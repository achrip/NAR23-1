#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>


int choose; 

void login(); 
void regist(); 

int main() {
    puts("KRIJJPY KREME");
    puts("=============");
    puts("1. Login"); 
    puts("2. Register");
    puts("3. Exit");
    printf(">> ");
    scanf("%d", &choose); 
    getchar(); 

    switch (choose) {
        case 1: 
            login(); 
            break; 
        case 2: 
            regist(); 
            break; 
        case 3: 
            exit(0);
            break;
        default: 
            break; 
    }
}

struct Account {
    char email[255], pwd[255]; 

    struct Account *left, *right;
} *root = NULL; 

struct Doughnut {
    char name[25], description[45], size[10], code[10];
    int price; 

    struct Doughnut *left, *right; 
} *rootDN = NULL; 

struct Account *initAcc(char *email, char *pwd) {
    struct Account *init = (struct Account *)malloc(sizeof(struct Account));

    strcmp(init->email, email); 
    strcmp(init->pwd, pwd);

    return init;
} 

struct Doughnut *initDn(char *name, char *description, 
        char *size, int price, char *code) {
    struct Doughnut *init = (struct Doughnut *)malloc(sizeof(struct Doughnut)); 

    strcmp(init->name, name); 
    strcmp(init->description, description);
    strcmp(init->size, size);
    init->price = price; 
    strcmp(init->code, code);

    return init;
}

struct Account *insert(struct Account *root, char *email, char *pwd) {
    if (!root) {
        return initAcc(email, pwd); 
    } else if (root->email > email) {
        root->left = insert(root->left, email, pwd); 
    } else if (root->email < email) {
        root->right = insert(root->right, email, pwd);
    }
}

struct Doughnut *insertDN(struct Doughnut *rootDN, char *name,
        char *description, char *size, char *code, int price) {
    if (!rootDN) {
        return initDN(name, description, size, code, price); 
    } else if (rootDN->code > code) {
        rootDN->left = insertDN(rootDN->left,name, description, size, code, price); 
    } else if (rootDN->code < code) {
        rootDN->right = insertDN(rootDN->right, name, description, size, code, price);
    }
}

struct Account *searchUser(struct Account *root, char *email, char *pwd) {
    if (!root) {
        return root; 
    } else if (strcmp(email, root->email) != 0) {
        searchUser(root->left, email, pwd); 
        searchUser(root->right, email, pwd); 
    } else {
        if (strcmp(pwd, root->email) != 0) return NULL; 
        else return root;
    }
}

struct Account *searchMail(struct Account *root, char *email) {
    if (!root) return root; 
    else if (strcmp(email, root->email) != 0) {
        searchMail(root->left, email); 
        searchMail(root->right, email); 
    } else {
        return root;
    }
}
void lookup(char *filename, char rwxy) {
    FILE *data = fopen(filename, rwxy);

    char mail[255], pwd[255];

    while (!feof(data)) {
        fscanf(data, "%[^;];%s\n", mail, pwd);
        insert(root, mail, pwd);
    }

    fclose(data);

}

void write(char *filename, char rwxy, char *mail, char *pwd) {
    FILE *data = fopen(filename, rwxy);

    fprintf(data, "%s;%s\n", mail, pwd);

    fclose(data); 
}

void login() {
    char mail[255], pwd[255], c;
    char substr[30] = "@email.com";
    int index = 0; 

    lookup("./account.txt", "r");
    puts("Login you account here!");
    puts("=======================");
    puts("Type 0 for back");
    printf("Email: "); 
    while ((c = getche()) != 13) {
        if(c == 8){
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;

            continue;
        }
        mail[index++] = c;
        putch(c);
    }
    mail[index] = '\0';
    if (strlen(mail) == 2 && mail[0] == 0) return; 

    printf("Password: ");
    scanf("%s", pwd);
    getchar(); 
    
    //TODO validasi dengan existing data
    struct Account *find = searchUser(root, mail, pwd);
    if (!find) {
        puts("\33[0:31m\\]User was not found\33[0m\\]");
        printf("Press [enter] to continue...");
        getchar(); 
    } else {
        if (strstr(mail, "admin") == 0) admPage();
        else custPage();

        return;
    }

}
  
void regist() {
    char mail[255], pwd[255], c;
    char substr[30] = "@email.com";
    int index = 0; 

    lookup("./account.txt", "r");
    puts("Register you account here!");
    puts("=======================");
    puts("Type 0 for back");
    printf("Email [ends with '@email.com' & unique]: "); 
      // validasi end with email.com
      while ((c = getche()) != 13) {
        if(c == 8){
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;

            continue;
        }
        mail[index++] = c;
        putch(c);
    }
    mail[index] = '\0';
    if (strlen(mail) == 2 && mail[0] == 0) return; 
    else {
        bool endsWith = false;
        if (strlen(substr) <= strlen(mail)) {
            for (int i = 0; i < strlen(substr); i++) {
                if (mail[i + strlen(mail) - strlen(substr)] != substr[i]) {
                    endsWith = false;
                    break;
                }
                endsWith = true;
            }
        }
        
        if (!endsWith) {
            puts("\33[0:31m\\]Email must end with '@email.com'!\33[0m\\]");

        }
    }

    struct Account *find = searchMail(root, mail); 
    if (find) {
        puts("\33[0:31m\\]Email was already taken\33[0m\\]");
    } 

    printf("Password [5 - 10 characters & alphanumeric]: ");
    scanf("%s", pwd);
    getchar();

    if (!(strlen(pwd) > 4 && strlen(pwd) < 11)){
        puts("\33[0:31m\\]Password must 5 - 10 characters\33[0m\\]");
    } else {
        int count = 0; 
        for (int i = 0; i < strlen(pwd); i++){
            if (isalnum(pwd[i]) == 0) count++;
        }

        if (count != strlen(pwd)) {
            puts("\33[0:31m\\]Password must be alphanumeric (ex: aaa123 ; Aaa123)!\33[0m\\]");
        }
    }

    write("./accounts.txt", "a", mail, pwd);
    return; 

}

void admHome() {
    puts("Menu Admin");
    puts("==========");
    puts("1. Add doughnut");
    puts("2. Remove Doughnut");
    puts("3. Logout");
    printf(">> ");
    int choose;
    scanf("%d", &choose);
    getchar(); 

    switch (choose) {
        case 1: 
            addDonat(); 
            break; 
        case 2: 
            rmrf(); 
            break; 
        case 3: return; 
        default :
            break; 
    }
}