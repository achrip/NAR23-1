#include <stdio.h>

int main (){
    int side, temp; 

    scanf("%d", &side); 
    getchar(); 

    temp = (side-3)/2;

    for (int i=side; i>0; --i){
        for (int j=0; j<i; ++j){
            printf("*"); 
        }
        for (int j=i; j<side; ++j){
            printf(" ");
        }
        for (int j=i; j<side; ++j){
            printf(" ");
        }
        for (int j=0; j<i; ++j){
            printf("*"); 
        }
        printf("\n");
    }
    
    for (int i=1; i<side; ++i){
        for (int j=0; j<=i; ++j){
            printf("*"); 
        }
        for (int j=side-1; j>i; --j){
            printf(" "); 
        }
        for (int j=side-1; j>i; --j){
            printf(" "); 
        }
        for (int j=0; j<=i; ++j){
            printf("*"); 
        }
        printf("\n");
    }
    // for (int i=0; i<side; ++i){ 
    //     printf("*");
    //     for (int j=temp; j>0; --j){
    //         printf(" ");
    //     }
    //     printf("*");

    //     for (int j=temp; j>0; --j){
    //         printf(" ");
    //     }
    //     printf("*");
        
    //     printf("\n");
    //     --temp; 
    // }
    return 0;
}