#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

// generally used variables
int choose;

/*below are functions related to database*/
void lookup(char *filename, char rwxy); 
void typeto(char *name, char *password, char *money, char *favourites); 
/*below are functions related to start menu*/
void login(); 
void signUp(); 
void seeYa(); 
/*below are functions related to home menu*/
void home(); 
void find(); 
void transmit(); 
void receive(); 
void faves(); 

int main() {
    // TODO clear linked list here (if any)
    // TODO populate user linked list / trie here
    // Landing Page
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
        login(); 
        break;
    case 2: 
        signUp(); 
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

// TODO create a linked list for users, shows
typedef User User; 
typedef Movie Movie; 
typedef Favourites Favourites; 
struct Favourites{
    char title [255]; 
    Favourites *character[64]; 
    Favourites *next; 
} *head = NULL, *tail = NULL;
struct User {
    char c, password[255]; 
    int money, isLeaf; 
    Favourites *head;
    User *child[64];
}; 

struct Movie {
    char title[255], description[255], genre[255], uploader[255]; 
    int price, duration, isLeaf;  

    Movie *character[64]; 
}; 

User *newUser(char data) {
    User *init = (User *)malloc(sizeof(User)); 

    for (int i = 0; i < 64; i++)  
        init->name[i] = NULL; 

    for (int i = 0; i < 64; i++) {
        init->child[i] = NULL; 
    }

    init->isLeaf = 0; 
    init->password = NULL; 
    init->money = 0; 

    return init; 
}

Favourites *newFave(char *title) {
    Favourites *init = (Favourites *)malloc(sizeof(Favourites)); 

    strcpy(init->title, title); 
    init->next = NULL ; 

    return init; 
}

Movie *newMov(char *title, char *desc, char *genre, char *uploader, int dur, int price) {
    Movie *init = (Movie *)malloc(sizeof(Movie)); 

    strcpy(init->title, title); 
    strcpy(init->description, desc); 
    strcpy(init->genre, genre); 
    strcpy(init->uploader, uploader); 
    init->duration = dur; 
    init->price = price; 
    init->isLeaf = 0; 

    return init; 
}

User *getNewUserNode() {
    User *node = (User *)malloc(sizeof(User)); 
    node->isLeaf = 0; 

    for (int i = 0; i < 64; i++) {
        node->name[i] = NULL; 
    }

    return node; 
}  

User *insertMov(User *head, char *str) {
    User *curr = head;
    while (*str)
    {
        if (curr->name[*str - 'a'] == NULL) {
            curr->name[*str - 'a'] = getNewUserNode();
        }
 
        curr = curr->name[*str - 'a'];
 
        str++;
    }
 
    curr->isLeaf = 1;
}

Movie *getNewMovNode() {
    Movie *node = (Movie *)malloc(sizeof(Movie)); 
    node->isLeaf = 0; 

    for (int i = 0; i < 64; i++) {
        node->title[i] = NULL; 
    }

    return node; 
}

Movie *insertMov(Movie *head, char *str) {
    Movie *curr = head;
    while (*str)
    {
        if (curr->title[*str - 'a'] == NULL) {
            curr->title[*str - 'a'] = getNewMovNode();
        }
 
        curr = curr->title[*str - 'a'];
 
        str++;
    }
 
    curr->isLeaf = 1;
}

void pushHead (Favourites *root, char *str) {
    Favourites *node = newFave(str); 

    if (head == NULL) {
        head = tail = node; 
    } else {
        node->next = head; 
        head = node; 
    }
}


void lookup(char *filename, char rwxy) {
        FILE *data = fopen(filename, rwxy); 

    if (strcmp(filename, "users") == 0) {
        char name[255], pwd[255], faves[255]; 
        int money; 
        User *head = getNewUserNode(); 
        while (!feof(data)) {
            fscanf (data, "%[^#]#%[^#]#%d#%[^\n]\n", name, pwd, money, faves);

            

        }
    }
    if (strcmp(filename, "films") == 0) {
        char title[255], desc[255], genre[255], uploader[255]; 
        int price, dur; 
        Movie *head = getNewMovNode(); 
        while (!feof(data)) { 
            fscanf(data, "%[^#]#%[^#]#%d#%d#%s#[^\n]\n", title, desc, price, dur, genre, uploader); 

            newMov(title, desc, genre, uploader, dur, price); 
            insertMov(head, title); 
        }
    }
    if (strcmp(filename, "borrows") == 0) {
        char title[255], rentee[255]; 
        int dur, timestamp;
        while (!feof(data)) {
            fscanf(data, "%[^#]#%[^#]#%[^#]#%d\n", title, rentee, timestamp, dur);


        }
    }
}

unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c; 

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /* hash = (hash * 33) + c*/
    }

    return hash % 1; 
}



/*********************************************************************************

                         THIS IS THE START PAGE AREA 

**********************************************************************************/
void login() {
    char user[255], password[255], c; 
    int index = 0; 

    puts("Login");
    printf(">> name >> "); 
    scanf("%[^\n]", &user); 
    printf(">> password >> "); 
    while ((c = getch()) != 13) {
        if(index < 0)
           index = 0;
        if(c == 8){
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;

            continue;
        }
        password[index++] = c;
        putch('*');
   }
   password[index] = '\0';
    

    if (/*user and password == user and password in linked list*/) { 
        puts("login success"); 
        printf("press any key to continue..."); 
        getch(); 

        home();
        return;  
    } else {
        puts("login failed"); 
        printf("press any key to continue..."); 
        getch(); 

        return; 
    } 
}

void signUp() {
    char user[255], password[255], c; 
    int index = 0; 
    bool check = false; 
    
    puts("Register"); 
    do {
        printf(">> name >> "); 
        while ((c = getch()) != 13) {
            if(index < 0)
                index = 0;
            if(c == 8){
                putch('\b');
                putch(NULL);
                putch('\b');
                index--;

                continue;
            }
            if (c == 95 || c == 32){
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
                putch(NULL);
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