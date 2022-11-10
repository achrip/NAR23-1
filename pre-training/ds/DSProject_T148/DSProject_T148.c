#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

// generally used variables
int choose;

// TODO create a linked list for users, shows
// TODO hash
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

void lookup() {
    FILE *users = fopen("./users/users.txt", "r"); 

    while (!feof(users)) { 
        fscanf(users, "");
    }

    fclose(users); 
}

void typeto(char *name, char *password, char *money, char *favourites) {
    FILE *data = fopen("./users/users.txt", "a"); 

    fscanf(data, "%s#%s#%s#%s\n", name, password, money, favourites); 

    fclose(data); 
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
    } while (check == false);
    
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
    int choose; 
    puts("filMZs"); 
    puts("Hi, %s", /*current user's name*/); 
    puts("Your money: %d", /*current user's money*/); 
    puts("Last Checked Time: \n"); // date/time function?????

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

}