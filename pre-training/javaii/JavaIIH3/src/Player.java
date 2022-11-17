public class Player {
    private String name, nationality, position;
    private int shirtNumber, age, appearance, att1, att2;
    private double overallRating;

    public Player(String name, String nationality, String position, int shirtNumber, int age, int appearance, double overallRating) {
        this.name = name;
        this.nationality = nationality;
        this.position = position;
        this.shirtNumber = shirtNumber;
        this.age = age;
        this.appearance = appearance;
        this.overallRating = overallRating;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNationality() {
        return nationality;
    }

    public void setNationality(String nationality) {
        this.nationality = nationality;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public int getShirtNumber() {
        return shirtNumber;
    }

    public void setShirtNumber(int shirtNumber) {
        this.shirtNumber = shirtNumber;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAppearance() {
        return appearance;
    }

    public void setAppearance(int appearance) {
        this.appearance = appearance;
    }

    public double getOverallRating() {
        return overallRating;
    }

    public void setOverallRating(double overallRating) {
        this.overallRating = overallRating;
    }
}
