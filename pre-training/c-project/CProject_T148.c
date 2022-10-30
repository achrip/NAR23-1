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
void itemShop(); 
void upgradeShop(); 
void leaderboard();


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
}allPlayer[100], currentPlayer, temp;

int playerIndex;

int main(){
    int choose; 
    int i=0; 


    do {
        playerData(); 
        system("cls");
        i = menuSelect(i);
    } while (TRUE);

    return 0; 
    
}
void textcolor(int color); 

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
    case 'W':
        menu[i][19] = ' ';
        i--;
        if (i<0) i=0; 
        menu[i][19] = '<';
        break;

    case 's':
    case 'S':
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

    for (int i=0; i<playerIndex; i++){
        for (int j=0; j<playerIndex-1-i; j++){
            if (allPlayer[j].level < allPlayer[j+1].level){
                strcpy(temp.name, allPlayer[j+1].name); 
                temp.money = allPlayer[j+1].money;
                temp.exp = allPlayer[j+1].exp;
                temp.level = allPlayer[j+1].level;
                temp.hp = allPlayer[j+1].hp;
                temp.energy = allPlayer[j+1].energy;
                temp.armor = allPlayer[j+1].armor;
                temp.damage = allPlayer[j+1].damage;

                strcpy(allPlayer[j+1].name, allPlayer[j].name);
                allPlayer[j+1].money = allPlayer[j].money;
                allPlayer[j+1].exp = allPlayer[j].exp;
                allPlayer[j+1].level = allPlayer[j].level;
                allPlayer[j+1].hp = allPlayer[j].hp;
                allPlayer[j+1].energy = allPlayer[j].energy;
                allPlayer[j+1].armor = allPlayer[j].armor;
                allPlayer[j+1].damage = allPlayer[j].damage;

                strcpy(allPlayer[j].name, temp.name);
                allPlayer[j].money = temp.money;
                allPlayer[j].exp = temp.exp;
                allPlayer[j].level = temp.level;
                allPlayer[j].hp = temp.hp;
                allPlayer[j].energy = temp.energy;
                allPlayer[j].armor = temp.armor;
                allPlayer[j].damage = temp.damage;

            }
        }
    }
}

