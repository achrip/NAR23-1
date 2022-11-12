#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

#define char_size 256
#define hash_size 5381


// generally used variables
int choose;
struct Favourites{
    char title[255]; 
    Favourites *next; 
} *favTable[hash_size];
struct Genre {
    char string[255]; 
    Genre *next; 
} *genreTable[hash_size]; 
struct User {
    char password[255]; 
    int money, isLeaf, hashIndex; 
    User *child[char_size];
}; 

struct Movie {
    char c, description[255], uploader[255]; 
    int price, duration, isLeaf, hashIndex;  
    Movie *child[char_size]; 
}; 
/*below are functions related to database*/
void lookup(char *filename, char rwxy); 
void typeto(char *name, char *password, char *money, char *favourites); 
/*below are functions related to start menu*/
void login(User *root); 
void signUp(User *root); 
void seeYa(); 
/*below are functions related to home menu*/
void home(); 
void find(); 
void transmit(); 
void receive(); 
void faves(); 

User *newUser() {
    User *init = (User *)malloc(sizeof(User)); 

    for (int i = 0; i < char_size; i++) {
        init->child[i] = NULL; 
    }

    // init->c = data;
    init->isLeaf = 0; 
    strcpy(init->password, ""); 
    init->money = 0; 

    return init; 
}

int main() {
    // TODO clear linked list here (if any)
    // TODO populate user linked list / trie here
    // Landing Page
    User *root = newUser();
    system("cls | @cls"); 
    puts("filMZ"); 
    puts("1. login");
    puts("2. register"); 
    puts("3. exit"); 
    printf(">> "); 
    scanf("%d", &choose);
    getchar(); 

    switch (choose)
    {
    case 1:
        login(root); 
        break;
    case 2: 
        signUp(root); 
        break; 
    case 3: 
        exit(0); 
        break; 
    default:
        break;
    } 
}

/*********************************************************************************

                         THIS IS THE TRIE AREA 

**********************************************************************************/

/*********************************************************************************

                         THIS IS THE LINKED LIST AREA 

**********************************************************************************/

// TODO create a linked list for users, show
Favourites *newFave(char *title) {
    Favourites *init = (Favourites *)malloc(sizeof(Favourites)); 

    strcpy(init->title, title); 
    init->next = NULL ; 

    return init; 
}

Genre *newGenre(char *category) { 
    Genre *init = (Genre *)malloc(sizeof(Genre)); 

    strcpy(init->string, category); 
    init->next = NULL; 

    return init; 
}


Movie *newMov(char data) {
    Movie *init = (Movie *)malloc(sizeof(Movie)); 

    for (int i = 0; i < char_size; i++) {
        init->child[i] = NULL; 
    }
    init->c = data; 
    strcpy(init->description, ""); 
    strcpy(init->uploader, ""); 
    init->duration = 0; 
    init->price = 0; 
    init->isLeaf = 0; 

    return init; 
}

User *insertUser(User *root, char *str, char *pwd, int money, int index) {
    if (!root)
        root = newUser(); 
    User *curr = root;
    int i; 
    for (i = 0; str[i] != '\0'; i++); {
        int idx = str[i]; 
        if (curr->child[idx] == NULL) {
            curr->child[idx] = newUser();
        } 

        curr = curr->child[idx]; 
    }
    curr->hashIndex = index; 
    strcpy(curr->password, pwd); 
    curr->money = money; 
    curr->isLeaf = 1;

    return curr; 
}

Movie *insertMov(Movie *head, char *title, char *desc, 
    char *uploader, int price, int duration, int index) {
    Movie *curr = head;
    int i ;
    
    for (i = 0; title[i] != '\0'; i++) {
        int idx = (int) title[i]; 
        if (curr->child[idx] == NULL) {
            curr->child[idx] = newMov(title[i]); 
        }
        
        curr = curr->child[idx];  
    }
    
    curr->hashIndex = index; 
    curr->price = price; 
    curr->duration = duration;
    strcpy(curr->description, desc); 
    strcpy(curr->uploader, uploader); 
    curr->isLeaf = 1;

    return curr; 
}

void chainingGenre(Genre *inserted, int hashIndex) {
    int index = hashIndex; 

        if (!genreTable[index]) genreTable[index] = inserted; 
        else {
            Genre *curr = genreTable[index]; 
            while (curr->next) {
                curr = curr->next; 
            }
            curr->next = inserted; 
        }
}

void chainingFave(Favourites *inserted, int hashIndex) {
    int index = hashIndex; 

    if (!favTable[index]) favTable[index] = inserted; 
    else {
        Favourites *curr = favTable[index]; 
        while (curr->next) {
            curr = curr->next; 
        }
        curr->next = inserted; 
    }
}

unsigned int hash(char *str) {
    unsigned int hash = hash_size;
    int c; 

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /* hash = (hash * 33) + c*/
    }

    return hash % hash_size; 
}

void lookupBorrow() {
    FILE *data = fopen("./borrow/borrows.txt", "r"); 
    char title[255], rentee[255]; 
    int dur, timestamp;
    while (!feof(data)) {
        fscanf(data, "%[^#]#%[^#]#%[^#]#%d\n", title, rentee, timestamp, dur);
    }

    fclose(data);
}

void lookupMov(Movie *root) {
    FILE *data = fopen("./films/films.txt", "r"); 

    char title[255], desc[255], genre[255], uploader[255]; 
    int price, dur; 
    while (!feof(data)) { 
        fscanf(data, "%[^#]#%[^#]#%d#%d#%s#[^\n]\n", title, desc, price, dur, genre, uploader); 
        
        int index = hash(title); 
        char *ptc = strtok(genre, ","); 
        while (ptc != NULL) {
            chainingGenre(newGenre(ptc), index);
            ptc = strtok(NULL, ",");
        }
        
        insertMov(root, title, desc, uploader, price, dur, index); //disini masuk hashIndex
    }

    fclose(data);
}

