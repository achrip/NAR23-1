#include <stdio.h>

void main (){
    int que, pos, time; 
    int floor[20];

    scanf("%d %d", &que, &pos);
    getchar();

    for (int i=0; i<que; ++i){
        scanf("%d", floor[i]);
        getchar();

        if (i==que){
            floor[i]=que;
        }
    }

    int batch=pos/5;

    for (int i=0; i<batch; ++i){
        if (batch==0){
            for (int j=0; j<5; ++j){
                if (floor[j]==que){
                    time += que;
                    break;
                }
                time += floor[j];
            }
            break; 
        }
        for (int j=0; j<batch; ++j){
            for (int k=0; k<5; ++k){
                if (floor[j]==que){
                    time += que;
                    break;
                }
            time += floor[j];
            }
        }
    }

    time *= 5;

    printf("%d\n", time);


}