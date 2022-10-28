#include <stdio.h>
#include <string.h>

struct Stocks {
    double price; 
    char name[1000];
    int index;
    char label[100];
};

void insert(); 
void view(); 
void delete(); 
void exit(); 


int main(){
    int choose;
    struct Stocks stock; 
    // Stocks nama

    printf("1. insert stock\n2. view all stock\n3. delete stock\n4. exit program\n");
    printf(">> ");
    scanf("%d", &choose);
    getchar();

    switch (choose){
        case 1: 
            insert();

            break; 
        
        case 2:
            view(); 
            break; 

        case 3: 
            delete(); 
            break;
        
        case 4: 
            exit(); 
            break;
        
        default: 
            break; 

    }

    return 0; 
}

void insert(){
    struct Stocks stock[10]; 
    int i=0;
    
    // inUID : 
    //     printf("input the stock name[>= 4 characters]: ");
    //     scanf("%[^\n]s", stock.name); 
    //     getchar(); 

    // if (strlen(stock.name)<4){
    //     goto inUID;
    // }

    // inprc: 
    //     printf("input the stock price[>=500]: "); 
    //     scanf("%d", stock.price);
    //     getchar(); 

    // if (stock.price<500){
    //     goto inprc;
    // }
    
    do {
        printf("input the stock name[>= 4 characters]: ");
        scanf("%[^\n]", stock[i].name); 
        getchar(); 
    } while (strlen(stock[i].name)<4); 


    do {
        printf("input the stock price[>=500]: "); 
        scanf("%lf", &stock[i].price);
        getchar(); 
    } while (stock[i].price<500); 
    
            // printf("%s\n", stock[i].name);
            // printf("%d\n", stock[i].price);
    // int pass; 
    // stock[i].code;
    // for (i=0; i<4; ++i){
    //     stock[i].code[i]=(rand()%35)+65;   
    // }
    // for (i=0; i<3; ++i){
    //     stock[i].code[i+4]=(rand()%10)+48;
    // }

    stock[i].index=(stock[i].price/(((rand()%37)+1)*2))*((rand()%100)+1);

    if (stock[i].index<=2853 && stock[i].index>=1){
        // stock[i].label = "small cap";
        strcpy(stock[i].label, "small cap");
    } else if (stock[i].index<=5707 && stock[i].index>=2854){
        // stock[i].label = "middle chip";
        strcpy(stock[i].label, "middle chip");
    } else if (stock[i].index<=8562 && stock[i].index>=5708){
        // stock[i].label = "blue chip";
        strcpy(stock[i].label, "blue chip");
    }

    printf("\n");
    printf("success added new stock named %s with stock code %s\npress enter to continue...", stock[i].name, stock[i].index);    
    //when enter pressed goto menu again
    return stock; 
}

void view(){
    struct Stocks stock[10]; 
    int i=0; 

    if (strlen(stock[i].name) == "\0"){
        printf("there are no stocks, consider to add one\npress enter to continue...");
        // goto menu when enter is pressed
    } else {
        printf("no\t| stock name\2t| stock code\2t| stock label\2t| stock price\2t|");
        
        for (i=0; i<10; ++i){
            printf("%d\t| %s\2t| %s\2t| %s\2t |%lf\2t|", i+1, stock[i].name, stock[i].index,
            stock[i].label, stock[i].price);


        }
    }   
    int composite =0;
    for (i=0; i<10; ++i){
        composite += stock[i].price;
    }
    printf("IDX Composite : %lf\n\npress enter to continue...", composite);

}

void delete(){
    struct Stocks stock[10]; 
    int i=0; 

    if (strlen(stock[i].name) == "\0"){
        printf("there are no stocks, consider to add one\npress enter to continue...");
        // goto menu when enter is pressed
    } else {
        printf("no\t| stock name\2t| stock code\2t| stock label\2t| stock price\2t|");
        
        for (i=0; i<10; ++i){
            printf("%d\t| %s\2t| %s\2t| %s\2t |%lf\2t|", i+1, stock[i].name, stock[i].index,
            stock[i].label, stock[i].price);


        }
    }   
}
