public class Drink extends Food{
    String size;

    public Drink(int price, int prepTime, String name, String type, String size) {
        super(price, prepTime, name, type);
        this.size = size;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }
}
