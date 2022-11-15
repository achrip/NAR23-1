public class Owner extends Farm{
    private int money, land, freshWater, saltWater;

    public Owner(int lv, int money, int land, int freshWater, int saltWater) {
        super(lv);
        this.money = money;
        this.land = land;
        this.freshWater = freshWater;
        this.saltWater = saltWater;
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public int getLand() {
        return land;
    }

    public void setLand(int land) {
        this.land = land;
    }

    public int getFreshWater() {
        return freshWater;
    }

    public void setFreshWater(int freshWater) {
        this.freshWater = freshWater;
    }

    public int getSaltWater() {
        return saltWater;
    }

    public void setSaltWater(int saltWater) {
        this.saltWater = saltWater;
    }
}
