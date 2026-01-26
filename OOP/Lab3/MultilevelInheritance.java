package OOP.Lab3;

class X {
    int i, j;

    X() {

    }

    X(int i, int j) {
        this.i = i;
        this.j = j;
    }

    int findSum() {
        return i + j;
    }
}

class Y extends X {
    Y() {

    }

    Y(int i, int j) {
        this.i = i;
        this.j = j;
    }

    int findProduct() {
        return i * j;
    }
}

class Z extends Y {
    Z(int i, int j) {
        this.i = i;
        this.j = j;
    }
}

public class MultilevelInheritance {
    public static void main(String[] args) {
        Z value1 = new Z(2, 3);
        int result = value1.findSum();
        System.out.println("Sum is " + result);
        int result2 = value1.findProduct();
        System.out.println("Product is " + result2);
    }
}
