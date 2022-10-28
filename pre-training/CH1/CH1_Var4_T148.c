#include <stdio.h>
#include <string.h>

int main(){
    int uinput, count=0; 
    char arr[10];

    scanf("%d", &uinput); 
    getchar(); 

    for (int i=0; i<uinput; ++i){
        arr[i] = i%10;

        for (int j=0; j<strlen(arr); ++j){
            if (arr[j]==1 || arr[j]==3 || arr[j]==6){
                count++;
            }
        }

        for (int j=0; j<strlen(arr); ++j){
            arr[j]=0; 
        }

    }

    printf("%d\n", count); 

    return 0;
}