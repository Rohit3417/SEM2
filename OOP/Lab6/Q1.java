package OOP.Lab6;

class A {
    int a;

    A() {
        this(10);
        System.out.println("Default Constructor A");
    }

    A(int a) {
        // Default super() calls Object(the super class of all)
        System.out.println("A = " + a);
    }
}

class B extends A {
    int b;

    B() {
        this(20);
        System.out.println("Defalut constructor B");
    }

    B(int b) {
        // Default super() will call A class constructor
        System.out.println("B = " + b);
    }
}

public class Q1 {
    public static void main(String[] args) {
        B object = new B();
    }

}
