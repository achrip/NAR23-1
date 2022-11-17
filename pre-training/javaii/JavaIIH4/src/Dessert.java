public class Dessert extends Food{
    String highCal;

    public Dessert(int price, int prepTime, String name, String type, String highCal) {
        super(price, prepTime, name, type);
        this.highCal = highCal;
    }

    public String getHighCal() {
        return highCal;
    }

    public void setHighCal(String highCal) {
        this.highCal = highCal;
    }
}
