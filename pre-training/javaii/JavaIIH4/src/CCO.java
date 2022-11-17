public class CCO extends Tred{
    private String threadName;
    private Main master;

    public CCO(int counter, String threadName, Main main) {
        super(counter);
        this.threadName = threadName;
        this.master = main;
    }

    public String getThreadName() {
        return threadName;
    }

    public void setThreadName(String threadName) {
        this.threadName = threadName;
    }

    @Override
    public void run() {
        try {
            this.setCounter(this.getCounter() - 1);
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        switch (this.getThreadName()) {
            case "cust":
                if (this.getCounter() == 0) {
                    master.failed();
                } break;
            case "bang":
                if (this.getCounter() == 0) {

                }
            case "nyam":
                if (this.getCounter() == 0) {

                }
        }
    }
}
