public class Attacker extends Player{

    private int finishing, power;

    public Attacker(String name, String nationality, String position, int shirtNumber, int age, int appearance, double overallRating, int finishing, int power) {
        super(name, nationality, position, shirtNumber, age, appearance, overallRating);
        this.finishing = finishing;
        this.power = power;
    }

    public int getFinishing() {
        return finishing;
    }

    public void setFinishing(int finishing) {
        this.finishing = finishing;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }
}
