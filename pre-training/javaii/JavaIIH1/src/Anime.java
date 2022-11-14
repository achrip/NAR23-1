public class Anime {
    private String id, title, description, genre;
    private double rating;
    private int episode;

    public String getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public double getRating() {
        return rating;
    }

    public void setRating(double rating) {
        this.rating = rating;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getGenre() {
        return genre;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public int getEpisode() {
        return episode;
    }

    public void setEpisode(int episode) {
        this.episode = episode;
    }

    public Anime(String id, double rating, String title, String description, String genre, int episode) {
        this.id = id;
        this.title = title;
        this.rating = rating;
        this.description = description;
        this.genre = genre;
        this.episode = episode;
    }
}
