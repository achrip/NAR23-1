import java.util.Scanner;

public class Main {
    Scanner sc = new Scanner(System.in);
    public Main(){

        System.out.println("""
                1. Login
                2. Register
                3. Exit""");
        System.out.print(">> ");
        int choose = sc.nextInt();
                    sc.nextLine();
        switch (choose) {
            case 1 -> login();
            case 2 -> register();
            case 3 -> quit();
            default -> {}
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}