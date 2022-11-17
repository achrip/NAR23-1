public class Type extends Animal{
    private String name, species;
    private int food;

    public Type(String terrain, String kind, String size, String name, int food, String species) {
        super(terrain, kind, size);
        this.name = name;
        this.species = species;
        this.food = food;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFood() {
        return food;
    }

    public void setFood(int food) {
        this.food = food;
    }

    public String getSpecies() {
        return species;
    }

    public void setSpecies(String species) {
        this.species = species;
    }
}
