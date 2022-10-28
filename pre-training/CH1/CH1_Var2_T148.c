#include <stdio.h> 

int main(){
    int rep, kids, chocs; 

    scanf("%d", &rep); 
    getchar(); 

    for (int i=0; i<rep; ++i){
        scanf("%d %d", &chocs, &kids); 
        getchar(); 

        if (chocs<=kids){ 
            int needed = kids-chocs+1;
            printf("%d\n", needed); 
        } else{ 
            printf("0\n");
        }
        
    }   

    return 0;
}