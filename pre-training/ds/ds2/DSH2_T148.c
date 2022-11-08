//
// Created by shrimp on 8/11/2022.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Drama{
    char title[255];
    char maleLead[255];
    char femaleLead[255];
    double ratings;
    int releaseDate;
    struct Drama *next;
    struct Drama *prev;
} *head = NULL, *tail = NULL;

struct Drama *initDrama (char *title, char *maleLead, char *femaleLead, double rating, int releaseDate) {
    struct Drama *newDrama = (struct Drama *)malloc(sizeof(struct Drama *));

    strcpy(newDrama->title, title);
    strcpy(newDrama->maleLead, maleLead);
    strcpy(newDrama->femaleLead, femaleLead);
    newDrama->ratings = rating;
    newDrama->releaseDate = releaseDate;

    newDrama->next = NULL;
    newDrama->prev = NULL;

    return newDrama;
}

void pushHead(char *title, char *maleLead, char *femaleLead, double rating, int releaseDate) {
    struct Drama *newDrama = initDrama(title, maleLead, femaleLead, rating, releaseDate);

    if (head == NULL) head = tail = newDrama;
    else {
        head->prev = newDrama;
        newDrama->next = head;
        head = newDrama;
    }
}

void pushTail (char *title, char *maleLead, char *femaleLead, double rating, int releaseDate) {
    struct Drama *newDrama = initDrama(title, maleLead, femaleLead, rating, releaseDate);

    if (head == NULL) head = tail = newDrama;
    else {
        tail->next = newDrama;
        newDrama->prev = tail;
        tail = newDrama;
    }
}

void pushMid(char *title, char *maleLead, char *femaleLead, double rating, int releaseDate) {
    struct Drama *newDrama = initDrama(title, maleLead, femaleLead, rating, releaseDate);

    if (head == NULL) head = tail = newDrama;
    else if (head->ratings < newDrama->ratings) pushHead(title, maleLead, femaleLead, rating, releaseDate);
    else if (tail->ratings > newDrama->ratings) pushTail(title, maleLead, femaleLead, rating, releaseDate);
    else {
        struct Drama *curr = head;
        while (curr->ratings > newDrama->ratings){
            curr = curr->next;
        }
        curr->next = newDrama;
        newDrama->prev = curr;
        newDrama->next = curr->next->next;
        curr->next->prev = newDrama;
    }

}


int choose;

void startPage();
void login();
void regist();
void bye();

void homePage(char *user);
void addDrama();
void updateDrama();
void deleteDrama();
void listDrama();

int main(){
    startPage();
}

