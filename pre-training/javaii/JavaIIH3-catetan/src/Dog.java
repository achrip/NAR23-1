public class Dog extends Animal implements carMammals{

    private String fur;
    public Dog(String name, String fur) {
        super(name);
        this.fur = fur;
    }

    public String getFur() {
        return fur;
    }

    public void setFur(String fur) {
        this.fur = fur;
    }

    @Override
    public void eat() {
        System.out.println("ChompChomp >////<");
    }
    @Override
    public void eat(String food, int age){
        System.out.println(this.getName() + " is eating a " + food);
    }

    @Override
    void move(){
        System.out.println(this.getName() + " is zooming....");
    }

    @Override
    public void giveBirth() {
        System.out.println(this.getName() + " is having kids...? in " + this.birthDuration + " minutes");
    }

    @Override
    public void eatMeat(){
        System.out.println(this.getName() + " is eating a meat");
    }

    @Override
    public void fangs(String s){
        System.out.println(this.getName() + " bares its fangs against you!");
    }
}
