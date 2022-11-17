public class Defender extends Player{

    int lowPass, loftPass;

    public Defender(String name, String nationality, String position, int shirtNumber, int age, int appearance, double overallRating, int lowPass, int loftPass) {
        super(name, nationality, position, shirtNumber, age, appearance, overallRating);
        this.lowPass = lowPass;
        this.loftPass = loftPass;
    }

    public int getLowPass() {
        return lowPass;
    }

    public void setLowPass(int lowPass) {
        this.lowPass = lowPass;
    }

    public int getLoftPass() {
        return loftPass;
    }

    public void setLoftPass(int loftPass) {
        this.loftPass = loftPass;
    }
}
