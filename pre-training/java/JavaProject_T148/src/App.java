import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class App {
    static Scanner sc = new Scanner(System.in);
    private ArrayList<String> uname;
    private ArrayList<String> pwd;
    private ArrayList<Integer> score;
    private final Crypt crypt = new Crypt();
    int choose;

    public App() {
        while (true){
            menu();
        }
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
        uname = new ArrayList<>();
        pwd = new ArrayList<>();
        score = new ArrayList<>();
        String tempUser = "";
        int tempScore = 100, pos = 0;
        // login menu will prompt uname and pass, then checking with database
        try {
            BufferedReader read = new BufferedReader(new FileReader("src/SuperS3cr3tFile.dat"));
            String s;
            while ((s = read.readLine()) != null){
                String[] tempArr = crypt.decrypt(s).split("#");
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
                tempScore = score.get(i);
                pos = i;
                System.out.println("[*] Successfully logged in\n" +
                        "Press enter to continue... ");
                sc.nextLine();
                homeMenu(tempUser, tempScore, pos);
            }
        }
        System.out.println("Invalid username/password\n" +
                "Press enter to continue...");
        sc.nextLine();
    }
    void register() {
        uname = new ArrayList<>();
        pwd = new ArrayList<>();
        score = new ArrayList<>();
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
        } while ((ch != 0 || num != 0));

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("src/SuperS3cr3tFile.dat", true));
            String tmp = crypt.encrypt(String.join("#", tempUname, tempPwd, "100"));
            writer.write(tmp);
            writer.write("\n");
            writer.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        uname.clear();
        pwd.clear();
        score.clear();

        return;
    }
    private void homeMenu(String user, int score, int pos){
        int choose;
        do {
            System.out.printf("""
                =====================
                | Hello, %-11s|
                | point : %-10d|
                =====================
                | 1. Play           |
                | 2. Highscore      |
                | 3. Save & Logout  |
                =====================\n""", user,score);
            System.out.print("Choose [1 - 3] >> ");
            choose = sc.nextInt();
            sc.nextLine();
        } while (choose < 1 || choose > 3);

        switch (choose){
            case 1 -> score = blackJack(user, score);
            case 2 -> leaderboard(user, score, pos);
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

    private int sum(String card, int shum){
        int tmp = 0;
        if (card.contains("A")){
            if (shum < 11){
                tmp += 10;
            } else {
                tmp += 1;
            }
        } else if (card.contains("2")){
            tmp += 2;
        } else if (card.contains("3")){
            tmp += 3;
        } else if (card.contains("4")){
            tmp += 4;
        } else if (card.contains("5")){
            tmp += 5;
        } else if (card.contains("6")){
            tmp += 6;
        }else if (card.contains("7")){
            tmp += 7;
        } else if (card.contains("8")){
            tmp += 8;
        } else if (card.contains("9")){
            tmp += 9;
        }else if (card.contains("10")){
            tmp += 10;
        } else if (card.contains("J")){
            tmp += 10;
        }else if (card.contains("Q")){
            tmp += 10;
        }else if (card.contains("K")){
            tmp += 10;
        }

        return tmp;
    }
    private int blackJack(String user, int points){
        ArrayList<String> player = new ArrayList<>();
        ArrayList<String> dealer = new ArrayList<>();
        if (points == 0){
            System.out.println("""
                    =====================================
                    |           !!! ERROR !!!           |
                    =====================================
                    | Your account has reached 0 point  |
                    | and been banned by system         |
                    =====================================
                    """);
            System.out.print("Press enter to continue...");
            sc.nextLine();
        }
        // start phase
        Deck deck = new Deck();
        deck.shuffle();
        player.add(deck.draw());
        dealer.add(deck.draw());
        player.add(deck.draw());
        dealer.add(deck.draw());
        int bet = betting();
        int playersum = 0, dealersum = 0;
        boolean status = true;


        // print menu hit/stand
        while (status == true){
            System.out.println("Dealer Card:");
            // print dealer card
            for (int i = 0; i < dealer.size(); i++){
                if (i == 1 && dealer.size() == 2){
                    System.out.print("??\n");
                    break;
                } else {
                    System.out.print(dealer.get(i));
                    if (i == dealer.size() - 1) {
                        System.out.println();
                    } else {
                        System.out.print(" | ");
                    }
                }
            }

            System.out.println("Player Card:");
            // print player card
            for (int i = 0; i < player.size(); i++){
                System.out.print(player.get(i));
                if (i == player.size() - 1) {
                    System.out.println();
                } else {
                    System.out.print(" | ");
                }

            }

            System.out.println("""
                ====================\040
                | Choose your move |
                ====================
                | 1. Hit           |\040
                | 2. Stand         |\040
                ====================
                """);
            System.out.print("Choose [1 - 2] >> ");
            choose = sc.nextInt();
            sc.nextLine();

            switch (choose){
                case 1:
                    player.add(deck.draw());

                    // count player value
                    for (String s : player) {
                        playersum += sum(s, playersum);
                    }

                    // count dealer value
                    for (String s : dealer) {
                        dealersum += sum(s, dealersum);
                    }

                    if (playersum > 21){
                        status = false;
                        break;
                    }
                    break;
                case 2:
                    for (String s : player) {
                        playersum += sum(s, playersum);
                    }

                    for (String s : dealer) {
                        dealersum += sum(s, dealersum);
                    }

                    if (dealersum < 17){
                        dealer.add(deck.draw());
                        status = false;
                    } else if (dealersum > 21){
                        status = false;
                        break;
                    }
                default:
                    break;
            }
        }

        // give value ke kartu
        playersum = 0;
        dealersum = 0;
        for (String s : player) {
            playersum += sum(s, playersum);
        }

        for (String s : dealer) {
            dealersum += sum(s, dealersum);
        }

        // print final board status
        for (int i = 0; i < dealer.size(); i++){
            System.out.print(dealer.get(i));
            if (i == dealer.size() - 1) {
                System.out.println();
            } else {
                System.out.print(" | ");
            }
        }

        System.out.println("Player Card:");
        // print player card
        for (int i = 0; i < player.size(); i++){
            System.out.print(player.get(i));
            if (i == player.size() - 1) {
                System.out.println();
            } else {
                System.out.print(" | ");
            }
        }

        // game result
        if ((dealersum > 21) || (playersum > dealersum && playersum <= 21)){
            System.out.printf("[!] The dealer busted, you won %d point(s)\n", bet*2);
            System.out.print("Press enter to continue...");
            points += bet*2;
            sc.nextLine();
        } else if ((playersum > 21) || (playersum < dealersum)){
            System.out.printf("[!] %s Busted, You lost %d points\n", user, bet); // lost = bet
            System.out.print("Press enter to continue...");
            points -= bet;
            sc.nextLine();
        }else {
            System.out.print("[!] It's a tie, you got nothing");
            System.out.print("Press enter to continue...");
            sc.nextLine();
            return 0;
        }
        return points;
    }

    private void bye(){
        try {
            BufferedWriter write = new BufferedWriter(new FileWriter("src/SuperS3cr3tFile.dat", false));

            for (int i = 0; i < uname.size(); i++){
                write.write(crypt.encrypt(String.join("#", uname.get(i), pwd.get(i), String.valueOf(score.get(i)))));
                write.write("\n");
            }
            write.close();

            uname.clear();
            pwd.clear();
            score.clear();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        menu();
    }

    public void sort(int from, int to){
        if (from == to){
            return;
        }
        int mid = from + (to-from) / 2;

        sort(from, mid);
        sort(mid+1, to);
        merge(from, mid, to);
    }
    public void merge(int from, int mid, int to){
        int n = to - from + 1;
        int l = mid - from + 1;
        int r = to - mid;
        int i = 0;
        Integer[] sR = new Integer[n];
        Integer[] sL = new Integer[n];
        String[] cR = new String[n];
        String[] cL = new String[n];

        for (i = 0; i < l; i++){
            sR[i] = score.get(mid + 1 + i);
            cR[i] = uname.get(mid + 1 + i);
        }

        for (i = 0; i < r; i++){
            sL[i] = score.get(from + i);
            cL[i] = uname.get(from + i);
        }

        int dexLeft = 0, dexRight = 0;
        int currDex = from;

        while (dexLeft < l && dexRight < r){
            if (sL[dexLeft].compareTo(sR[dexRight]) >= 0){
                score.set(currDex, sL[dexLeft]);
                uname.set(currDex, cL[dexLeft]);
                dexLeft++;
            } else {
                score.set(currDex, sR[dexRight]);
                uname.set(currDex, cR[dexRight]);
                dexRight++;
            }
            currDex++;
        }

        while (dexLeft < l){
            score.set(currDex, sL[dexLeft]);
            uname.set(currDex, cL[dexLeft]);
            dexLeft++;
            currDex++;
        }

        while (dexRight < r) {
            score.set(currDex, sR[dexRight]);
            uname.set(currDex, cR[dexRight]);
            dexRight++;
            currDex++;
        }

    }
    private void leaderboard(String user, int points, int position){
        score.add(position, points);
        sort(0, uname.size() - 1);

        System.out.print("""
                ===========================
                |        HIGHSCORE        |
                ===========================
                | Username   | Point      |
                ===========================
                """);
        for (int i = 0; i < uname.size(); i++){
            System.out.printf("| %-11s| %-12d|\n", uname.get(i), score.get(i));
        }
        System.out.println("===========================");
        System.out.print("Press enter to continue...");
        sc.nextLine();
    }

    public static void main(String[] args) throws Exception {
        new App();
    }
}
