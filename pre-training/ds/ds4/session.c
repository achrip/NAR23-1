#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[255]; 
    int age;
    struct Node *left, *right;
} *root;

struct Node *initNode(char *name, int age, struct Node *left, struct Node *right) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    strcpy(new->name, name); 
    new -> age = age; 
    new -> left = NULL; 
    new -> right = NULL;
}
int main() {


    return 0; 
}