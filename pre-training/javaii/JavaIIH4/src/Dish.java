public class Dish extends Food{
    String state;
    String origin;

    public Dish(int price, int prepTime, String name, String type, String state, String origin) {
        super(price, prepTime, name, type);
        this.state = state;
        this.origin = origin;
    }

    public String getOrigin() {
        return origin;
    }

    public void setOrigin(String origin) {
        this.origin = origin;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }
}
