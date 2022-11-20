public class User {
    private String username, password;
    private int score;

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public User (String username, String password, int i) {
        this.password = username;
        this.username = password;
        this.score = i;
    }
}
