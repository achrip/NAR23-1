#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4

struct Node {
    char name[50]; 
    int price;
    struct Node *next; // used for chaining
} *table[SIZE];

struct Node *createNode (char *name, int price) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->name, name); 
    newNode->price = price; 
    newNode->next = NULL; 

    return newNode; 
}

/* Hash Function */
int hash(char *name) {
    int hashkey = 0; 
    for (int i = 0; i < strlen(name); i++) {
        hashkey += name[i]; 
    }

    return hashkey % SIZE; 
}

/* Linear Probing */
void insert(struct Node *toInsert) {
    // decide which index toInsert will point to 
    int index = hash(toInsert->name); 

    //apppend to said index
        /* check the availability of the index */
        if (!table[index]) table[index] = toInsert;     // translates as "while table[index] == NULL"

        else {
            int baseIndex = index;
            while (table[index]) {              // this translates as "while table[index] != NULL"
                index = (index - 1) % SIZE;     // helps to loop to the first (0-th) index
                if (index == baseIndex) break;  //stops looping if there are no available index at all
            }

            /* at this point, we've known there is an empty index or not */
            if (index == baseIndex) puts("Table is FULL"); 
            else if (!table[index]) table[index] = toInsert;    
        }
}

/* Chaining */
void chaining(struct Node *toInsert) { 
     // decide which index toInsert will point to 
    int index = hash(toInsert->name); 

    //apppend to said index
        /* check the availability of the index */
        if (!table[index]) table[index] = toInsert;     // translates as "while table[index] == NULL"

        else{
            struct Node *cursor = table[index];
            while (cursor->next) {          // if the pointer to isn't null, we'll keep iterating
                cursor = cursor->next ; 
            }

            /* at this point we've found the list pointing to a NULL */
            cursor->next = toInsert; 
        }
}

void erase(char *name) {
    /* find the index of the certain data using hash function */
    int index = hash(name); 

    /* delete said data */
        /*check whether said data is the head or not*/
        if (table[index] && strcmp(name, table[index]->name) == 0) {
            /* save the old head*/
            struct Node *toDelete = table[index]; 

            /* assign the next pointed data as the new head*/
            table[index] = table[index]->next; 

            /*delete the old head*/
            free(toDelete);
        } else {
            /* loop through the linked list from the head*/
            struct Node *cursor = table[index]; 
            struct Node *prev = cursor; 
            while (cursor) { 
                if (strcmp(cursor->name, name) == 0) {
                    prev->next = cursor->next; 
                    free(cursor); 
                } else {
                    prev = cursor; 
                    cursor = cursor->next;
                }
            }
        }
}
void view() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d.", i); 
        if (!table[i]) printf("EMPTY");
        else {
            struct Node *cursor = table[i];     //start from the head
            while (cursor){
                printf("[%s, %d]", cursor->name, cursor->price); 
                if (cursor->next) printf(" -> ");       // just to give an arrow for visual's sake
                cursor = cursor->next;
            }
        }
        puts("");
    }
}

int main() {

    chaining(createNode("abc", 123));
    chaining(createNode("ghi", 456));
    // view(); 
    chaining(createNode("cba", 243));
    view(); 

    return 0; 
}