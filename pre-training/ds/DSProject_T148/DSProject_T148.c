#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

// generally used variables
int choose;

/*below are functions related to database*/
void lookup(); 
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

struct Trie {
    int isLeaf; 
    struct Trie *character[26];
} *root = NULL;

typedef struct Trie Trie; 

Trie *createnode () {
    Trie *init = (Trie *)malloc(sizeof(Trie)); 
    init->isLeaf = 0; 
    
    for (int i = 0; i < 26; i++) {
        init->character[i] = NULL;
    }

    return init; 
}

void insert (Trie *head, char *str) {
    Trie *curr = head; 
    while (*str) {
        if (curr->character[*str - 'a'] == NULL) {
            curr->character[*str - 'a'] = createnode(); 
        }

        curr = curr->character[*str - 'a']; 

        str++; 
    }

    curr->isLeaf = 1; 
}

int search(Trie *head, char *str) {
    if (head == NULL) {
        return 0; 
    }
    
    Trie *curr = head; 
    while (*str) {
        curr = curr->character[*str - 'a']; 

        if (curr == NULL) {
            return 0; 
        } 

        str++; 
    }

    return curr->isLeaf; 
}

int hasChildren(Trie *curr) {
    for (int i = 0; i < 26; i++){
        if (curr->character[i]) {
            return 1; 
        }
    }

    return 0; 
}

// Recursive function to delete a string from a Trie
int deletion(struct Trie **curr, char* str)
{
    // return 0 if Trie is empty
    if (*curr == NULL) {
        return 0;
    }
 
    // if the end of the string is not reached
    if (*str)
    {
        // recur for the node corresponding to the next character in
        // the string and if it returns 1, delete the current node
        // (if it is non-leaf)
        if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
            deletion(&((*curr)->character[*str - 'a']), str + 1) &&
            (*curr)->isLeaf == 0)
        {
            if (!hasChildren(*curr))
            {
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else {
                return 0;
            }
        }
    }
 
    // if the end of the string is reached
    if (*str == '\0' && (*curr)->isLeaf)
    {
        // if the current node is a leaf node and doesn't have any children
        if (!hasChildren(*curr))
        {
            free(*curr);    // delete the current node
            (*curr) = NULL;
            return 1;       // delete the non-leaf parent nodes
        }
 
        // if the current node is a leaf node and has children
        else {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            (*curr)->isLeaf = 0;
            return 0;       // don't delete its parent nodes
        }
    }
 
    return 0;
}

/*********************************************************************************

                         THIS IS THE LINKED LIST AREA 

**********************************************************************************/

// TODO create a linked list for users, shows
struct User {
    char name[255], password[255], favourites[255]; 
    int money; 


} *root = NULL; 

struct Movie {
    char title[255], description[255], genre[255], uploader[255]; 
    int price, duration;  

} *root = NULL; 

struct Borrow {
    char title[255], rentee[255]; 
    int timeStamp; 
    int rentDuration; 
} *root = NULL; 

struct Movie *newMovie(char *title, char *desc, int price, 
        int dur, char *genre, char *up) {
    struct Movie *init = (struct Movie *)malloc(sizeof(struct Movie)) ; 

    strcpy(init->title, title); 
    strcpy(init->description, desc); 
    strcpy(init->genre, genre); 
    strcpy(init->uploader, up); 
    init->price = price; 
    init->duration = dur; 

    return init; 
}

void lookup(char *filename, char rwxy) {
        FILE *data = fopen(filename, rwxy); 

    if (strcmp(filename, "users") == 0) {
        char name[255], pwd[255], faves[255]; 
        int money; 
        while (!feof(data)) {
            fscanf (data, "%[^#]#%[^#]#%d#%[^\n]\n", name, pwd, money, faves);
        }
    }
    if (strcmp(filename, "films") == 0) {
        char title[255], desc[255], genre[255]; 
        int price, dur; 
        while (!feof(data)) { 
            fscanf(data, "%[^#]#%[^#]#%d#%d#%s\n", title, desc, price, dur, genre); 

            newMovie(title, desc, price, dur, genre); 
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
        hash = ((hash << 5) + hash) ^ c; 
    }

    return hash; 
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
        scanf("%[^\n]", &user);
        getchar(); 

        if (strlen(user) < 8) {
            puts("name must be at least 8 characters"); 
            continue; 
        } else if (strlen(user) > 30) {
            puts("name must not be more than 30 characters"); 
            continue; 
        } else if (/* name exists */) {
            puts("name already taken!"); 
            continue; 
        } else {
            check = true; 
        }
    } while (!check);
    
    do {
        printf(">> password >> "); 
        while ((c = getch()) != "\n") {
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
            puts("password must be at least 8 characters"); 
            continue; 
        } else if (strlen(password) > 30) {
            puts("password must not be more than 30 characters"); 
            continue; 
        } else {
            check = true; 
        } 
    } while (!check);

    //TODO concat info here 
    typeto(user, password, 300, "-");

    puts("Register Success"); 
    printf("press any key to continue...");
    getch();

    return; 
}


/*********************************************************************************

                         THIS IS THE HOME PAGE AREA 

**********************************************************************************/

void home() {
    time_t t = time(NULL); 
    int choose; 
    puts("filMZs"); 
    puts("Hi, %s", /*current user's name*/); 
    puts("Your money: %d", /*current user's money*/); 
    puts("Last Checked Time: %s\n", ctime(&t)); // date/time function?????

    puts("Menus"); 
    puts("1. Search film"); 
    puts("2. Upload film"); 
    puts("3. Return film"); 
    puts("4. Favorited film"); 
    puts("0. Logout"); 
    
    printf(">> "); 
    scanf("%d", &choose); 
    getchar(); 

    switch (choose) {
        case 0: 
            return; 
            break; 
        case 1:    
            find(); 
            break; 
        case 2: 
            transmit(); 
            break; 
        case 3: 
            retrieve(); 
            break; 
        case 4: 
            faves(); 
            break; 
        default: 
            break;            
    }

}

void find() {
    struct Movies *curr = root; 
    int number = 1;
    lookup("./films/films.txt", "r");   

    puts(">> search >> ");
    puts("Results:"); 

    

}