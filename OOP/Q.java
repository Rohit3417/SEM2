package OOP;

class A {
    void show() {
        System.out.println("A shows");
    }
}

class B extends A {
    void show(int i) {
        System.out.println("B shows" + i);
    }
}

public class Q {
    public static void main(String[] args) {
        A a = new A();
        a.show();
        // a.show(10); wrong
        B b = new B();
        b.show();
        b.show(10);
        A c = new B();
        c.show();
        // c.show(10); wrong
    }
}
