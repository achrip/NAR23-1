import java.util.ArrayDeque;
import java.util.Random;

public class Customer implements Runnable{

    private int patience;
    private Thread t;
    private Game gem;
    private ArrayDeque<Customer> cust = new ArrayDeque<>();
    private Drink drinks = new Drink();
    private Food foods = new Food();
    private Random rand = new Random();
    

    public Customer() {}

    public Customer(int patience, Food food, Drink drink) {
    }

    public int getPatience() {
        return patience;
    }

    public Drink getDrinks() {
        return drinks;
    }

    public Food getFoods() {
        return foods;
    }

    @Override
    public void run() {
        gem = new Game();
        int count = 0;
        while (gem.getLife() != 0) {
            try {
                Thread.sleep(1001);
                if (count % 7 == 0) spawn();
                for(Customer c : cust) {
                    System.out.printf("%d, %s, %s\n", c.getPatience(), c.getFoods().getFoodName(), c.getDrinks().getDrinkName());
                }
                count++;
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void init() {
        if (t == null) t = new Thread(this);
        foods.populate();
        drinks.populate();
        t.start();
    }

    public void spawn() {
        patience = 10;
        cust.add(new Customer(patience, foods.getRandomFood(), drinks.getRandomDrink()));
    }
}