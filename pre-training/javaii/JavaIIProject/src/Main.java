import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    private final Scanner sc = new Scanner(System.in);
    private ArrayList<User> users = new ArrayList<>();
    private Customer cust = new Customer();
//    private HashMap

    public Main() {
        while (true) {
            try {
                File playerFile = new File("src/player.txt");
                playerFile.createNewFile();
            } catch (IOException e) {e.printStackTrace();}
            users.clear();
            System.out.println("1. Login\n" +
                    "2. Register\n" +
                    "3. Exit");
            System.out.print(">> ");
            int choose = 0;
            do {
                try {
                    choose = sc.nextInt();
                    sc.nextLine();
                } catch (InputMismatchException e) {
                    System.out.println("Input a number");
                    sc.next();
                    System.out.print(">> ");
                }
            } while (!(choose > 0 && choose < 4));

            switch (choose) {
                case 1 :
                    login();
                    break;
                case 2 :
                    register();
                    break;
                case 3 :
                    System.exit(0);
                    break;
                default :
                    break;
            }
        }
    }

    private void login() {

        System.out.print("Enter your username: ");
        String uname = sc.nextLine();
        System.out.print("Enter your password: ");
        String pass = sc.nextLine();

        try {
            BufferedReader br = new BufferedReader(new FileReader("src/player.txt"));
            String s;
            int i = 0;
            while ((s = br.readLine()) != null) {
                String[] arr = s.split("#");
                users.add(new User(arr[1], arr[0], Integer.parseInt(arr[2])));
            }
            br.close();
        } catch (IOException e) {e.printStackTrace();}
        for (int i = 0; i < users.size(); i++)
            if (users.get(i).getUsername().equals(uname))
                if (users.get(i).getPassword().equals(pass))
                    home(uname, users.get(i).getScore());
        return;
    }

    private void register() {
        String uname, pass;
        do {
            System.out.print("Input a unique username [ 5..30 ] : ");
            uname = sc.nextLine();
            for (User u: users)
                if (uname.equals(u.getUsername())) {
                    System.out.println("Username has been taken, choose another username");
                    continue;
                }
        } while (uname.length() < 5 || uname.length() > 30);

        do {
            System.out.print("Input your password [ 8..20 ] : ");
            pass = sc.nextLine();
        } while (pass.length() < 8 || pass.length() > 20);

        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("src/player.txt", true));
            String s = String.join("#", uname, pass, String.valueOf(0));
            bw.write(s);
            bw.write("\n");
            bw.close();
        } catch (IOException e) {e.printStackTrace();}
        return;
    }

    private void home(String player, int score) {
        int choose = 0;
        System.out.printf("%-25s | %-25s\n", player, score);
        System.out.println("1. Play game\n" +
                "2. View scoreboard\n" +
                "3. Exit");
        System.out.print(">> ");
        do {
            try {
                choose = sc.nextInt();
                sc.nextLine();
            } catch (InputMismatchException e) {
                System.out.println("Input a number");
                sc.next();
                System.out.print(">> ");
            }
        } while (!(choose > 0 && choose < 4));
        switch (choose) {
            case 1:
                game(score);
                break;
            case 2:
                scoreboard(player, score);
                break;
            case 3:
                return ;
            default: break;
        }
    }
    private void game(int score) {
        Game gem = new Game();
        gem.init();
        cust.init();
        while (true) {
            try {
                Thread.sleep(1);
                System.out.println(); // change this with cls();
                System.out.printf("Time: %d, Life: %d, Score: %d\n", gem.getTime(), gem.getLife(), score);
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void scoreboard(String player, int score) {
        for (User u : users) {
            if (player.equals(u.getUsername())) {
                System.out.printf(" %-25s| %-25d\n", player, score);
            }
            System.out.printf(" %-25s| %-25d", u.getUsername(), u.getScore());
        }
    }
    public static void main (String[]args){
        new Main();
    }
}