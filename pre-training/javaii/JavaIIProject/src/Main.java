import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private final Scanner sc = new Scanner(System.in);
    private ArrayList<User> users = new ArrayList<>();

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
            int choose = sc.nextInt();
            sc.nextLine();
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
        System.out.println("1. Play game\n" +
                "2. View scoreboard\n" +
                "3. Exit");
        int choose = sc.nextInt(); sc.nextLine();
        switch (choose) {
            case 1:
                game();
                break;
            case 2:
                scoreboard();
                break;
            case 3:
                return ;
            default: break;
        }
    }
    public static void main (String[]args){
        new Main();
    }
}
