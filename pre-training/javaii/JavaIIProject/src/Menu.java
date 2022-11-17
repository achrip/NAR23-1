public abstract class Menu extends Customer{

    private String food, drink;
    private int price;
    private boolean isDone;

    public Menu(int patience, String food, String drink, int price) {
        super(patience);
        this.food = food;
        this.drink = drink;
        this.price = price;
        isDone = false;
    }

    public String getFood() {
        return food;
    }

    public boolean isDone() {
        return isDone;
    }

    public void setDone(boolean done) {
        isDone = done;
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
