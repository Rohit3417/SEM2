package OOP.Lab6;

abstract class Car {
    int i = 4;

    void wheels() {
        System.out.println("Number of wheels : " + i);
    }

    abstract void avg();

    abstract void mode();
}

class Maruti extends Car {
    void avg() {
        System.out.println("Average of Maruti cars : 19-26 kmpl");
    }

    void mode() {
        System.out.println("Sports mode\n");
    }
}

class Santro extends Car {
    void avg() {
        System.out.println("Average of Santro : 20-29 kmpl");
    }

    void mode() {
        System.out.println("Eco mode");
    }
}

public class Q4 {
    public static void main(String[] args) {
        Car car1 = new Maruti();
        Car car2 = new Santro();
        System.out.println("For Maruti cars:");

        car1.wheels();
        car1.avg();
        car1.mode();
        System.out.println("For Santro:");
        car2.wheels();
        car2.avg();
        car2.mode();

    }
}
