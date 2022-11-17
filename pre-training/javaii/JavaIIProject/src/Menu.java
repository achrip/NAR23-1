public class Menu extends Customer{

    private String food, drink;
    private int price;

    public Menu(int patience, String food, String drink, int price) {
        super(patience);
        this.food = food;
        this.drink = drink;
        this.price = price;
    }

    public String getFood() {
        return food;
    }

    public void setFood(String food) {
        this.food = food;
    }

    public String getDrink() {
        return drink;
    }

    public void setDrink(String drink) {
        this.drink = drink;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }
}
