package OOP.Lab9;

import java.util.Random;

class Money {
    int balance = 600;
    boolean isGreat = false;
    boolean isLower = true;
}

class Father extends Thread {
    Money mon = null;

    Father(Money mon) {
        this.mon = mon;
    }

    public void run() {
        Random r = new Random();
        while (!mon.isLower) {
            try {
                mon.wait();
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
        System.out.println("Starting to deposit : ");
        while (mon.balance <= 2000) {
            mon.balance += r.nextInt(1, 200) + 1;
        }
        System.out.println("Balance > 2000 and = " + mon.balance);
        synchronized (mon) {
            mon.isGreat = true;
            mon.notify();
        }

    }
}

class Son extends Thread {
    Money mon = null;

    Son(Money mon) {
        this.mon = mon;
    }

    public void run() {
        Random r = new Random();
        while (!mon.isGreat) {
            synchronized (mon) {
                try {
                    mon.wait();
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }

        }

        System.out.println("Starting to withdraw : ");
        while (mon.balance >= 500) {
            mon.balance -= r.nextInt(1, 150) + 1;
        }
        System.out.println("Balance < 500 and value = " + mon.balance);
        synchronized (mon) {
            mon.isLower = false;
            mon.notify();
        }
    }
}

public class Q7 {
    public static void main(String[] args) {
        Money mon = new Money();

        Father f = new Father(mon);
        Son s = new Son(mon);

        f.start();
        s.start();

        try {
            f.join();
            s.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }

        System.out.println("Transfer of money completed");
    }
}
