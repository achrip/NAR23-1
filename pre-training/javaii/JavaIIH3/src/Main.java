import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {
    private Scanner sc = new Scanner(System.in);
    private Manager owner;
    private ArrayList<Player> players = new ArrayList<>();
    public Main() {
        while (true) {
            owner = new Manager("default", "default" , 0);
            System.out.println("""
                1. Create Team
                2. Exit""");
            System.out.print(">> ");
            int choose = sc.nextInt(); sc.nextLine();
            switch (choose) {
                case 1 -> regist();
                case 2 -> System.exit(0);
                default -> {}
            }
        }
    }

    public void regist() {
        boolean flag = false;
        do {
            System.out.print("Enter team name [ 5 - 20 characters ] : ");
            String s = sc.nextLine();

            if (s.length() < 5 || s.length() > 20) continue;
            else {
                flag = true;
                owner.setClub(s);
            }
        } while(!flag);
        do {
            System.out.print("Enter owner name [ 5 - 20 characters ] : ");
            String s = sc.nextLine();

            if (s.length() < 5 || s.length() > 20) continue;
            else {
                flag = false;
                owner.setName(s);
            }
        } while (flag);
        owner.setMoney(1000000);
        home();
    }
    public void home () {
        System.out.printf("Team Name    : %s\n", owner.getClub());
        System.out.printf("Team Owner   : %s\n", owner.getName());
        System.out.printf("Team Money   : %d\n", owner.getMoney());

        System.out.println("""
                1. Add Player
                2. Manage Players
                3. Matchmaking
                4. Exit""");
        System.out.print(">> ");
        int choose = sc.nextInt(); sc.nextLine();
        switch (choose) {
            case 1 -> add();
            case 2 -> manage();
            case 3 -> matchmaking();
            case 4 -> {return;}
            default -> {}
        }
    }

    public void add() {
        boolean flag;
        String name, reg, pos;
        int app, num, age;
        while (true) {
            System.out.print("Enter player shirt number [ 1 - 99 and unique ] : ");
            num = sc.nextInt(); sc.nextLine();

            for (Player player : players) {
                if (player.getShirtNumber() == num) continue;
            }
            break;
        }
        while (true) {
            System.out.print("Enter player name [ 7 - 20 characters ] : ");
            name = sc.nextLine();

            if (name.length() > 6 && name.length() < 21) break;
        }
        while (true) {
            System.out.print("Enter player position [ GK | CB | LB | RB | DMF | CMF |AMF | LWF | RWF | SS | CF ] : ");
            pos = sc.nextLine();

            if (pos.equals("GK") || pos.equals("CB") || pos.equals("LB") || pos.equals("RB") ||
                pos.equals("DMF") || pos.equals("AMF") || pos.equals("LWF") || pos.equals("SS") || pos.equals("CF")
            || pos.equals("CMF") || pos.equals("RWF"))
                    break;
        }
        while (true) {
            System.out.print("Enter player age [ 15 - 45 ] : ");
            age = sc.nextInt(); sc.nextLine();

            if (age > 14 && age < 46) break;
        }
        while (true) {
            System.out.print("Enter player nationality [ 7 - 20 characters ] : ");
            reg = sc.nextLine();

            if (reg.length() > 6 && reg.length() < 21) {
                break;
            }
        }
        Player sei = null;
        Random rand = new Random();
        switch (pos) {
            case "GK" :
                int att1 = rand.nextInt(59)+40;
                int att2 = rand.nextInt(59)+40;
                double rate = (att1*0.45) + (att2*0.55);
                sei = new Goalkeeper(name, reg, pos, num, age, 0, rate, att1, att2);
                break;
            case "CB" :
            case "LB" :
            case "RB" :
                 att1 = rand.nextInt(59)+40;
                 att2 = rand.nextInt(59)+40;
                 rate = (att1*0.75) + (att2*0.25);
                sei = new Defender(name, reg, pos, num, age, 0, rate, att1, att2);
                break;

            case "DMF" :
            case "CMF" :
            case "AMF" :
                 att1 = rand.nextInt(59)+40;
                 att2 = rand.nextInt(59)+40;
                 rate = (att1*0.50) + (att2*0.50);
                sei = new Midfielder(name, reg, pos, num, age, 0, rate, att1, att2);
                break;

            case "LWF" :
            case "RWF" :
            case "SS" :
            case "CF" :
                 att1 = rand.nextInt(59)+40;
                 att2 = rand.nextInt(59)+40;
                 rate = (att1*0.60) + (att2*0.40);
                sei = new Attacker(name, reg, pos, num, age, 0, rate, att1, att2);
                break;

        }

        System.out.printf("Player transfer fee: %f", sei.getOverallRating()*1000);
        System.out.printf("Team money: %d", owner.getMoney());
        players.add(sei);

    }
    public static void main(String[] args) {
        new Main();
    }
}