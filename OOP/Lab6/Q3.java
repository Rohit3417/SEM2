package OOP.Lab6;

class WashingMachine {
    void SwitchOn() {
        System.out.println("Washing Machine was switched ON");
    }

    int acceptClothes(int n) {
        return n;
    }

    void acceptDetergent() {
        System.out.println("Detergent poured");
    }

    void SwitchOff() {
        System.out.println("Washing Machine was switched Off");
    }
}

public class Q3 {
    public static void main(String[] args) {
        WashingMachine object = new WashingMachine();
        object.SwitchOn();
        object.acceptDetergent();
        object.SwitchOff();
        System.out.println("No. of clothes washed = " + object.acceptClothes(10));
    }
}
