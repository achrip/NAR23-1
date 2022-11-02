import java.util.ArrayList;
import java.util.Scanner;
import java.util.SplittableRandom;

public class App {
    int balance, shoe, leash;
    ArrayList<String> wl = new ArrayList<>();
    ArrayList<String> winner = new ArrayList<>();
    ArrayList<Integer> finalPos = new ArrayList<>();
    Scanner sc = new Scanner(System.in);

    char[][] arena = {
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#',' ','P','l','a','y','e','r',' ',' ','|','P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ','#'},
            {'#',' ','B','o','t','1',' ',' ','-',' ','|','B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ','#'},
            {'#',' ','B','o','t','2',' ',' ',' ',' ','|','B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    };

    private void sleep(){
        try {
            Thread.sleep(2);
        } catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    public App(){

    }

    private void menu(){
        System.out.println("Horse Gallop");
        System.out.println("=======================================");
        System.out.println("Balance: " + balance);
        System.out.println("Shoe Level: " + shoe);
        System.out.println("Leash Level: " + leash);
        System.out.println("=======================================");
        System.out.println("1. Begin Race");
        System.out.println("2. View History");
        System.out.println("3. Upgrade Accessories");
        System.out.println("4. Exit");
        System.out.print(">> ");
        int choose = sc.nextInt();

        switch (choose){
            case 1 -> race();
            case 2 -> history();
            case 3 -> upgrade();
            case 4 -> System.exit(0);
            default -> {}
        }
    }
    private void race(){
        SplittableRandom rand = new SplittableRandom();
        double botShoe, botLeash;
        int shoeVal = 1 * shoe;
        int leashVal = 2 * leash;
        botShoe = rand.nextInt(1, shoe);
        botLeash = rand.nextInt(1, leash);

//        int playerX = 1, botX = 3, bot1X = 5;
        int playerY = 11, botY = 1, bot1Y = 11;

        printArena();

        System.out.println("Press enter to start the race..");
        sc.nextLine();

        while (arena[1][51] == ' ' || arena[3][51] == ' ' || arena[5][51] == ' '){
            printArena();
            startMove(playerY, botY, bot1Y);
        }

        if ((arena[1][51] == 'P' && arena[2][51] =='B') ||
            (arena [1][51] == 'P' && arena [3][51] == 'B')){
            System.out.println("Race ended, Draw!");
            if (arena[3][51] == 'B'){
              System.out.println("Winner: Player, Bot2");
            } else if (arena[2][51] == 'B'){
                System.out.println("Winner: Player, Bot1");
            } else {
                System.out.println("Winner: Player, Bot1, Bot2");
            }
        } else if (arena[3][51] == 'B' || arena[5][51] == 'B'){
            System.out.println("Race ended, you Lost!");
        } else {
            System.out.println("Race ended, You Win!");
        }
    }

    private void startMove(int playerY, int botY, int bot1Y) {

        sleep();
        arena[1][playerY] = ' ';
        arena[3][botY] = ' ';
        arena[5][bot1Y] = ' ';

        playerY++;
        botY++;
        bot1Y++;

        arena[1][playerY] = 'P';
        arena[3][botY] = 'B';
        arena[5][bot1Y] = 'B';


    }

    private void history(){
        System.out.println("Race History\n" +
                "=======================================");

        if (wl.size() == 0){
            System.out.println("You havent done any race yet!\n");
            System.out.println("Press enter to continue..");
            sc.nextLine();
        } else {
            for (int i = 0; i < wl.size(); i++){
                System.out.print(wl.get(i) + ", your last position was" + finalPos.get(i)
                + "Winner: " + winner.get(i));
                System.out.println("\n");
                System.out.println("Press enter to continue..");
                sc.nextLine();
            }
        }
    }

    private void upgrade(){
        int choose;
        do {
            System.out.println("Upgrade Accessories" +
                    "=======================================");
            System.out.println("Balance: " + balance);
            System.out.println("Shoe Level: " + shoe);
            System.out.println("Leash Level: " + leash +
                    "=======================================");
            System.out.println("1. Upgrade Shoe");
            System.out.println("2. Upgrade Leash");
            System.out.println("3. Exit");
            System.out.print(">> ");
            choose = sc.nextInt();
        } while (choose != 1 || choose != 2);

        switch (choose){
            case 1:
                if (shoe <3) shoeUP();
                else System.out.println("Your shoe level is already maxed out..");
                break;
            case 2:
                if (leash <3) leashUP();
                else System.out.println("Your leash level is already maxed out..");
                break;
            default:
                break;
        }

        return;
    }

    private void shoeUP(){
        System.out.println("Upgrade shoe level " + shoe + "-> " + (shoe+1) +
                    ", cost: " + (shoe*1000) );
        System.out.print("Are you sure you want to continue? [Yes/No] (Case insensitive): ");
        String choose = sc.nextLine();

        if (choose.equalsIgnoreCase("yes")){
            if (balance >= 1000){
                System.out.println("Shoe successfully upgraded");
            } else System.out.println("Insufficient balance..");
        }

        sc.nextLine();
        return;
    }

    private void leashUP(){
        System.out.println("Upgrade leash level " + leash + "-> " + (leash+1) +
                ", cost: " + (leash*1000) );
        System.out.print("Are you sure you want to continue? [Yes/No] (Case insensitive): ");
        String choose = sc.nextLine();

        if (choose.equalsIgnoreCase("yes")){
            if (balance >= 1000){
                System.out.println("Leash successfully upgraded");
            } else if (leash == 3) {
                System.out.println("Your leash level is already maxed out..");
            } else System.out.println("Insufficient balance..");

        }

        sc.nextLine();
        return;
    }

    private void printArena() {
        for (char cs[] : arena){
            for (char c : cs){
                System.out.print(c);
            }
            System.out.println();
        }
    }

}
