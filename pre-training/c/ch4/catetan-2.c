#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    // r --> read
    // w --> write 
    // a --> append
    // r+ --> read + write
    FILE *fp = fopen("test.txt", "r"); 

    char c[100]; 

    // method 1 of reading a file 
    while (fscanf(fp, "%[^\n]\n", c) != -1){     // -1 marks the end of file. could be replaced with 'EOF'
        printf("%s\n", c); 
    }

    // method 2 of reading a file
    while (!feof(fp)){
        fscanf(fp, "[^\n]\n", c); 
        printf("%s\n", c);
    }
    
    fp = fopen("test.txt", "w"); 

    while (true){
        scanf("%[^\n]", &c);
        getchar();

        if (strcmp(c, "exit") == 0){
            break; 
        }
        fprintf(fp, "%s\n", c);
    }

    fclose(fp); 
    return 0;
}