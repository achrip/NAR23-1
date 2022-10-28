#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>


void newGame();
void loadGame();
void settings();
void manual();
void exit();

int main(){
    int choose; 
    initscr();
    raw();
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME\n");
    printf("3. SETTING\n");
    printf("4. HOW TO PLAY\n");
    printf("5. EXIT\n");
    printf(">> "); scanf ("%d", &choose);

    switch (choose){
        case 1: 
            newGame();
            break;
        case 2: 
            //loadGame();
            break;
        case 3: 
            settings();
            break;
        case 4: 
            manual();
            break;
        case 5: 
            //exit();
            break;
        default : 
            break;
    }

    return 0; 
    
}

void newGame(){
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
    // read enter then goto menu

}

void manual(){
    printf("Space Invader\n\n\n");

    printf("The object if the game is, basically, to shoot the invaders with your shooter\nwhile avoiding their shots and preventing an invasion Amassing a high scoree is a further\nobjective and one that must be prioritised against your continued survival.\n\n\n");
    printf("There is no time limit,\nexcept for the fact that if you do not shoot them all before they reach\nthe bottom of the screen the game ends.\n\n\n");
    printf("Credit : TinTin Winata\n\n");
    
    printf("Back to menu ? [press enter]");
    // read enter then goto menu
}