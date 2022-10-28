#include <stdio.h>

void main(){
    int a, b, c; 

    scanf("%d", &a);
    getchar();

    b=2*a;
    c=3*a;

    for (int i=0; i<b; ++i){
        printf("_");
    }
    for (int i=0; i<a; ++i){
        printf(" ");
        for (int j=a; j>=i; --j){
            printf("/\n");
        }
    }
}