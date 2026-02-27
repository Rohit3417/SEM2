package OOP.Lab5;

class Fruit {
    String name;
    int num;
    float price;

    Fruit(String name, int num, float price) {
        this.name = name;
        this.num = num;
        this.price = price;
    }

    void displayFruit() {
        System.out.println("Name of fruit is : " + name);
        if (num == 1) {
            System.out.println("It is a single fruit");
        } else {
            System.out.println("Bunch of fruits");
        }
        System.out.println("Price of this fruit is : " + price);
    }
}

public class Q4 {
    public static void main(String[] args) {
        Fruit F1 = new Fruit("Guava", 1, 30);
        Fruit F2 = new Fruit("Grapes", 20, 50);
        System.out.println("First fruit is : ");
        F1.displayFruit();
        System.out.println();
        System.out.println("Second fruit is : ");
        F2.displayFruit();

    }
}
