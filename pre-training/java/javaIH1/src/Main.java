import java.util.Scanner;
public class Main {
    static Scanner sc = new Scanner(System.in);
    static String uname, level; 
    static int choose, chance, cash, hpotion, apotion; 
    static double hp, atk; 
    static jokeMon player = new jokeMon(hp, atk);
    static jokeMon enemy = new jokeMon(hp, atk);
    static Item playerItem = new Item(0, 0, 100);
    
    public Main(){
        registerPage();
        homePage();
    }

    static void registerPage(){
        System.out.println("JokeMon");
        System.out.println("=======================\n");
        do {
            System.out.print("Input your name [minimum two words]: ");
            uname = sc.nextLine(); 
        } while (uname.length() < 2);
    }

    static void homePage(){
        do {
            System.out.println("Welcome, " + uname);
            System.out.println("1. Play");
            System.out.println("2. Shop");
            System.out.println("3. Quit");
            System.out.print(">> ");
            choose = sc.nextInt(); sc.nextLine();
    
        } while (choose < 1 || choose > 3); 

        switch (choose){
            case 1: 
                play(); 
                break; 
            
            case 2: 
                shop(); 
                break; 

            case 3: 
                System.exit(0);
        }
    }

    // public int jokeStat(int hp, int atk){
    //     this.hp = hp; 
    //     this.atk = atk; 
    // }
    
    // public int player(int hp, int atk, int cash){
    //     this.hp = hp; 
    //     this.atk = atk; 
    //     this.cash = cash;
        
    //     return hp, atk, cash; 
    // }
    static void play(){
        do{
            System.out.println("-------------------");
            System.out.println("Choose 1 JokeMon");
            System.out.println("1. Charmander (health: 100, attack: 20");
            System.out.println("2. Squirtle (health: 70, attack: 40");
            System.out.println("3. Bulbasaur (health: 200, attack: 10");
            System.out.print("Input only 1 to 3: ");
            choose = sc.nextInt(); sc.nextLine();
            System.out.println();
        } while (choose < 1 || choose > 3);

        switch (choose){
            case 1: 
                player.hp = 100;
                player.atk = 20;
                break; 
            
            case 2: 
                player.hp = 70; 
                player.atk = 40;
                break; 
            
            case 3: 
                player.hp = 200; 
                player.atk = 10; 
                break;

            default: 
                break;
        }

        do{
            System.out.println("-------------------");
            System.out.println("Choose Level");
            System.out.println("1. Easy");
            System.out.println("2. Medium");
            System.out.println("3. Hard");
            System.out.print("Input only 'Easy', 'Medium', or 'Hard' (case sensitive): ");
            level = sc.nextLine();
            System.out.println();
        } while (!(level.equals("Easy") || level.equals("Medium") || level.equals("Hard")));

        switch (level){
            case "Easy":
                enemy.hp = 70*0.8; 
                player.atk = 20*1.3; 
                break;
            case "Medium":
                enemy.hp = 70*1.0; 
                player.atk = 20*1.0; 
                break;
            case "Hard":
                enemy.hp = 70*1.3; 
                player.atk = 20*0.8; 
                break;

        }

        gameON(); 
    }

    static void shop(){

    }

    static void gameON(){
        System.out.println("-------------------");
        System.out.println("\tYour Turn ");
        System.out.println("JokeMon health : " + player.atk);
        System.out.println("JokeMon attack : " + player.atk);
        System.out.println("Enemy health   : "+ enemy.hp);
        System.out.println("Enemy attack   : " + enemy.atk);
        System.out.println();
        do{
            System.out.println("1. Attack enemy");
            System.out.println("2. Escape");
            System.out.println("3. Use Item");
            System.out.print(">> ");
            choose = sc.nextInt(); sc.nextLine();
            System.out.println();
        } while (choose < 1 || choose > 3);

        switch (choose){
            case 1: 
                chance = (int) Math.random()*100; 
                if (chance>49){
                    System.out.printf("JokeMon damaged the enemy %d damage!", player.atk);
                    System.out.println("Press ENTER to continue.");
                    enemy.hp -= player.atk; 
                    sc.nextLine();
                    break;
                } else{
                    System.out.println("JokeMon didn't damaged enemy.");
                    System.out.println("Press ENTER to continue.");
                    sc.nextLine();
                    break; 
                }
                
                case 2: 
                if (cash < 90){
                    System.out.println("Unable to escape. You need 90 jokedollar to escape.");
                    System.out.println("Press ENTER to continue.");
                    sc.nextLine();
                    break; 
                } else{
                    cash -= 90; 
                    System.out.println("You escaped the game.");
                    System.out.println("Your money is deducted by 90. ");
                    System.out.println("Press ENTER to continue.");
                    sc.nextLine();
                    homePage();
                }
                break; 
            
            case 3: 
                if (playerItem.hpotion != 0 || playerItem.apotion != 0){
                    System.out.println("Choose Item");
                    System.out.printf("1. %d health potion.\n", playerItem.hpotion);
                    System.out.printf("2. %d attack potion.\n", playerItem.apotion);
                    System.out.println("3. Cancel");
                    System.out.print(">> ");
                    choose = sc.nextInt(); sc.nextLine();

                    switch (choose){
                        case 1: 
                            playerItem.hpotion--; 
                            player.hp += 25;
                            System.out.println();
                            System.out.print("Used 1 health potion. ");
                            System.out.println("Now your JokeMon's health increased by 25.");
                            break; 
                        
                        case 2: 
                        playerItem.apotion--; 
                        player.atk += 25;
                        System.out.println();
                        System.out.print("Used 1 attack potion. ");
                        System.out.println("Now your JokeMon's attack increased by 25.");
                            break; 
                        
                        case 3: 
                            break;
            
                        default: 
                            break;
                    }
                } else {
                    System.out.println("You don't have any item.");
                    System.out.println();
                    System.out.println("Press ENTER to continue.");
                    sc.nextLine();
                    break;
                }
                break;

            default: 
                break;
        }   

        gameOFF();
    }

    static void gameOFF(){
        System.out.println("--------------------------");
        System.out.println("\t Enemy's turn");
        chance = (int)Math.random()*100;
        if (chance > 49){
            System.out.println("Enemy damaged you 20 damage!");
            player.hp -= enemy.hp;
        } else {
            System.out.println("Enemy didn't damaged you.");
        }
    }
    public static void main(String[] args) {
        new Main(); 


    }
}
