#include <stdio.h>

void main(){
    int menu, count=0;
    char email[100];
    printf("Foda Wallet\n");
    printf("============\n");
    printf("1. Buy E-Wallet\n");
    printf("2. Back To Main Menu\n");
    printf(">>");
    scanf("%d", menu); 
    getchar();

    switch (menu)
    {
    case 1:
        do{
        printf("Input Your Email : ");
        scanf("%s", email);
        getchar(); 

        if (email[0]=="@"){
            printf("Email Cannot Start With @ character");
            count =0; 
        } else{
            for (int i=0; i<100; ++i){
                if (email[i]="@"){
                    count++; 
                }
                if (count>1||count==0){
                    printf("Email Must Consist of One @");
                }
            }
        }
        } while (count>1||count==0);

        
        break;
    case 2:
        break; 
    default:
        break;
    }
}