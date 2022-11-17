public class Game implements Runnable{

    private Thread t;
    private int life, time;

    public void init() {
        if (t == null)
            t = new Thread(this);
        t.start();
    }
    @Override
    public void run() {}
}
