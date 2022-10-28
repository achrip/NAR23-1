#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
// #include <ncurses.h>
// #include <pdcurses/curses.h>


// void gotoxy();
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
    //     printf("1. NEW GAME\n");
    //     printf("2. LOAD GAME\n");
    //     printf("3. SETTING\n");
    //     printf("4. HOW TO PLAY\n");
    //     printf("5. EXIT\n");
    //     printf(">> "); 
    //     scanf ("%d", &choose);

    //     switch (choose){
    //         case 1: 
    //             newGame();
    //             break;
    //         case 2: 
    //             //loadGame();
    //             break;
    //         case 3: 
    //             settings();
    //             break;
    //         case 4: 
    //             manual();
    //             break;
    //         case 5: 
    //             logout();
    //             break;
    //         default : 
    //             break;
        
    //     }
    } while (TRUE);

    return 0; 
    
}

// void gotoxy(int x, int y)
// {
//     COORD c = { x, y };  
//     SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
// }

int menuSelect(int i){
    // char choose;
    for (int i=0; i<5; i++){
        for (int j=0; j<20; j++){
            printf("%c", menu[i][j]); 
        }
        puts("");
    }
    char choose = getch();

    // while (TRUE){
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
                
                break;
         }

    return i; 

    // }




}

void newGame(){
    system("cls");
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
    printf("Welcome to the game!\n\n");

    printf("Basic Movement\n");
    printf("'w' - Move Up\n");
    printf("'a' - Move Left\n");
    printf("'s' - Move Down\n");
    printf("'d' - Move Right\n\n");

    printf("Lobby Arena\n");
    printf("'SPACE' - Intersect\n");
    printf("'y' - Talk\n");
    printf("'o' - Open Backpack\n\n");

    printf("Game Arena\n");
    printf("'SPACE' - Shoot\n");
    printf("'r' - Reload\n");
    printf("'f' - Skill \n");
    printf("'1' - Use Potion\n");
    printf("'2' - Use Max Potion\n");
    printf("'3' - Use Energy\n");
    printf("'4' - Use Max Energy\n");
    printf("'g' - Use Bomb\n\n");

    printf("Back to menu ? [press enter]");
    getch();
    // read enter then goto menu

}

void manual(){
    system("cls");
    printf("Space Invader\n\n\n");

    printf("The object if the game is, basically, to shoot the invaders with your shooter\nwhile avoiding their shots and preventing an invasion Amassing a high scoree is a further\nobjective and one that must be prioritised against your continued survival.\n\n\n");
    printf("There is no time limit,\nexcept for the fact that if you do not shoot them all before they reach\nthe bottom of the screen the game ends.\n\n\n");
    printf("Credit : TinTin Winata\n\n");
    
    printf("Back to menu ? [press enter]");
    getch();
    // read enter then goto menu
}

void logout(){
    system("cls");
    FILE *asset = fopen("./assets/logo.txt", "r");

    char c;

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