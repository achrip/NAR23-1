#include <stdio.h>

// Functions
int menu(); 
void game_menu(); 
void game_play(int difficulty);
void view_highscore();
void help(); 
void merge_sort(int left, int right); 
void merge(int left, int mid, int right);

// Structs 
struct DifficultyStruct {
    int initialEnemy; 
    int enemySpawn;  
    int healthPoint; 
} levels[3];

struct HighscoreStruct {
    char name[255]; 
    int difficulty; 
    long int score; 
} hscore[255];

int main() {
    levels[0] = { .initialEnemy = 5, .enemySpawn = 2, .healthPoint = 6};
    levels[1] = { .initialEnemy = 7, .enemySpawn = 3, .healthPoint = 4};
    levels[2] = { .initialEnemy = 9, .enemySpawn = 4, .healthPoint = 2};

    while (1) {
        switch (menu()) {
            case 1: 
                game_menu();
                break; 
            case 2: 
                view_highscore();
                break; 
            case 3: 
                help();
                break; 
            case 4: 
                exit(0); 
                break; 
            default: 
                break; 
        }
    }
    return 0; 
}

int menu() {
    int choose; 
    printf("Untitled Shooter Game Main Menu\n"); 
    printf("===============================\n");
    printf("1. Play Game\n2. Highscore\n3. Help\n4. Exit\n"); 
    printf("Input [1-4]: "); 
    scanf("%d", &choose); 
    getchar();

    return choose; 
}

void game_menu() {
    char string[255]; 
    int difficulty; 

    do {
        printf("Input Hero's name [Must be between 3 and 10 characters (inclusive)]: "); 
        scanf("%[^\n]", &string); 
        getchar(); 
    } while ((sizeof(string)/sizeof(char)) < 3 || (sizeof(string)/sizeof(char) > 10));

    do {
        printf("Input difficulty [Must be between 1 and 3 (inclusive)]: "); 
        scanf("%d", &difficulty);
        getchar(); 
    } while (difficulty < 1 || difficulty > 3);

    long int score = game_play(difficulty); 

    // append to file after returning from the game
    FILE *fp = fopen("highscore.csv", "a"); 
    fprintf(fp, "%s,%d,%ld\n", string, difficulty, score);
    fclose(fp); 
}

long int game_play(int difficulty) {
    levels[difficulty - 1];
}

void view_highscore() {
    printf("Untitled Shooter Highscores\n");
    printf("===============================\n");
    printf("%-12s%-13s%-5s\n", "Name", "Difficulty", "Score");

    FILE *fp = fopen("highscore.csv", "r"); 

    // if the file never exists in the first place
    if (!fp) puts("Error: File Not Found!"); 

    // populate the struct array
    int id = 0; 
    while (fscanf(fp, "%[^,],%d,%ld", &hscore[id].name, &hscore[id].difficulty, &hscore[id].score) == 3) id++;

    // if there exists no data in the file
    if (id == 0) puts("No highscore has been set yet");

    // print the sorted struct array
    for (int i = 0; i <= id; i++) printf("%-12s%-13d%-10ld\n", &hscore[id].name, 
                                        &hscore[id].difficulty, &hscore[id].score);
    
    fclose(fp);
    printf("Press enter to go back to main menu."); 
    getchar(); 
}

void help() {
    printf("Untitled Shooter Game Help\n"); 
    printf("============================\n");
    printf("How To Play:\n");
    printf("You play as an untitiled hero that needs to survive as long as possible against the enemy horde.\n");
    printf("The hero is able to shoot the enemy to kill them in one shot. On the other hand, the enemy is\n");
    printf("able to melee strike the hero, reducing his health in the process but also killing the enemhy.\n");
    printf("For each random amount of time, a health pack will appear on the map. This health pack can be\n");
    printf("picked up by the hero to restore their health.");

    printf("\nScore:\n"); 
    printf("When the hero is eventually slain, a score will be calculated. The calculated score can be\n"); 
    printf("viewed again in the Highscore menu.\n"); 

    printf("\nControls:\n"); 
    printf("W: Move Up\nS: Move Down\nA: Move Left\nD: Move Right\n\nK: Shoot\n\nESC: Exit from current game session\n"); 

    printf("\nPress enter to go back to main menu.");
    getchar(); 
}

void merge_sort(int left, int right) {

    // this acts as a base case. in which when left == right, the function returns immediately
    if (left < right) {
        int mid = left + (right-left) / 2;  

        merge_sort(left, mid);
        merge_sort((mid + 1), right); 
        merge(left, mid, right); 
    }
}

void merge(int left, int mid, int right) {
    int n = right - left + 1; 
    int l = mid - left + 1; 
    int r = right - mid; 
 
    Highscore L[l], R[r];
    for (int i = 0; i < r; i++) R[i] = hscore[mid + 1 + i]; 
    for (int i = 0; i < l; i++) L[i] = hscore[left + i]; 

    int leftIndex = 0, rightIndex = 0; 
    int currentIndex = left; 

    while (leftIndex < l && rightIndex < r) {
        // check the score 

        // the score is similar, check difficulty levels
        if (L[leftIndex].score == R[rightIndex].score) {
            // check difficulty

            // lefthand's difficulty is higher than righthand's difficulty
            if (L[leftIndex].difficulty > R[rightIndex].difficulty) { 
                hscore[currentIndex] = L[leftIndex]; 
                leftIndex++; 
            }

            // lefthand's difficulty is lower than righthand's difficulty
            else {
                hscore[currentIndex] = R[rightIndex]; 
                rightIndex++; 
            }

        }

        // the score is not similar, 
        else {
            // lefthand's score is higher than the righthand's 
            if (L[leftIndex].score > R[rightIndex].score) {
                hscore[currentIndex] = L[leftIndex]; 
                leftIndex++;
            } 
            
            // lefthand's score is lower than righthand's
            else {
                hscore[currentIndex] = R[rightIndex];
                rightIndex;
            }
        }
        
        // move on 
        currentIndex++; 
    }

    while (leftIndex < l) {
        hscore[currentIndex] = L[leftIndex]; 
        leftIndex++; 
        currentIndex++; 
    }

    while (rightIndex < r) {
        hscore[currentIndex] = R[rightIndex]; 
        rightIndex++; 
        currentIndex++; 
    }
}

