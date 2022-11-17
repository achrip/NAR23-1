public class Main {
    public Main() {
//        Animal animalA = new Animal("ardog");
//        System.out.println("Name: " + animalA.getName());
//        animalA.eat();
//        animalA.eat(animalA.getName());

        Dog doggo = new Dog("Brian", "white");
        System.out.println("Name: " + doggo.getName());
        System.out.println("Fur: " + doggo.getFur());
        doggo.eat(doggo.getName());
        doggo.eat("Bone", 5);
    }
    public static void main(String[] args) {
        new Main();
    }
}