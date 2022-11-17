public class Tred implements Runnable {
    private int counter;
    private Thread t;

    public Tred(int counter) {
        this.counter = counter;
    }

    public int getCounter() {
        return counter;
    }

    public void setCounter(int counter) {
        this.counter = counter;
    }

    @Override
    public void run() {

    }

    public void start() {
        if (t == null) {
            t = new Thread(this);
            t.start();
        }
    }
}