void lookupUser(User *root) {
    FILE *data = fopen("./users/users.txt", "r"); 
    char name[255], pwd[255], faves[255]; 
    int money; 
    while (!feof(data)) {
        fscanf (data, "\n%[^#]#%[^#]#%d#%[^\n]", name, pwd, &money, faves);

        int index = hash(name); 
        char *ptc = strtok(faves, ",");    
        // while (ptc != NULL) {
        //     chainingFave(newFave(ptc), index);
        //     ptc = strtok(NULL, ",");
        // }
        insertUser(root, name, pwd, money, index);
    }
}

User *searchUser(User *root, char *name) {
    User *curr = root; 

    for (int i = 0; name[i] != '\0'; i++) {
        int index = name[i]; 
        if (curr->child[index] == NULL) return NULL; 
        curr = curr->child[index]; 
    }
    if (curr != NULL && curr->isLeaf == 1) return curr; 
    return NULL; 
}

void print_Trie(User *root) {
    if (!root) {
        puts("NO DATA"); 
        return; 
    }
    User *node = root; 
    printf("%s -> ", node->password); 
    for (int i = 0; i < char_size; i++) {
        print_Trie(node->child[i]); 
    }
}

/*********************************************************************************

                         THIS IS THE START PAGE AREA 

**********************************************************************************/
void login(User *root) {
    char user[255], password[255], c; 
    int index = 0; 
    lookupUser(root); 
    print_Trie(root);

    puts("Login");
    printf(">> name >> "); 
    scanf("%[^\n]", &user); 
    printf(">> password >> "); 
    while ((c = getch()) != 13) {
        if(index < 0)
           index = 0;
        if(c == 8){
            putch('\b');
            putch(' ');
            putch('\b');
            index--;

            continue;
        }
        password[index++] = c;
        putch('*');
   }
   password[index] = '\0';
    
    User *curr = searchUser(root, user);
    if (!curr) {
        puts("\nlogin failed"); 
        printf("press any key to continue..."); 
        getch(); 

        return; 
    } else { 

        if (!strcmp(password, curr->password)) {
            puts("\nlogin success"); 
            printf("press any key to continue..."); 
            getch(); 

            return; 
        } else puts("you are here"); 
    }
    
}

void signUp(User *root) {
    char user[255], password[255], c; 
    int index = 0; 
    bool check = false; 
    lookupUser(root);
    print_Trie(root);  
    
    puts("Register"); 
    do {
        printf(">> name >> "); 
        while ((c = getch()) != 13) {
            if(index < 0)
                index = 0;
            if(c == 8){
                putch('\b');
                putch(' ');
                putch('\b');
                index--;

                continue;
            }
            if (c == 95 || c == 32){// underscore dan spasi 
                goto here; 
            }
            if (isalnum(c) == 0){
                continue; 
            }
            here :  user[index++] = c;
                    putch(c);
        }
        user[index] = '\0'; 

        if (strlen(user) < 8) {
            puts("\nname must be at least 8 characters"); 
            continue; 
        } else if (strlen(user) > 30) {
            puts("\nname must not be more than 30 characters"); 
            continue; 
        } else {
            check = true; 
        }

        User *curr = searchUser(root, user); 
        if (curr) {
            puts("\nname already taken!"); 
            check = false; 
        } else check = true;
    } while (!check);
    puts(" "); 
    
    check = false; 
    do {
        printf(">> password >> "); 
        while ((c = getch()) != 13) {
            if(index < 0)
                index = 0;
            if(c == 8){
                putch('\b');
                putch(' ');
                putch('\b');
                index--;

                continue;
            }
            password[index++] = c;
            putch('*');
        }
        password[index] = '\0'; 
        
        if (strlen(password) < 8) {
            puts("\npassword must be at least 8 characters"); 
            continue; 
        } else if (strlen(password) > 30) {
            puts("\npassword must not be more than 30 characters"); 
            continue; 
        } else {
            check = true; 
        } 
    } while (!check);

    //TODO concat info here 
    // typeto(user, password, 300, "-");

        puts("Register Success"); 
        printf("press any key to continue...");
        getch();

    return; 
}


/*********************************************************************************

                         THIS IS THE HOME PAGE AREA 

**********************************************************************************/

// void home() {
//     time_t t = time(NULL); 
//     int choose; 
//     puts("filMZs"); 
//     puts("Hi, %s", /*current user's name*/); 
//     puts("Your money: %d", /*current user's money*/); 
//     puts("Last Checked Time: %s\n", ctime(&t)); // date/time function?????

//     puts("Menus"); 
//     puts("1. Search film"); 
//     puts("2. Upload film"); 
//     puts("3. Return film"); 
//     puts("4. Favorited film"); 
//     puts("0. Logout"); 
    
//     printf(">> "); 
//     scanf("%d", &choose); 
//     getchar(); 

//     switch (choose) {
//         case 0: 
//             return; 
//             break; 
//         case 1:    
//             find(); 
//             break; 
//         case 2: 
//             transmit(); 
//             break; 
//         case 3: 
//             retrieve(); 
//             break; 
//         case 4: 
//             faves(); 
//             break; 
//         default: 
//             break;            
//     }

// }

// void find() {
//     Trie *head = createnode(); 

//     int number = 1;
//     lookup("./films/films.txt", "r");   

//     puts(">> search >> ");
//     puts("Results:"); 

    

// }