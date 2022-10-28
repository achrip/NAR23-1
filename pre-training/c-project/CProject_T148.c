#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
// #include <ncurses.h>
// #include <pdcurses/curses.h>


void gotoxy();
int menuSelect();
void newGame();
void loadGame();
void settings();
void manual();
void logout();

char menu[5][20]={
    {"NEW GAME           <"},
    {"LOAD GAME           "}, 
    {"SETTINGS            "}, 
    {"HOW TO PLAY         "}, 
    {"EXIT                "}, 
};

int main(){
    int choose; 
    int i=0; 


    do {
        system("cls");
        i = menuSelect(i);
    } while (TRUE);

    return 0; 
    
}

void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

int menuSelect(int i){
    // char choose;
    for (int i=0; i<5; i++){
        gotoxy(5,i+2);
        for (int j=0; j<20; j++){
            printf("%c", menu[i][j]); 
        }
        puts("");
        
    }
    char choose = getch();

    switch (choose){
    case 'w':
        menu[i][19] = ' ';
        i--;
        if (i<0) i=0; 
        menu[i][19] = '<';
        break;

    case 's':
        menu[i][19] = ' '; 
        i++;
        if (i>4) i=4; 
        menu[i][19] = '<';
        break;

    case '\r':
        switch (i){
            case 0: 
                newGame();
                break;
            case 1: 
                //loadGame();
                break;
            case 2: 
                settings();
                break;
            case 3: 
                manual();
                break;
            case 4: 
                logout();
                break;
            default : 
                break;
        }

        break;
    }

    return i; 
}

void newGame(){
    system("cls");
    gotoxy(5,2);
    char uname [10001];

    printf("Select Your New Name: ");
    do {
        scanf("%s", uname);
        getchar(); 
    } while (strlen(uname) < 3);

    // add filepointer to crosscheck database with input
}

void loadGame(){
    // show player data by format num. [uname] [Level : n]
}

void settings(){
    system("cls");
    gotoxy(5,2);
    printf("Welcome to the game!\n\n");

    gotoxy(5,4);
    printf("Basic Movement\n");
    gotoxy(5,5);
    printf("'w' - Move Up\n");
    gotoxy(5,6);
    printf("'a' - Move Left\n");
    gotoxy(5,7);
    printf("'s' - Move Down\n");
    gotoxy(5,8);
    printf("'d' - Move Right\n\n");

    gotoxy(5,10);
    printf("Lobby Arena\n");
    gotoxy(5,11);
    printf("'SPACE' - Intersect\n");
    gotoxy(5,12);
    printf("'y' - Talk\n");
    gotoxy(5,13);
    printf("'o' - Open Backpack\n\n");

    gotoxy(5,15);
    printf("Game Arena\n");
    gotoxy(5,16);
    printf("'SPACE' - Shoot\n");
    gotoxy(5,17);
    printf("'r' - Reload\n");
    gotoxy(5,18);
    printf("'f' - Skill \n");
    gotoxy(5,19);
    printf("'1' - Use Potion\n");
    gotoxy(5,20);
    printf("'2' - Use Max Potion\n");
    gotoxy(5,21);
    printf("'3' - Use Energy\n");
    gotoxy(5,22);
    printf("'4' - Use Max Energy\n");
    gotoxy(5,23);
    printf("'g' - Use Bomb\n\n");

    gotoxy(5,25);
    printf("Back to menu ? [press enter]");
    getch();
    // read enter then goto menu

}

void manual(){
    system("cls");
    gotoxy(5,2); 
    printf("Space Invader\n\n\n");

    gotoxy(5,5); 
    printf("The object if the game is, basically, to shoot the invaders with your shooter\n");
    gotoxy(5,6); 
    printf("while avoiding their shots and preventing an invasion Amassing a high scoree is a further\n");
    gotoxy(5,7); 
    printf("objective and one that must be prioritised against your continued survival.\n\n\n");
    gotoxy(5,10); 
    printf("There is no time limit,\n");
    gotoxy(5,11); 
    printf("except for the fact that if you do not shoot them all before they reach\n");
    gotoxy(5,12); 
    printf("the bottom of the screen the game ends.\n\n\n");
    gotoxy(5,15); 
    printf("Credit : TinTin Winata\n\n");
    
    gotoxy(5,17); 
    printf("Back to menu ? [press enter]");
    getch();
    // read enter then goto menu
}

void logout(){
    system("cls");
    FILE *asset = fopen("./assets/logo.txt", "r");

    char c;
    gotoxy(5,1);
    while(!feof(asset)){
        c = getc(asset);
        printf("%c", c);
        Sleep(0.9);
    };
    puts("");
    puts("");

    char message[]={"Alongside courage and perseverance, we shape and define our future.\nJT 22-1."};

    for (int i=0; i<strlen(message); i++){
        printf("%c", message[i]);
        Sleep(1.2);
    }

    fclose(asset);

    getch();
    exit(0);
}