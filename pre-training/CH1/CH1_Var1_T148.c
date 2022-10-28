#include <stdio.h>

int main(){
    int rep, start_point, x, y, z; 

    scanf("%d", &rep); 
    getchar(); 

    for (int i=0; i<rep; ++i){
        scanf("%d %d %d %d", &start_point, &x, &y, &z); 
        getchar(); 

        if (start_point<x || start_point>=y || start_point%z!=0){ 
            printf("Not Eligible\n");
        } else { 
            printf("Eligible\n"); 
        }
    }

    return 0; 
}