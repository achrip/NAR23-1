import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Vector;

public class Drink extends Menu{
    private static List<Drink> drinks = Collections.synchronizedList(new Vector<>());
    private String drinkName;
    private int drinkPrice;

    public Drink(String s, int parseInt) {
        super();
        drinkName = s;
        drinkPrice = parseInt;
    }
    public Drink() {}

    public void populate() {
        try {
            BufferedReader br = new BufferedReader(new FileReader("src/drink.txt"));
            String s;
            while ((s = br.readLine()) != null) {
                String[] arr = s.split("#");
                drinks.add(new Drink(arr[0], Integer.parseInt(arr[2])));
            }
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getDrinkName() {
        return drinkName;
    }

    public int getDrinkPrice() {
        return drinkPrice;
    }

    public Drink getRandomDrink () {
        Random rand = new Random();
        return drinks.get(rand.nextInt(drinks.size()));
    }
}
