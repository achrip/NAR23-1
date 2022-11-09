#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 9999

int choose; 
struct Member {
    char name[255];
    int age; 
    int weight; 
    char gender; 
    char code[10];

    struct Member *next; 
} *table[SIZE];

struct Member *initMember(char *name, int age, int weight, char gender, char *code) {
    struct Member *new = (struct Member *)malloc(sizeof(struct Member)); 

    strcpy(new->name, name);
    new->age = age; 
    new->weight = weight; 
    new->gender = gender; 
    strcpy(new->code, code); 
    new-> next = NULL;

    return new;
}

int hash (char *code) {
    int hashkey = 0; 
    for (int i = 0; i < strlen(code); i++) {
        hashkey += code[i];
    }

    return hashkey % SIZE;
}

void insert(struct Member *inserts) {
    int index = hash(inserts->name);

    if (!table[index]) table[index] = inserts; 
    else {
        struct Member *curr = table[index];
        while (curr->next) {
            curr = curr->next;
        }

        curr-> next = inserts;
    }
}
void login(); 
void view();
void erase(); 
void seeYa();

int main() {
    puts("1. insert memebership");
    puts("2. view membership");
    puts("3. delete membership");
    puts("4. exit");
    printf(">> ");
    scanf("%d", &choose);
    getchar(); 


    switch (choose) { 
        case 1: 
            login(); 
            break; 
        case 2:
            view(); 
            break; 
        case 3: 
            // erase(); 
            break; 
        case 4: 
            // seeYa(); 
            break;
        
    }
}   

void login() {
    char name[255], gender[10];
    int age, weight; 

    while (true) {
        printf("Input new member name [>= 2 characters]: ");
        scanf("%[^\n]", name); 
        getchar(); 

        if (!(strlen(name) < 2)) break; 

    };

    while (true)  {
        printf("Input new member age [>=10 years old]: ");
        scanf("%d", &age);
        getchar(); 


        if (!(age < 10)) break; 
    };

    while (true)  {
        printf("Input new member weight [>= 30 kilograms]: ");
        scanf("%d", &weight);
        getchar(); 


        if (!(weight < 30)) break;
    };

    while (true)  { 
        printf("Input new member gender [male or female][case insensitive]: "); 
        scanf("%s", gender);
        getchar(); 


        if (strcmpi(gender, "male") == 0 || strcmpi(gender,"female") == 0) break; 
    };

    puts(""); 



    // member code
    char code[100];
    int numcode = (rand() % 100) + 1;
    char tenn[5];  
    itoa (numcode, tenn, 10 );
    strcat(code, tenn);
    for (int i = 0, n = 0; i < strlen(name); i++) {
        if (i == 0) {
            char c = toupper(name[0]);
            strncat(code, &c, 1);

        } else {
            if (name[i] == ' ') {
                char c = toupper(name[i+1]);
                strncat(code, &c, 1);
            } 
        }
    }

    if (strcmpi(gender, "male")){
        strcat(code, "F");
    } else strcat(code, "M"); 

    int lastcode = (age * weight) / 4; 
    itoa(lastcode, tenn, 10); 
    strcat(code, tenn);


    // lempar ke struct
    insert(initMember(name, age, weight, gender, code));
    printf("success create new gym membership [name: %s, code: %s]\n", name, code);
    printf("Press enter to continue...");
    getchar();

    return;
}

void view() { 
    int count = 0; 
    for (int i = 0; i <= SIZE; i++){
        if (!table[i]) count++;
    }    

    if (count == SIZE){
        puts("gym membership is empty, consider to add one!");
        printf("press enter to continue...");
        getchar();
    } else {
        for (int i = 0; i < SIZE; i++) {
            if (!table[i]) continue; 
            else {
                struct Member *curr = table[i];
                while (curr) {
                    printf("| %-3d| %-30s| %-15d| %-15d| %-20s| %-33s|", i+1, 
                    curr->name, curr->age, curr->weight, curr->gender,
                    curr->code);
                }
                curr = curr->next; 
            }
        }
        puts("");
    }
}