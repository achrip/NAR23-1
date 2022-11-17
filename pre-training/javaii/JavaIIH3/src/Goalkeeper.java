public class Goalkeeper extends Player{

    int reflex, catchy;

    public Goalkeeper(String name, String nationality, String position, int shirtNumber, int age, int appearance, double overallRating, int reflex, int catchy) {
        super(name, nationality, position, shirtNumber, age, appearance, overallRating);
        this.reflex = reflex;
        this.catchy = catchy;
    }

    public int getReflex() {
        return reflex;
    }

    public void setReflex(int reflex) {
        this.reflex = reflex;
    }

    public int getCatchy() {
        return catchy;
    }

    public void setCatchy(int catchy) {
        this.catchy = catchy;
    }
}
