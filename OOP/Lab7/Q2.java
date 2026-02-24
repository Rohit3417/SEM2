package OOP.Lab7;

class Vehicle {
    int wheels;

    Vehicle() {
        System.out.println("Super class called");
    }
}

class Car extends Vehicle {
    Car(int wheels) {
        super();
        this.wheels = wheels;
        System.out.println("Car object created");
    }

    void maxSpeed() {
        System.out.println("Car runs at 100kmph");
    }
}

class Bicycle extends Vehicle {
    Bicycle(int wheels) {
        super();
        this.wheels = wheels;
        System.out.println("Bicycle object created");
    }

    void maxSpeed() {
        System.out.println("Bicycle runs at 20kmph");
    }
}

class Scooter extends Vehicle {
    Scooter(int wheels) {
        super();
        this.wheels = wheels;
        System.out.println("Scooter object created");
    }

    void maxSpeed() {
        System.out.println("Scooter runs at 50kmph");
    }
}

public class Q2 {
    public static void main(String[] args) {
        Car c = new Car(4);
        System.out.println();
        Bicycle b = new Bicycle(2);
        System.out.println();
        Scooter s = new Scooter(2);
        System.out.println();
        System.out.println("Car has " + c.wheels + " wheels");
        System.out.println("Bicycle has " + b.wheels + " wheels");
        System.out.println("Scooter has " + s.wheels + " wheels");
        System.out.println();
        c.maxSpeed();
        b.maxSpeed();
        s.maxSpeed();

    }
}
