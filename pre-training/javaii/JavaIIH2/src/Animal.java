public class Animal extends Habitat {
    private String kind, size;

    public Animal(String terrain, String kind, String size) {
        super(terrain);
        this.kind = kind;
        this.size = size;
    }

    public String getKind() {
        return kind;
    }

    public void setKind(String kind) {
        this.kind = kind;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }
}
