import javax.crypto.Cipher;
import javax.crypto.spec.GCMParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Base64;
import java.util.Scanner;


public class App {
    static Scanner sc = new Scanner(System.in);
     ArrayList<String> uname = new ArrayList<>();
     ArrayList<String> pwd = new ArrayList<>();
     ArrayList<Integer> score = new ArrayList<>();
     int choose;

    public App() {
        menu();
    }
    // create the main menu for the card game
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
        // login menu will prompt uname and pass, then checking with database
        try {
            BufferedReader read = new BufferedReader(new FileReader("src/SuperS3cr3tFile.dat"));
            String s;
            // TODO: instance object here
            Crypt crypt = new Crypt();
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
         System.out.print("Input username : ");
        String logUname = sc.nextLine();
        System.out.print("Input password : ");
        String logPwd = sc.nextLine();

        for (int i = 0; i < uname.size(); i++) {
            if (logUname.contains(uname.get(i)) && logPwd.contains(pwd.get(i))) {
                System.out.println("[*] Successfully logged in\n" +
                        "Press enter to continue... ");
                sc.nextLine();
            } else {
                System.out.println("Invalid username/password\n" +
                        "Press enter to continue...");
                sc.nextLine();
            }
        }

    }

     void register() {
        while (true){
            System.out.print("Input username : ");
            String tempUname = sc.nextLine();

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

        while (true){
            System.out.print("Input password : ");
            String tempPwd = sc.nextLine();
            char[] pass = tempPwd.toCharArray();

            if (tempPwd.length() < 8 || tempPwd.length() > 16){
                System.out.println("[!] Password must be between 8 and 16 characters");

            } else {
                for (char c : pass){
                    if (!(Character.isDigit(c))){
                        System.out.println("[!] Password must be alphanumeric");
                    }
                }
            }
        }
    }

//    private void homeMenu(){
//        int choose;
//        do {
//            System.out.printf("""
//                =====================
//                | Hello, %s         |
//                | point : %d        |
//                =====================
//                | 1. Play           |
//                | 2. Highscore      |
//                | 3. Save & Logout  |
//                =====================""", tempUser,tempScore);
//            System.out.print("Choose [1 - 3] >> ");
//            choose = sc.nextInt();
//                sc.nextLine();
//        } while (choose < 1 || choose > 3);
//
//        switch (choose){
//            case 1 -> game();
//            case 2 -> leaderboard();
//            case 3 -> bye();
//            default -> {}
//        }
//    }
//
//    private int betting() {
//        int bet;
//        while (true) {
//            System.out.print("Input your bet [max 100]: ");
//            bet = sc.nextInt();
//            sc.nextLine();
//            if (bet < 1 || bet > 100) {
//                System.out.println("[!] Input must be between 1 and 100");
//            } else break;
//        }
//        return bet;
//    }
//
//    private void game(){
//        int bet = betting();
//
//
//    }


    public static void main(String[] args) throws Exception {
        new App();
//        // System.out.println("\u2666"); // diamond suit
//        // System.out.println("\u2660" ); // spade suit
//        // System.out.println("\u2663" ); // club suit
//        // System.out.println("\u2665" ); // heart suit


    }
}