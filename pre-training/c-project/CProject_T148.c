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
void playerData(); 
void newGame();
void loadGame();
void settings();
void manual();
void logout();
void gameLobby();
void gamePlay();



char menu[5][20]={
    {"NEW GAME           <"},
    {"LOAD GAME           "}, 
    {"SETTINGS            "}, 
    {"HOW TO PLAY         "}, 
    {"EXIT                "}, 
};

struct player{
    char name[255]; 
    int money; 
    int exp; 
    int level; 
    int hp; 
    int energy; 
    int armor; 
    int damage; 
}allPlayer[100], currentPlayer;

int playerIndex;

int main(){
    int choose; 
    int i=0; 

    playerData(); 

    do {
        system("cls");
        i = menuSelect(i);
    } while (TRUE);

    return 0; 
    
}

void gotoxy(int x, int y){
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

int menuSelect(int i){
    for (int i=0; i<5; i++){
        gotoxy(5,i+2);
        for (int j=0; j<20; j++){
            printf("%c", menu[i][j]); 
        }
        puts("");
        
    }
    gotoxy(0,0);
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
                loadGame();
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

void playerData(){
    FILE *data = fopen("./database/player.dat", "r");

    playerIndex=0; 
    while(!feof(data)){
        fscanf(data, "%[^#]#%d#%d#%d#%d#%d#%d#%d\n", allPlayer[playerIndex].name, &allPlayer[playerIndex].money, &allPlayer[playerIndex].exp,
        &allPlayer[playerIndex].level, &allPlayer[playerIndex].hp, &allPlayer[playerIndex].energy, &allPlayer[playerIndex].armor, &allPlayer[playerIndex].damage);
        playerIndex++;
    };

    fclose(data);
}

void newGame(){
    do {
        system("cls");
        gotoxy(5,2);
        printf("Select Your New Name: ");
        scanf("%s", currentPlayer.name);
        getchar(); 
        getch();
        
        if (strlen(currentPlayer.name)<3){
            gotoxy(5,4);
            printf("Please insert more than 3 characters [press enter]");
            getch();
        }
    } while (strlen(currentPlayer.name) < 3);

    for (int i=0; i<playerIndex; i++){
        if ((strcmpi(currentPlayer.name, allPlayer[i].name))==0){
            gotoxy(5,4);
            printf("Sorry but name already exists! [press enter]");
            getch(); 
            return; 
        }
    }
    
    FILE *data = fopen ("./database/player.dat", "a"); 

        currentPlayer.money = 0; 
        currentPlayer.exp = 0;
        currentPlayer.level = 0;
        currentPlayer.hp = 100; 
        currentPlayer.energy = 50; 
        currentPlayer.armor = 1; 
        currentPlayer.damage = 1;

    fprintf(data, "%[^\n]#%d#%d#%d#%d#%d#%d#%d\n", currentPlayer.name, 
    currentPlayer.money, currentPlayer.exp, currentPlayer.level, currentPlayer.hp, 
    currentPlayer.energy, currentPlayer.armor, currentPlayer.damage);

    fclose(data);
    gameLobby();
}

void loadGame(){
    // show player data by format num. [currentPlayer.name] [Level : n]
    char cursorLoc[playerIndex][3];
    gotoxy(5,2);
    printf("Save Data : \n");
    for (int i=0; i<=playerIndex; i++){
        gotoxy(5, 3+i);
        if (i == playerIndex){
            printf("%d. Back", i+1);
        } else{
            printf("%d. %s [Level : %d]\n", i+1, allPlayer[i].name, allPlayer[i].level);

        }
        cursorLoc[i][1] = ' ';
    }       

    int posX=0; 
    int cursor = 0 ; 
    cursorLoc[0][1] = '<'; 
    while(TRUE){
        for (int i=0; i<=playerIndex; i++){
            gotoxy(30,3+i); 
            printf("%c", cursorLoc[i][1]);
        }

        cursor = getch();
        switch (cursor){
        case 'w':
            cursorLoc[posX][1] = ' ';
            posX--; 
            if (posX < 0) posX = 0; 
            cursorLoc[posX][1] = '<';
            break;
        
        case 's':
            cursorLoc[posX][1] = ' ';
            posX++; 
            if (posX > playerIndex) posX = playerIndex; 
            cursorLoc[posX][1] = '<';
            break;
        
        case '\r':
            if (posX == playerIndex) return; 
            else {
                currentPlayer.name == allPlayer[posX].name;
                currentPlayer.money == allPlayer[posX].money;
                currentPlayer.exp == allPlayer[posX].exp;
                currentPlayer.level == allPlayer[posX].level;
                currentPlayer.hp == allPlayer[posX].hp;
                currentPlayer.energy == allPlayer[posX].energy;
                currentPlayer.armor == allPlayer[posX].armor;
                currentPlayer.damage == allPlayer[posX].damage;

                gameLobby();
            }
            break; 
        }
    }
    gotoxy(0,0);
    getch();
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
    // gotoxy(5,1);
    while(!feof(asset)){
        c = getc(asset);
        printf("%c", c);
        Sleep(0.9);
    };
    puts("");
    puts("");

    char message[]={"\tAlongside courage and perseverance, we shape and define our future.\n\tJT 22-1."};

    for (int i=0; i<strlen(message); i++){
        printf("%c", message[i]);
        Sleep(1.5);
    }

    fclose(asset);

    getch();
    exit(0);
}

void gameLobby(){
    system("cls");
    FILE *lobbyMap = fopen("./assets/lobby.txt", "r"); 

    char s[1000][1000], action;
    int i=0, j=0; 
    int posX=20, posY=17, tmp;

    while (!feof(lobbyMap)){
        fscanf(lobbyMap, "%[^\n]\n", s[i]);
        i++; 
    }

    s[16][6] = 'U';
    s[16][27] = 'I';
    s[20][17] = 'P';

    while(TRUE){
        system("cls");
        for (int i=0; i<22; i++){
            gotoxy(5, i+1);
            printf("%s\n", s[i]); 

            // if (i==19) s[posX][posY] = 'P';
            if (currentPlayer.level < 10 ){
                s[6][6] = '-';
                s[6][7] = '-';
                s[6][8] = '-';
                s[6][9] = '-';
            }
        }

        char mv = getch(); 

        switch(mv){
            case 'a':
                tmp = posY;
                posY--;
                if (s[posX][posY]=='/' || s[posX][posY]=='#' || 
                s[posX][posY]=='-' || s[posX][posY]=='|' ||
                s[posX][posY]=='\\' || s[posX][posY]=='.' || s[posX][posY]=='_'){
                    posY++; 
                    s[posX][posY] = 'P';
                    break;
                } else if (s[posX][posY]=='I'){
                    posY++;  
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char itemShop[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(itemShop[i]); j++){
                                printf("%c", itemShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='U'){
                    posY++; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char upgradeShop[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(upgradeShop[i]); j++){
                                printf("%c", upgradeShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else{
                    s[posX][posY] = 'P';
                    s[posX][tmp] = ' ';
                }                
                break;

            case 'd':
                tmp = posY;
                posY++;
                if (s[posX][posY]=='/' || s[posX][posY]=='#' || 
                s[posX][posY]=='-' || s[posX][posY]=='|' ||
                s[posX][posY]=='\\' || s[posX][posY]=='.' || s[posX][posY]=='_'){
                    posY--; 
                    s[posX][posY] = 'P';
                    break;
                } else if (s[posX][posY]=='I'){
                    posY--; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char itemShop[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(itemShop[i]); j++){
                                printf("%c", itemShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='U'){
                    posY--; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char upgradeShop[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(upgradeShop[i]); j++){
                                printf("%c", upgradeShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else{
                    s[posX][posY] = 'P';
                    s[posX][tmp] = ' ';
                }
                break;

            case 'w':
                tmp = posX;
                posX--;
                if (s[posX][posY]=='/' || s[posX][posY]=='#' || 
                s[posX][posY]=='-' || s[posX][posY]=='|' ||
                s[posX][posY]=='\\' || s[posX][posY]=='.' || s[posX][posY]=='_'){
                    posX++; 
                    s[posX][posY] = 'P';
                    break;
                } else if (s[posX][posY]=='I'){
                    posX++; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char itemShop[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(itemShop[i]); j++){
                                printf("%c", itemShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='U'){
                    posX++; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char upgradeShop[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(upgradeShop[i]); j++){
                                printf("%c", upgradeShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else if(posX == 9 && posY == 17){
                    gotoxy(40,15); 
                    printf("Press SPACE to interact");
                     action = getch(); 

                    if (action == ' ') gamePlay();
                } else{
                    s[posX][posY] = 'P';
                    s[tmp][posY] = ' ';
                }
                break;

            case 's':
                tmp = posX;
                posX++;
                if (s[posX][posY]=='/' || s[posX][posY]=='#' || 
                s[posX][posY]=='-' || s[posX][posY]=='|' ||
                s[posX][posY]=='\\' || s[posX][posY]=='.' || s[posX][posY]=='_'){
                    posX--; 
                    s[posX][posY] = 'P';
                    break;
                } else if (s[posX][posY]=='I'){
                    posX--; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char itemShop[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(itemShop[i]); j++){
                                printf("%c", itemShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='='){
                    posX--; 
                    s[posX][posY] = 'P';
                    gotoxy(45, 15);
                    printf("Press SPACE to exit");
                     action = getch();

                    if (action == ' ') return;  
                    if (action == 'w'){
                        posX--;
                        s[posX][posY] = 'P';
                        s[tmp][posY] = ' ';
                    }
                } else if (s[posX][posY]=='U'){
                    posX--; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char upgradeShop[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(upgradeShop[i]); j++){
                                printf("%c", upgradeShop[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y'); //goto shop
                        if (action == 'n') break;
                    }             

                } else{
                    s[posX][posY] = 'P';
                    s[tmp][posY] = ' ';
                }
                break;
        }

    }
}

void gamePlay(){
    getch();
}