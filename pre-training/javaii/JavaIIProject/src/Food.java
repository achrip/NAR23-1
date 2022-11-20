import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Vector;

public class Food extends Menu{
    private Vector<Food> foods = new Vector<>();
    private String foodName;
    private int foodPrice;

    public Food(String s, int parseInt) {
        super();
        foodName = s;
        foodPrice = parseInt;
    }
    public Food() {}

    public void populate() {
        try {
            BufferedReader br = new BufferedReader(new FileReader("src/food.txt"));
            String s;
            int i = 0;
            while ((s = br.readLine()) != null) {
                String[] arr = s.split("#");
                foods.add(new Food(arr[0], Integer.parseInt(arr[2])));
                System.out.println(foods.size());
            }
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getFoodName() {
        return foodName;
    }

    public int getFoodPrice() {
        return foodPrice;
    }

    public Food getRandomFood() {
        Random rand = new Random();
        return foods.get(rand.nextInt(foods.size()));
    }

}
