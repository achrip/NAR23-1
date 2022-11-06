import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class App {
    static Scanner sc = new Scanner(System.in);
     private ArrayList<String> uname = new ArrayList<>();
     private ArrayList<String> pwd = new ArrayList<>();
     private ArrayList<Integer> score = new ArrayList<>();
     private Crypt crypt = new Crypt();
     int choose;

    public App() {
        menu();
    }
     void menu() {
        do {
            choose = 0;
            System.out.println("""
                    ======================
                    | ♥   BlueJack   ♠ |
                    | ♦   Card Game  ♣ |
                    ======================
                    | 1.  Login          |
                    | 2.  Register       |
                    | 3.  Exit           |
                    ======================""");

            System.out.print("Choose [1 - 3] >> ");
            choose = sc.nextInt();
            sc.nextLine();
        } while (choose < 1 || choose > 3);

        switch (choose) {
            case 1 -> login();
            case 2 -> register();
            case 3 -> System.exit(0);
            default -> {}
        }
    }
     void login() {
        String tempScore, tempUser;
        // login menu will prompt uname and pass, then checking with database
        try {
            BufferedReader read = new BufferedReader(new FileReader("src/SuperS3cr3tFile.dat"));
            String s;
            Crypt crypt = new Crypt(); // instantiate object
            while ((s = read.readLine()) != null){
                String temp = crypt.decrypt(s);
                String[] tempArr = temp.split("#");
                uname.add(tempArr[0]);
                pwd.add(tempArr[1]);
                score.add(Integer.valueOf(tempArr[2]));

            }
            read.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        System.out.print("Input username : ");
        String logUname = sc.nextLine();
        System.out.print("Input password : ");
        String logPwd = sc.nextLine();

        for (int i = 0; i < uname.size(); i++) {
            if (logUname.contains(uname.get(i)) && logPwd.contains(pwd.get(i))) {
                tempUser = uname.get(i);
                tempScore = String.valueOf(score.get(i));
                System.out.println("[*] Successfully logged in\n" +
                        "Press enter to continue... ");
                sc.nextLine();
            } else {
                System.out.println("Invalid username/password\n" +
                        "Press enter to continue...");
                sc.nextLine();
            }
        }
        homeMenu(tempUser, tempScore);
    }
     void register() {
        int ch = 0, num = 0;
        String tempUname, tempPwd;
         try {
             BufferedReader read = new BufferedReader(new FileReader("src/SuperS3cr3tFile.dat"));
             String s;
             while ((s = read.readLine()) != null){
                 String temp = crypt.decrypt(s);
                 String[] tempArr = temp.split("#");
                 uname.add(tempArr[0]);
                 pwd.add(tempArr[1]);
                 score.add(Integer.valueOf(tempArr[2]));

                 System.out.println(uname);
             }
             read.close();
         } catch (IOException e) {
             e.printStackTrace();
         } catch (Exception e) {
             throw new RuntimeException(e);
         }
        while (true){
            System.out.print("Input username : ");
            tempUname = sc.nextLine();

            if (tempUname.length() < 4 || tempUname.length() > 10){
                System.out.println("[!] Username must be between 4 and 10 characters");

            } else {
                for (String s : uname) {
                    if (tempUname.contains(s)) {
                        System.out.println("[!] Username already exist");
                        break;
                    }
                }
                break;
            }
        }

        do {
            System.out.print("Input password : ");
            tempPwd = sc.nextLine();
            char[] pass = tempPwd.toCharArray();

            for (char c : pass) {
                if (Character.isDigit(c)){
                    num++;
                } else {
                    ch++;
                }
            }
            if (tempPwd.length() < 8 || tempPwd.length() > 16){
                System.out.println("[!] Password must be between 8 and 16 characters");
                if (ch == 0 || num == 0){
                    System.out.println("[!] Password must be alphanumeric");
                }
            } else break;
        } while ((tempPwd.length() < 6 || tempPwd.length() > 16 )&& (ch != 0 || num != 0) );

        try {
            PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("src/SuperS3cr3tFile.dat")));
            String tmp = crypt.encrypt(String.join("#", tempUname, tempPwd, "0"));
            writer.println(tmp);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
     }
    private void homeMenu(String user, int score){
        int choose;
        do {
            System.out.printf("""
                =====================
                | Hello, %-5s|
                | point : %-9d|
                =====================
                | 1. Play           |
                | 2. Highscore      |
                | 3. Save & Logout  |
                =====================""", user,score);
            System.out.print("Choose [1 - 3] >> ");
            choose = sc.nextInt();
                sc.nextLine();
        } while (choose < 1 || choose > 3);

        switch (choose){
            case 1 -> blackJack(user, score);
            case 2 -> leaderboard();
            case 3 -> bye();  // clear arraylist every logout
            default -> {}
        }
    }

    private int betting() {
        int bet;
        while (true) {
            System.out.print("Input your bet [max 100]: ");
            bet = sc.nextInt();
            sc.nextLine();
            if (bet < 1 || bet > 100) {
                System.out.println("[!] Input must be between 1 and 100");
            } else break;
        }
        return bet;
    }

    private void blackJack(String user, int score){
        ArrayList<String> player = new ArrayList<>();
        ArrayList<String> dealer = new ArrayList<>();
        int bet = betting();

        Deck deck = new Deck();
        deck.shuffle();

        // start phase
        player.add(deck.draw());
        dealer.add(deck.draw());
        player.add(deck.draw());
        dealer.add(deck.draw());

        // TODO print menu hit/stand
        System.out.println("Dealer Card:");
        for (String s : dealer){
            System.out.print(s);
            System.out.print(" | ");
        }
        System.out.println();

        System.out.println("Player Card:");
        for (String s : player){
            System.out.print(s);
            System.out.print(" | ");
        }
        System.out.println();

        System.out.println("""
                ==================== 
                | Choose your move |
                ====================
                | 1. Hit           | 
                | 2. Stand         | 
                ====================
                """);
        System.out.print("Choose [1 - 2] >> ");
        choose = sc.nextInt();
            sc.nextLine();

        switch (choose){
            case 1:
                player.add(deck.draw());
                break;
            case 2:
                if (/*dealersum*/ < 17){
                dealer.add(deck.draw());
            } else {
                // dealer will stand
            }
            default:
                break;
        }

        // TODO game lanjut/selesai
        if (dealersum > 21){
            System.out.printf("[!] The dealer busted, you won %d point(s)\n", bet*2);
            System.out.print("Press enter to continue...");
            score += bet*2;
            sc.nextLine();
        } else if (playersum > 21){
            System.out.printf("[!] %s Busted, You lost %d points\n", user, bet); // lost = bet
            System.out.print("Press enter to continue...");
            score -= bet;
            sc.nextLine();
        }else if (playersum > dealersum && playersum <= 21){
        } else if (playersum < dealersum && dealersum <= 21){

        }

    }


    public static void main(String[] args) throws Exception {

//        new App();
//        // System.out.println("\u2666"); // diamond suit
//        // System.out.println("\u2660" ); // spade suit
//        // System.out.println("\u2663" ); // club suit
//        // System.out.println("\u2665" ); // heart suit


    }
}
