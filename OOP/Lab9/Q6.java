package OOP.Lab9;

class Control {
    boolean primeDone = false;
    boolean fibPaused = false;
}

class Prime extends Thread {
    Control control;

    Prime(Control control) {
        this.control = control;
        setName("PrimeThread");
        setPriority(5);
    }

    boolean isPrime(int data) {
        for (int i = 2; i < data; i++) {
            if (data % i == 0)
                return false;

        }
        return true;
    }

    public void run() {
        // wait till fib thread is not paused
        synchronized (control) {
            while (!control.fibPaused) {
                try {
                    control.wait();
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }
        System.out.println("Starting prime number counting ...");
        int count = 0, i = 2;
        while (count <= 25) {
            if (isPrime(i)) {
                System.out.println(i + " ");
                count++;
            }
            i++;

        }
        System.out.println("[" + getName() + "] Done computing 25 primes.");

        // Notify FibThread to resume
        synchronized (control) {
            control.primeDone = true;
            control.notify();
        }
    }
}

class Fib extends Thread {
    Control control;

    Fib(Control control) {
        this.control = control;
        setName("FibThread");
        setPriority(8);
    }

    public void run() {
        int f1 = 0;
        int f2 = 1;
        int temp = f1;
        while (f1 <= 50) {
            System.out.println(f1);
            temp = f1;
            f1 = f2;
            f2 = f2 + temp;
        }
        System.out.println("Phase 1 done");
        synchronized (control) {
            control.fibPaused = true;
            control.notify();
        }

        synchronized (control) {
            while (!control.primeDone) {
                try {
                    control.wait(); // sleep until prime is done
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }

        while (f1 <= 100) {
            System.out.println(f1);
            f1 = f2;
            f2 = f2 + f1;
        }
        System.out.println("Phase 2 done ");
    }
}

public class Q6 {
    public static void main(String[] args) {
        Control control = new Control();

        Fib f1 = new Fib(control);
        Prime p1 = new Prime(control);

        f1.start();
        p1.start();

        try {
            f1.join();
            p1.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }

        System.out.println("All phases done");
    }
}
