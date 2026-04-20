package OOP.Lab9;

class ThreadDemo extends Thread {
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(getName() + i);
        }
    }
}

public class Q1 {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getName() + i);
        }

        ThreadDemo o = new ThreadDemo();
        o.start();
    }
}
