#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// generally used variables
int choose;

// TODO create a linked list for users, shows
void login(); 
void signUp(); 
void seeYa(); 

int main() {
    // TODO clear linked list here (if any)
    // TODO populate user linked list / trie here
    // Landing Page
    puts("filMZ"); 
    puts("1. login");
    puts("2. register"); 
    puts("3. exit"); 
    printf(">> "); 
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        login(); 
        break;
    case 2: 
        signUp(); 
        break; 
    case 3: 
        seeYa(); 
        break; 
    default:
        break;
    } 
}

void login() {
    char user[255], password[255]; 
    FILE *users = fopen("./users/users.txt", "r"); 

    while (!feof(users)) { 
        fscanf(users, "");
    }

    fclose(users); 

    puts("Login");
    printf(">> name >> "); 
    scanf("%[^\n]", &user); 
    printf(">> password >> "); 
    scanf("%s", &password); 

    if (/*user and password == user and password in linked list*/) home(); 
    else return; 
}

void signUp() {
    char user[255], password[255]; 
    
    puts("Register"); 
    do {
        printf(">> name >> "); 
        scanf("%[^\n]", &user);

        if (strlen(user) < 8) {
            puts("name must be at least 8 characters"); 
            continue; 
        } else if (strlen(user) > 30) {
            puts("name must not be more than 30 characters"); 
            continue; 
        } else if (/* name exists */) {
            puts("name already taken!"); 
            continue; 
        } 
    } while (strlen(user) < 8 || strlen(user) > 30 || 
        check == false)
}