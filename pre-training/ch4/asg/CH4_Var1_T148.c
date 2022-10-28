#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct telephoneBook{
    char name[100];
    char phoneNum[20];
    char addr[100];
};


void add(); 
void search(); 
// void edit(); 
// void exit();

struct telephoneBook telebook;


int main(){
    int menu; 
    while (menu != 4){
    system("clear");
    printf("1. Add telephone book\n");
    printf("2. Search telephone book\n");
    printf("3. View telephone book\n");
    printf("4. Exit\n");
    printf(">> ");
    scanf("%d", &menu);
    getchar(); 


    switch (menu){
        case 1: 
            system("clear");
            add(); 
            break; 
        case 2: 
            system("clear");
            //search(); 
            break; 
        case 3: 
            system("clear");
            // view(); 
            break; 
        case 4: 
            system("clear");
            // exit(); 
            break; 
    }
    }
}


void add(){
    FILE *fp = fopen("file.txt", "a");
    printf("--Add telephone book--\n\n");

    x:
        printf("Please Input Name [Must be more than 3 characters long]: ");
        scanf("%[^\n]", telebook.name);
        getchar();

    if (strlen(telebook.name) < 3){
        printf("Name must be at least 3 characters long!\n\n");
        goto x;
    }

    y: 
        printf("Please Input Phone Number [10..12 charactes long, must start with '0', must be a number]: ");
        scanf("%s", telebook.phoneNum);
        getchar(); 

        
        if (telebook.phoneNum[0] !='0'){
                printf("Phone number must start with '0'\n\n");
                goto y; 
        } 
        
        for (int i=0; i<strlen(telebook.phoneNum); i++){
            if (telebook.phoneNum[i] >='a' && telebook.phoneNum[i]<='z'){
                    printf("Phone number must consists of only numbers\n\n");
                    goto y; 
            }
        }

        if (strlen(telebook.phoneNum) < 10 || strlen(telebook.phoneNum) > 12){
                printf("Phone number must be 10 to 12 characters long\n\n");
                goto y; 
        }
    z: 
        printf("Please Input Address [Must end with street]: ");
        scanf("%[^\n]", telebook.addr);
        getchar();

        if (!(strstr(telebook.addr, "street"))){
            printf("Address must end with 'street'\n\n");
            goto z;
        }

/*
        int low = 0, high = strlen(telebook.addr) - 1;
       bif: 
        while (high >= 1){
            int mid = low + (high-low)/2;

            if (telebook.addr[mid] < 's'){
                   low = mid + 1; 
            } else if (telebook.addr[mid] == 's'){
                if (telebook.addr[mid+5] == 't'){
                    break;
                } else{
                    goto bif;
                }
            } else {
                high = mid - 1;
            } 
            }
*/

    fprintf(fp, "%s#%s#%s\n", telebook.name, telebook.phoneNum, telebook.addr);

    fclose(fp);    
    printf("Phone data added successfully!\n");
    printf("Press enter to continue...");
    scanf("%*c");


}

void view(){
    FILE *fp = fopen("file.txt", "r");
    fscanf(fp, "%[^#]#%s#%s\n", telebook.name, telebook.phoneNum, telebook.addr);


    
}