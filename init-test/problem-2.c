#include <stdio.h>

void main(){
    int leng, letCount=0; 
    char str[100]; 

    scanf("%d", &leng);
    getchar();

    scanf("%s", str);
    getchar();

    for (int i=0; i<leng; ++i){
        for (int j=0; j<leng; ++j){
            if (str[i]==str[j]){
                letCount++;
            }
        }
    }
    // printf("%d", letCount);

    int tmp = letCount%4;

    // printf("tmep %d", tmp);
    if (tmp!=0){
        letCount=letCount/4+1;
        printf("%d\n", letCount);
    } else{
        printf("%d\n", letCount/4);
    }
    

}