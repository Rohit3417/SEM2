package OOP.Lab9;

class MyRunnable implements Runnable {
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }
    }
}

public class Q2 {
    public static void main(String[] args) {
        MyRunnable r1 = new MyRunnable();
        Thread t1 = new Thread(r1); // As for registration of the the method
                                    // In runnable interface only run method is present
        t1.start();
    }
}
