#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char name[255]; 
    int age;
    struct Node *left, *right;
} *root = NULL;

struct Node *initNode(char *name, int age) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->name, name); 
    newNode->age = age; 
    newNode->left = NULL; 
    newNode->right = NULL;

    return newNode;
}
struct Node *insert(struct Node *root, char *name, int age) {
    if (!root) {
        return initNode(name, age); 
    } else if (root->age > age) {
        root->left = insert(root->left, name, age); 
    } else if (root->age < age) {
        root->right = insert(root->right, name, age);
    }
}

void inOrder(struct Node *root) {
    if (!root) {
        return; 
    } else {
        inOrder(root->left); 
        printf("%s %d\n", root->name, root->age);
        inOrder(root->right); 
    }
}

void preOrder(struct Node *root) {
    if (!root) {
        return; 
    } else {
        preOrder(root->left); 
        preOrder(root->right); 
        printf("%s %d\n", root->name, root->age);
    }
}

void postOrder(struct Node *root) {
    if (!root) {
        return; 
    } else {
        printf("%s %d\n", root->name, root->age);
        postOrder(root->left); 
        postOrder(root->right); 
    }
}

void deleteByAge(struct Node *root, int age) {
    if (!root) {
        return; 
    } else if (root->age > age) {
        deleteByAge(root->left, age); 
    } else if (root->age < age) {
        deleteByAge(root->right, age);
    } else {
        if (!root->left && !root->right) {
            return NULL; 
        } else if (!root->left) {
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } else if (!root->right) {
            struct Node *temp = root->left; 
            free(root); 
            return temp;
        } else {
        /*predecessor*/
            // struct Node *temp = root->left; 
            // while (temp->right) {
            //     temp = temp->right;
            // }

            // strcpy(root->name, temp->name); 
            // root->age = temp->age; 

            // deleteByAge(root->left, root->age);
            // return root; 
            
            struct Node *temp = root->right; 
            while (temp->left) {
                temp = temp->left;
            }

            strcpy(root->name, temp->name); 
            root->age = temp->age; 

            deleteByAge(root->right, root->age);
            return root; 

        }
    }
}

struct Node *searchByAge(struct Node *root, int age) {
    if (!root || root->age == age) {
        return root; 
    } else if (root->age > age) {
        searchByAge(root->left, age);
    }else if (root->age < age) {
        searchByAge(root->right, age); 
    }
}

int main() {

    root = insert(root, "Felix", 20); 
    root = insert(root, "Andi", 35); 
    root = insert(root, "Bobi", 30); 
    root = insert(root, "Cecep", 25); 
    root = insert(root, "Asep", 12); 
    root = insert(root, "Yus", 29); 
    root = insert(root, "Sam", 8);
    inOrder(root);
    preOrder(root);
    postOrder(root);

    struct Node *find = searchByAge(root, 20); 

    if (!find) {
        puts("404 not found");
    } else {
        printf("%s %d\n", find->name, find->age);
    }

    return 0; 
}