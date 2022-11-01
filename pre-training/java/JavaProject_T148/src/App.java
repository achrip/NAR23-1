import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class App {
    static Scanner sc = new Scanner(System.in);
    static ArrayList<String> uname = new ArrayList<>();
    static ArrayList<String> pwd = new ArrayList<>();
    static ArrayList<Integer> score = new ArrayList<>();
    static int choose;

    public App() {
        menu();
    }

    // create the main menu for the card game
    static void menu() {
        do {
            System.out.println("======================");
            System.out.println("| \u2665   BlueJack   \u2660 |");
            System.out.println("| \u2666   Card Game  \u2663 |");
            System.out.println("======================");
            System.out.println("| 1.  Login          |");
            System.out.println("| 2.  Register       |");
            System.out.println("| 3.  Exit           |");
            System.out.println("======================");

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

    static void login() {
        // login menu will prompt uname and pass, then checking with database
        try {
            BufferedReader read = new BufferedReader(new FileReader("SuperS3cr3tFile.txt"));
            // call Crypt constructor as object to decrypt input from file
            // split decrypt by ';'
            // append decrypted to respective arraylist
            read.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.print("Input usernamne : ");
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

    static void register() {
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

    public static void main(String[] args) throws Exception {
//        // System.out.println("\u2666"); // diamond suit
//        // System.out.println("\u2660" ); // spade suit
//        // System.out.println("\u2663" ); // club suit
//        // System.out.println("\u2665" ); // heart suit


    }
}