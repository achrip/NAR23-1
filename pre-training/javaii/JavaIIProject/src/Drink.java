import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;

public class Drink extends Menu{
    private Vector<String> name = new Vector<>();
    private Vector<Integer> price = new Vector<>();
    public void fPopulate() {
        try {
            BufferedReader br = new BufferedReader(new FileReader("src/drinks.txt"));
            String s;
            int index = 0;
            while ((s = br.readLine()) != null) {
                String[] arr = s.split("#");
                name.add(arr[0]);
                price.add(Integer.parseInt(arr[2]));
            }
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
