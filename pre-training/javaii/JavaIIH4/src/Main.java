import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class Main {
    private Scanner sc;
    private Tred custMood, gameTimer, driver, fewd;
    private ArrayList<Food> menu = new ArrayList<>();
    public Main() {
        sc = new Scanner(System.in) ;
       while (true) {
           System.out.println("""
                                   
                               ___  ________  ___  ___  ________  ________  ___  ________ ________  ________  ________
                              |\\  \\|\\   ____\\|\\  \\|\\  \\|\\   __  \\|\\   __  \\|\\  \\|\\  _____\\\\   __  \\|\\   __  \\|\\   ___ \\
                              \\ \\  \\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\ \\  \\__/\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\_|\\ \\
                            __ \\ \\  \\ \\_____  \\ \\   __  \\ \\  \\\\\\  \\ \\   ____\\ \\  \\ \\   __\\\\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ \\\\ \\
                           |\\  \\\\_\\  \\|____|\\  \\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\___|\\ \\  \\ \\  \\_| \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\_\\\\ \\
                           \\ \\________\\____\\_\\  \\ \\__\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\   \\ \\_______\\ \\_______\\ \\_______\\
                            \\|________|\\_________\\|__|\\|__|\\|_______|\\|__|     \\|__|\\|__|    \\|_______|\\|_______|\\|_______|
                                      \\|_________|
                                   
                                   
                           [S] Start Game          [Q] Quit
                   """);
           System.out.print("        >> ");
           char choose = 0;
           try {
               choose = sc.next().charAt(0);
           } catch (InputMismatchException e) {
               continue;
           } finally {
               switch (choose) {
                   case 's':
                   case 'S':
                       game();
                       break;
                   case 'q':
                   case 'Q':
                       System.exit(0);
                   default:
                       break;
               }
           }
       }
    }

    private void game() {
        Random rand = new Random();
        gameTimer = new GTime(0);
        custMood = new CCO((rand.nextInt(10)+50), "cust", this);
        driver = new CCO(0, "bang", this);
        fewd = new CCO(0, "nyam", this);

        try {
            BufferedReader br = new BufferedReader(new FileReader("src/source.txt"));
            String s;
            while ((s = br.readLine()) != null) {
                String[] arr = s.split("#");
                switch (arr[0]) {
                    case "food":
                        if (Integer.parseInt(arr[5]) == 1)
                            menu.add(new Dish(Integer.parseInt(arr[2]), Integer.parseInt(arr[3]), arr[1], arr[0], "Yes", arr[4]));
                        else
                            menu.add(new Dish(Integer.parseInt(arr[2]), Integer.parseInt(arr[3]), arr[1], arr[0], "No", arr[4]));

                    case "dessert":
                        if (Integer.parseInt(arr[4]) == 1)
                            menu.add(new Dessert(Integer.parseInt(arr[2]), Integer.parseInt(arr[3]), arr[1], arr[0], "Yes"));
                        else
                            menu.add(new Dessert(Integer.parseInt(arr[2]), Integer.parseInt(arr[3]), arr[1], arr[0], "No"));
                    case "beverage":
                        menu.add(new Drink(Integer.parseInt(arr[2]), Integer.parseInt(arr[3]), arr[1], arr[0], String.valueOf(arr[4])));

                }
            }

        } catch (FileNotFoundException e) {
            System.out.println("No Data!");
            sc.nextLine();
            return;
        } catch (IOException e) {
            System.out.println("You have nothing to sell!");
            sc.nextLine();
            return;
        }
        gameTimer.start();
        System.out.println("[P] Prepare Food\t [A] Assign Courier\t [E] Exit Game");
        System.out.print(">> ");
        char choose = 0;
        try {
            choose = sc.next().charAt(0);
        } catch (InputMismatchException e) {
//            continue;
        }

        switch (choose) {
            case 'p':
            case 'P':
                prep();
                break;
            case 'a':
            case 'A':
                break;
            case 'e':
            case 'E':
                return;
            default:
                break;
            }
    }

    private void prep() {
        System.out.println("""
                Prepare Orders
                -------------------------------------
                1. Food
                2. Beverage
                3. Dessert
                
                [0] Back""");
        System.out.printf(">> ");
        int choose = 0, index = 0;
        try {
            choose = sc.nextInt();
            sc.nextLine();
        } catch (InputMismatchException e) {
//            continue;
        }

        switch (choose) {
            case '1':
                for (Food f : menu){
                    if (f instanceof Dish) {
                        Dish s = (Dish) f;
                        System.out.println("Food Menu");
                        System.out.printf("%d   %-50s| IDR %-40d| %-40s| %-30s", (index + 1),
                                s.getName(), s.getPrice(), s.getOrigin(), s.getState());
                        index++;
                    }
                }
                break;
            case '2':
                for (Food f : menu){
                    if (f instanceof Drink) {
                        Drink s = (Drink) f;
                        System.out.println("Beverage Menu");
                        System.out.printf("%d   %-50s| IDR %-40d| %-30s", (index + 1),
                                s.getName(), s.getPrice(), s.getSize());
                        index++;
                    }
                }
                break;
            case '3':
                for (Food f : menu){
                    if (f instanceof Dessert) {
                        Dessert s = (Dessert) f;
                        System.out.println("Dessert Menu");
                        System.out.printf("%d   %-50s| IDR %-40d| %-30s", (index + 1),
                                s.getName(), s.getPrice(), s.getHighCal());
                        index++;
                    }
                }

            case '0':
                return;
            default:
                break;
        }
    }

    public void failed() {}
    public static void main(String[] args) {
        new Main();
    }
}