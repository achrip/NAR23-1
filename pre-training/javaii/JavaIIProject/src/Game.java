public class Game implements Runnable{

    private Thread t;
    private int life = 5, time = 0;

    public int getLife() {
        return life;
    }

    public void setLife(int life) {
        this.life = life;
    }

    public int getTime() {
        return time;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public void init() {
        if (t == null)
            t = new Thread(this);
        t.start();
    }
    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(1000);
                setTime(getTime() + 1);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
