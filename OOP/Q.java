package OOP;

interface car {
    int wheels = 4;

    void show();
}

class Vehicle implements car {
    public void show() {
        System.out.println("it is a car");
    }
}

class Main {
    public static void main(String[] args) {
        Vehicle a = new Vehicle();
        a.show();
        System.out.println(a.wheels);

    }
}