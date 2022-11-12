#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

#define char_size 256
#define hash_size 5381

int choose; 
struct tm *current_time; 
struct User {
    char password[255]; 
    int money; 
    int endofString; 
    User *child[char_size];
} *user_root = NULL; 

struct Film { 
    char title[255], description[255], uploader[255]; 
    int duration, price; 
    int endofString; 
    Film *child[char_size];
} *film_root = NULL; 

struct Faves {
    char user[255], title[255]; 
    Faves *next; 
} *fave_table[hash_size]; 

struct Genre {
    char title[255], category[255]; 
    Genre *next; 
} *genre_table[hash_size];

User *newUser() {
    User *node = (User *)calloc(1, sizeof(User));
    node->endofString = 0; 

    return node; 
}

User *trie_user(User *root, char *name, char *password, int money) {
    User *current = root; 
    while (*name) {
        if (!current->child[*name]) 
            current->child[*name] = newUser(); 
        current = current->child[*name]; 
        name++; 
    }
    strcpy(current->password, password); 
    current->money = money; 
    current->endofString = 1; 
}

Film *newFilm() {
    Film *node = (Film *)calloc(1, sizeof(Film)); 
    node->endofString = 0; 

    return node; 
}

Film *trie_film(Film *root, char *title) {
    Film *current = root; 
    while (*title){ 
        if (!current->child[*title])
            current->child[*title] = newFilm(); 
        current = current->child[*title];
        title++;
    }
    current->endofString = 1; 
}

Genre *create_genre(char *title, char *category) {
    Genre *node = (Genre *)malloc(sizeof(Genre)); 
    strcpy(node->category, category);
    strcpy(node->title, title); 
    node->next = NULL; 

    return node; 
}

Faves *create_fave(char *user, char *title) {
    Faves *node = (Faves *)malloc(sizeof(Faves)); 
    strcpy(node->user, user); 
    strcpy(node->title, title); 
    node->next = NULL; 

    return node; 
}

int hash (char *str) {
    unsigned int hashValue = hash_size; 
    int c; 
    while (c = *str++){
        hashValue = ((hashValue << 5) + hashValue) ^ c; 
    }
    return hashValue % hash_size;
}

void chain_fave(Faves *inserted) {
    int index = hash(inserted->user);

    if (!fave_table[index]) fave_table[index] = inserted; 
    else {
        Faves *current = fave_table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = inserted; 
    }
}

void chain_genre(Genre *inserted) {
    int index = hash(inserted->title); 

    if (!genre_table[index]) genre_table[index] = inserted;
    else { 
        Genre *current = genre_table[index]; 
        while (current->next) {
            current = current->next; 
        }
        current->next = inserted; 
    }
}

void login(); 
void signup(); 
void home(char *str, int i); 

int main() { 
    user_root = newUser();
    while (true) {
        FILE *dataUser = fopen("./users/users.txt", "r"); 
        char name[255], pwd[255], fav[255]; 
        int money; 
        while (!feof(dataUser)) {
            fscanf(dataUser, "\n%[^#]#%[^#]#%d#%[^\n]", name, pwd, &money, fav);
            trie_user(user_root, name, pwd, money);
            char *split = strtok(fav, ","); 
            while (split) {
                chain_fave(create_fave(name, split)); 
                split = strtok(NULL, ","); 
            }
        }
        fclose(dataUser); 

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
            signup(); 
            break; 
        case 3: 
            exit(0); 
            break; 
        default:
            break;
        } 
    }
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


User *search_user(User *root, char *name) {
    if (!root) 
        return NULL;
    
    User *current = root; 
    for (int i = 0; name[i] != '\0'; i++) {
        if (!current->child[name[i]])
            return NULL; 
        current = current->child[name[i]]; 
    }
    if (current->endofString = 1 && current != NULL) 
        return current; 
    return NULL;
}

Film *search_title(Film *root, char *title) {
    if (!root) 
        return NULL;
    
    Film *current = root; 
    for (int i = 0; title[i] != '\0'; i++) {
        if (!current->child[title[i]])
            return NULL; 
        current = current->child[title[i]]; 
    }
    if (current->endofString = 1 && current != NULL) 
        return current; 
    return NULL;
}

void login() {
    char user[255], pwd[255], c;
    int index = 0;  


    system("cls | @cls"); 
    puts("Login"); 
    printf(">> name >> "); 
    scanf("%[^\n]", user); 
    getchar(); 

    printf(">> password >> "); 
    while ((c = getch()) != 13) {
        if (index < 0) 
            index == 0;        
        if (c == 8) {
            putch('\b');
            putch(' '); 
            putch('\b');
            index--; 
            continue;
        }
        pwd[index++] = c; 
        putch('*'); 
    }
    pwd[index] = '\0'; 

    User *temp = search_user(user_root, user) ;
    if (!temp){
        puts("\nlogin failed"); 
        printf("press any key to continue..."); 
        getch(); 
    }
    if (!strcmp(temp->password, pwd)) {
        puts("\nlogin successful");
        printf("press any key to continue..."); 
        getch(); 
        home(user, temp->money);
    } else {
        puts("\nlogin failed"); 
        printf("press any key to continue..."); 
        getch(); 
    }


    return; 
}

void signup() {

    char user[255], pwd[255], c; 
    int index = 0; 
    bool check = false; 

    system("cls | @cls"); 
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

        User *curr = search_user(user_root, user); 
        if (curr) {
            puts("\nname already taken!"); 
            check = false; 
        } else check = true;
    } while (!check);
    puts(""); 
    
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
            pwd[index++] = c;
            putch('*');
        }
        pwd[index] = '\0'; 
        
        if (strlen(pwd) < 8) {
            puts("\npassword must be at least 8 characters"); 
            continue; 
        } else if (strlen(pwd) > 30) {
            puts("\npassword must not be more than 30 characters"); 
            continue; 
        } else {
            check = true; 
        } 
    } while (!check);

    FILE *userData = fopen("./users/users.txt", "a"); 
    fprintf(userData, "\n%s#%s#%d#%s", user, pwd, 300, "-"); 
    fclose(userData); 

    puts("Register Success"); 
    printf("press any key to continue...");
    getch();    

    return; 
}

void home(char *name, int money) {
    time_t t; 
    time (&t); 
    current_time = localtime(&t);
    int choose; 

    while (true) {
        system("cls");
        puts("filMZs"); 
        printf("Hi, %s\n", name); 
        printf("Your money: %d\n", money); 
        printf("Last Checked Time: %s\n", asctime(current_time)); // date/time function?????

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
                findMovie();   
                break; 
            case 2: 
                break; 
            case 3: 
                break; 
            case 4: 
                break; 
            default: 
                break;            
        }

    }
}

void findMovie() {
    
}