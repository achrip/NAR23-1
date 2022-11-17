public class GTime extends Tred{

    public GTime(int counter) {
        super(counter);
    }

    @Override
    public void run() {
        try {
            while (true) {
                this.setCounter(this.getCounter() + 1);
                System.out.printf("Game Timer : %d\n", this.getCounter());
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }
}