void startPage(){
    printf("MyDramaList\n");
    printf("===========\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    printf(">> ");
    scanf("%d", &choose);
    getchar();

    switch (choose) {
        case 1:
            login();
            break;
        case 2:
            regist();
            break;
        case 3:
            bye();
            break;
        default:
            break;
    }
}

void login(){
    char uname[255][255], pwd[255][255];
    char tempUname[255], temPwd[255];
    FILE *userData =  fopen("./user.txt", "r");

    int index = 0;
    while (!feof(userData)){
        fscanf(userData, "%s#%s\n", uname[index], pwd[index]);
        index++;
    }
    fclose(userData);

    printf("Enter your username (enter 0 to return): ");
    scanf("%s", tempUname);
    if (strlen(tempUname) == 1 && strcmp(tempUname, "0") == 0) return;

    printf("Enter your password (enter 0 to return): ");
    scanf("%s", temPwd);
    if (strlen(tempUname) == 1 && strcmp(tempUname, "0") == 0) return;


    for (int i = 0; i < strlen(*uname); i++) {
        if (tempUname == uname[i] && temPwd == pwd[i]){
            homePage(tempUname);
            return;
        }
    }

    printf("Wrong credentials\n");
    printf("Press enter to continue...");
    getchar();
    return;
}

void homePage(char *user){
    puts("MyDramaList");
    puts("===========");
    puts("1. Add drama");
    puts("2. Update drama");
    puts("3. Delete drama");
    puts("4. Drama list");
    puts("5. Logout");
    printf(">> ");
    scanf("%d", &choose);
    getchar();

    switch (choose) {
        case 1:
            if (strcmp(user, "admin") == 0){
                addDrama();
                break;
            } else {
                puts("You do not have access to this feature");
                printf("Press enter to continue...");
                getchar();
                break;
            }
        case 2 :
            if (strcmp(user, "admin") == 0){
                updateDrama();
                break;
            } else {
                puts("You do not have access to this feature");
                printf("Press enter to continue...");
                getchar();
                break;
            }

        case 3:
            if (strcmp(user, "admin") == 0){
                deleteDrama();
                break;
            } else {
                puts("You do not have access to this feature");
                printf("Press enter to continue...");
                getchar();
                break;
            }
        case 4:
            if (strcmp(user, "admin") == 0){
                listDrama();
                break;
            } else {
                //watchlist
                getchar();
                break;
            }
        case 5:
            return;
        default:
            break;
    }
}

void addDrama(){
    char title[255], ml[255], fml[255];
    double rating;
    int release;

    do {
        printf("Enter drama title (4-20 characters, 0 to cancel): ");
        scanf("%[^\n]", title);
        getchar();

        if (strlen(title) < 4 || strlen(title) > 20){
            puts("Title length can't be less than 4 characters or greater than 20 characters!");
        } else if (strlen(title) == 1 && strcmp(title, "0") == 0) return;
        else break;
    } while (strlen(title) < 4 || strlen(title) > 20);

    do {
        printf("Enter drama male lead (6-12 characters, 0 to cancel): ");
        scanf("%[^\n]", ml);
        getchar();

        if (strlen(ml) < 6 || strlen(ml) > 12){
            puts("Male lead length can't be less than 6 characters or greater than 12 characters!");
        }else if (strlen(ml) == 1 && strcmp(ml, "0") == 0) return;
    } while (strlen(ml) < 6 || strlen(ml) > 12);

    do {
        printf("Enter drama female lead (6-12 characters, 0 to cancel): ");
        scanf("%[^\n]", ml);
        getchar();

        if (strlen(fml) < 6 || strlen(fml) > 12){
            puts("Female lead length can't be less than 6 characters or greater than 12 characters!");
        }else if (strlen(fml) == 1 && strcmp(fml, "0") == 0) return;
    } while (strlen(fml) < 6 || strlen(fml) > 12);

    do {
        printf("Enter drama rating (2.5 - 5.0, 0 to cancel): ");
        scanf("%lf", &rating);
        getchar();

        if (rating < 2.5 || rating > 5.0){
            puts("Drama rating have to be greater than or equals to 2.5 or less than or equals to 5.0");
        } else if (rating == 0) return;
    } while (rating < 2.5 || rating > 5.0);

    do{
        printf("Enter drama release data (2012 - 2022, 0 to cancel): ");
        scanf("%d", &release);
        getchar();

        if (release < 2012 || release > 2022) {
            puts("Drama release date has to be greater than or equals to 2012 and less than or equals to 2022");
        } else if (release == 0) return;
    } while (release < 2012 || release > 2022);

    FILE *dramas = fopen("./drama.txt", "a");

    fprintf(dramas, "%s#%s#%s#%lf#%d", title, ml, fml, rating, release);

    fclose(dramas);
}

void updateDrama(){
    char title[255], ml[255], fml[255];
    double rating;
    int release;
    FILE *dramas = fopen("./drama.txt", "r");

    int index = 0;
    while (!feof(dramas)){
        fscanf(dramas, "%[^#]#%[^#]#%[^#]#%lf#%d", title, ml, fml, &rating, &release);
        pushMid(title, ml, fml, rating, release);
        index++;
    }
    fclose(dramas);

    if (head == NULL) {
        puts("No drama information available");
        printf("Press enter to continue");
        getchar();
    } else {
        struct Drama *curr = head;
        for (int i = 0; i <= index; i++){
            printf("| %d | %-33s| %-21s| %-21s| %-7.1lf| %-15d|", (i + 1),
                   curr->title, curr->maleLead, curr->femaleLead, curr->ratings, curr->releaseDate);
            curr = curr->next;
        }
        puts("");
       do {
           printf("Enter drama index (1 - %d, 0 to return): ", index);
           scanf("%d", &choose);

           if (choose < 1 || choose > index){
               puts("Drama index can't be 0 or greater than the greatest index!");
           } else if (choose == 0) return;
       } while (choose < 1 || choose > index);

        do {
            printf("Enter drama title (4-20 characters, 0 to cancel): ");
            scanf("%[^\n]", title);
            getchar();

            if (strlen(title) < 4 || strlen(title) > 20){
                puts("Title length can't be less than 4 characters or greater than 20 characters!");
            } else if (strlen(title) == 1 && strcmp(title, "0") == 0) return;
            else break;
        } while (strlen(title) < 4 || strlen(title) > 20);

        do {
            printf("Enter drama male lead (6-12 characters, 0 to cancel): ");
            scanf("%[^\n]", ml);
            getchar();

            if (strlen(ml) < 6 || strlen(ml) > 12){
                puts("Male lead length can't be less than 6 characters or greater than 12 characters!");
            }else if (strlen(ml) == 1 && strcmp(ml, "0") == 0) return;
        } while (strlen(ml) < 6 || strlen(ml) > 12);

        do {
            printf("Enter drama female lead (6-12 characters, 0 to cancel): ");
            scanf("%[^\n]", ml);
            getchar();

            if (strlen(fml) < 6 || strlen(fml) > 12){
                puts("Female lead length can't be less than 6 characters or greater than 12 characters!");
            }else if (strlen(fml) == 1 && strcmp(fml, "0") == 0) return;
        } while (strlen(fml) < 6 || strlen(fml) > 12);

        do {
            printf("Enter drama rating (2.5 - 5.0, 0 to cancel): ");
            scanf("%lf", &rating);
            getchar();

            if (rating < 2.5 || rating > 5.0){
                puts("Drama rating have to be greater than or equals to 2.5 or less than or equals to 5.0");
            } else if (rating == 0) return;
        } while (rating < 2.5 || rating > 5.0);

        do{
            printf("Enter drama release data (2012 - 2022, 0 to cancel): ");
            scanf("%d", &release);
            getchar();

            if (release < 2012 || release > 2022) {
                puts("Drama release date has to be greater than or equals to 2012 and less than or equals to 2022");
            } else if (release == 0) return;
        } while (release < 2012 || release > 2022);



    }
}