void newGame(){
    do {
        system("cls");
        gotoxy(5,2);
        printf("Select Your New Name: ");
        scanf("%[^\n]", currentPlayer.name);
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

    fprintf(data, "%s#%d#%d#%d#%d#%d#%d#%d\n", currentPlayer.name, 
    currentPlayer.money, currentPlayer.exp, currentPlayer.level, currentPlayer.hp, 
    currentPlayer.energy, currentPlayer.armor, currentPlayer.damage);

    fclose(data);
    gameLobby();
}

void loadGame(){
    // show player data by format num. [currentPlayer.name] [Level : n]
    system("cls");
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

        gotoxy(0,0); 
        cursor = getch();
        switch (cursor){
        case 'w':
        case 'W':
            cursorLoc[posX][1] = ' ';
            posX--; 
            if (posX < 0) posX = 0; 
            cursorLoc[posX][1] = '<';
            break;
        
        case 's':
        case 'S':
            cursorLoc[posX][1] = ' ';
            posX++; 
            if (posX > playerIndex) posX = playerIndex; 
            cursorLoc[posX][1] = '<';
            break;
        
        case '\r':
            if (posX == playerIndex) return; 
            else {

                strcpy(currentPlayer.name, allPlayer[posX].name);
                currentPlayer.money = allPlayer[posX].money;
                currentPlayer.exp = allPlayer[posX].exp;
                currentPlayer.level = allPlayer[posX].level;
                currentPlayer.hp = allPlayer[posX].hp;
                currentPlayer.energy = allPlayer[posX].energy;
                currentPlayer.armor = allPlayer[posX].armor;
                currentPlayer.damage = allPlayer[posX].damage;

                gameLobby();
                return; 
            }
            break; 
        }
    }
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

        gotoxy(45,3);
        printf("\033[0;33m");
        printf("[%s]", currentPlayer.name);
        printf("\033[0m"); 
        gotoxy(45,4);
        printf("Level : %d", currentPlayer.level);
        gotoxy(45,5);
        printf("Money : %d", currentPlayer.money);

        gotoxy(0,22);
        char mv = getch(); 

        switch(mv){
            case 'a':
            case 'A':
                tmp = posY;
                posY--;
                if (s[posX][posY]=='/' || s[posX][posY]=='#' || 
                s[posX][posY]=='-' || s[posX][posY]=='\\' || 
                s[posX][posY]=='.' || s[posX][posY]=='_'){
                    posY++; 
                    s[posX][posY] = 'P';
                    break;
                } else if (s[posX][posY]=='|'){
                    posY++;  
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        leaderboard(); 
                    }
                    break;
                }else if (s[posX][posY]=='I'){
                    posY++;  
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char shopText[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') itemShop();
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='U'){
                    posY++; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char shopText[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') upgradeShop();
                        if (action == 'n') break;
                    }             

                } else{
                    s[posX][posY] = 'P';
                    s[posX][tmp] = ' ';
                }                
                break;

            case 'd':
            case 'D':
                tmp = posY;
                posY++;
                if (s[posX][posY]=='/' || s[posX][posY]=='#' || 
                s[posX][posY]=='-' || s[posX][posY]=='|' ||
                s[posX][posY]=='\\' || s[posX][posY]=='.' || s[posX][posY]=='_'){
                    posY--; 
                    s[posX][posY] = 'P';
                    break;
                }else if (s[posX][posY]=='I'){
                    posY--; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char shopText[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') itemShop();
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='U'){
                    posY--; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char shopText[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') upgradeShop();
                        if (action == 'n') break;
                    }             

                } else{
                    s[posX][posY] = 'P';
                    s[posX][tmp] = ' ';
                }
                break;

            case 'w':
            case 'W':
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
                        char shopText[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') itemShop();
                        if (action == 'n') break;
                    }             

                } else if (s[posX][posY]=='U'){
                    posX++; 
                    s[posX][posY] = 'P';
                    gotoxy(45,15);
                    printf("Press SPACE to interact");
                     action = getch();

                    if (action == ' '){
                        char shopText[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') upgradeShop();
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
            case 'S':
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
                        char shopText[2][50]={"Welcome to item shop!","Do you want to buy any item ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') itemShop();
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
                        char shopText[2][50]={"Hohoo! This is an upgrade shop","Any thing i can do for you ? [y/n]"};

                        for (int i=0; i<2; i++){
                            gotoxy(45, 12+i);
                            for (int j=0; j<strlen(shopText[i]); j++){
                                printf("%c", shopText[i][j]);
                                Sleep(1.2);
                            }   
                        }
                        action = getch(); 

                        if (action == 'y') upgradeShop();
                        if (action == 'n') break;
                    }             

                } else{
                    s[posX][posY] = 'P';
                    s[tmp][posY] = ' ';
                }
                break;

            case 'o':
            case 'O': 
                // open backpack 
                system("cls"); 
                gotoxy(5,3); 
                printf("%s backpack's", currentPlayer.name); 
                gotoxy(5,4); 
                printf("===========================================");
                gotoxy(5,7); 
                printf("back to game [press enter]"); 
                getch(); 

        }

    }
}

void gamePlay(){
    getch();
}

void itemShop(){
    system("cls"); 
    gotoxy(5,2); 
    printf("Welcome to the item shop"); 
    gotoxy(5,3); 
    printf("1. Potion [$5]"); 
    gotoxy(5,4); 
    printf("2. Max Potion [$20]"); 
    gotoxy(5,5); 
    printf("3. Energy Drink [$3]"); 
    gotoxy(5,6); 
    printf("4. Max Energy Drink [$15]"); 
    gotoxy(5,7); 
    printf("5. Bomb [$10]"); 
    gotoxy(5,8); 
    printf("6. Back"); 

    char cursorLoc[6][3];
    cursorLoc[0][1] = '<'; 
    cursorLoc[1][1] = ' ';
    cursorLoc[2][1] = ' ';
    cursorLoc[3][1] = ' ';
    cursorLoc[4][1] = ' ';
    cursorLoc[5][1] = ' ';
    int bought; 
    int posX = 0; 

    while(TRUE){
        for (int i=0; i<=6; i++){
            gotoxy(35, 3+i); 
            printf("%c", cursorLoc[i][1]); 
        }

        char cursor = getch();
        switch (cursor){
            case 'w':
            case 'W': 
                cursorLoc[posX][1] = ' ';
                posX--; 
                if (posX < 0) posX = 0; 
                cursorLoc[posX][1] = '<';
                break;
            
            case 's':
            case 'S':
                cursorLoc[posX][1] = ' ';
                posX++; 
                if (posX > 5) posX = 5; 
                cursorLoc[posX][1] = '<';
                break;

            case '\r': 
                switch (posX){
                    case 0: 
                        gotoxy(5,10); 
                        printf("How many Potion do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();
                        break;

                    case 1: 
                        gotoxy(5,10); 
                        printf("How many Max Potion do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();
                        break;

                    case 2: 
                        gotoxy(5,10); 
                        printf("How many Energy Drink do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();
                        break;

                    case 3: 
                        gotoxy(5,10); 
                        printf("How many Max Energy Drink do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();
                        break;

                    case 4: 
                        gotoxy(5,10); 
                        printf("How many Bomb do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();
                        break;
                    
                    case 5: 
                        gotoxy(5,10); 
                        printf("See you again! [press enter]");
                        getch();
                        return; 
                }
        }
    }
}

void upgradeShop(){
    system("cls"); 
    gotoxy(5,2); 
    printf("Do you need anything to upgrade ?"); 
    gotoxy(5,3); 
    printf("1. HP 300/300 - $50"); 
    gotoxy(5,4); 
    printf("2. Energy 500/500 - $50"); 
    gotoxy(5,5); 
    printf("3. Armor 30/30 - $30"); 
    gotoxy(5,6); 
    printf("4. Back"); 

    char cursorLoc[4][3];
    cursorLoc[0][1] = '<'; 
    int bought; 
    int posX = 0; 

    while(TRUE){
        for (int i=0; i<=4; i++){
            cursorLoc[i][1] = ' '; 
            gotoxy(35, 3+i); 
            printf("%c", cursorLoc[i][1]); 
        }

        char cursor = getch();

        switch (posX){
            case 'w':
            case 'W': 
                cursorLoc[posX][1] = ' ';
                posX--; 
                if (posX < 0) posX = 0; 
                cursorLoc[posX][1] = '<';
                break;
            
            case 's':
            case 'S':
                cursorLoc[posX][1] = ' ';
                posX++; 
                if (posX > 3) posX = 3; 
                cursorLoc[posX][1] = '<';
                break;

            case '\r': 
                switch (posX){
                    case 0: 
                        gotoxy(5,10); 
                        printf("How many Potion do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();

                    case 1: 
                        gotoxy(5,10); 
                        printf("How many Max Potion do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();

                    case 2: 
                        gotoxy(5,10); 
                        printf("How many Energy Drink do you want to buy ?");
                        gotoxy(5,11); 
                        printf("-"); 
                        gotoxy(8,11); 
                        bought = getche();

                    case 3: 
                        gotoxy(5,10); 
                        printf("Good bye! Dont forget to came again [press enter]");
                        getch();
                        return; 

                    
                }
        }
    }
}
        
void leaderboard(){

    char uname[100][100], temp[100]; 
    int hiscore[100], n=0; 

    FILE *score = fopen("./database/score.dat", "r"); 

    while(!feof(score)){
        fscanf(score, "%[^#]#%d\n", uname[n], &hiscore[n]); 
        n++;
    }

    fclose(score); 

    for (int i=0; i<playerIndex; i++){
        for (int j=0; j<playerIndex-1-i; j++){
            if (hiscore[j] < hiscore[j+1]){
                strcpy(temp, uname[j]); 
                int tempScore = hiscore[j+1]; 
                
                strcpy(uname[j+1], uname[j]); 
                hiscore[j+1] = hiscore[j]; 

                strcpy(uname[j], temp); 
                hiscore[j] = tempScore; 
            }
        }
    }

    system("cls"); 

    gotoxy(5,2); 
    printf("C Space Invader Scoreboard");
    gotoxy(5,3); 
    printf("====================================="); 

    for (int i=0; i<n; i++){
        gotoxy(5, 5+i); 
        printf("%d. %s | %d", i+1, uname[i], hiscore[i]); 
    }

    gotoxy(5, n+7); 
    printf("Back to menu? [press enter]"); 
    getch();
    return; 
}        
        
        
        