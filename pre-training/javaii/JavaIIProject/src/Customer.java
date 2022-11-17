public class Customer implements Runnable{

    private Thread t;
    private int patience;

    public Customer(int patience) {
        this.patience = patience;
    }

    public int getPatience() {
        return patience;
    }

    public void setPatience(int patience) {
        this.patience = patience;
    }

    @Override
    public void run() {
        while (patience != 0) {
            try {
                System.out.print("[");
                for (int i = 0; i < patience; i++)
                    System.out.print("#");
                System.out.print("]");
                Thread.sleep(1000);
                patience--;
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    public void countdown() {
        if (t == null)
            t = new Thread(this);
        patience = 10;
        t.start();

    }
}
