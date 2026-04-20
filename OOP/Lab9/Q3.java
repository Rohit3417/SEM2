package OOP.Lab9;

import java.util.Scanner;

class sinSeries extends Thread {
    double x;
    int terms;

    int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; i++) {
            result = result * i;
        }
        return result;
    }

    public sinSeries(double x, int terms) {
        this.x = x;
        this.terms = terms;
    }

    public void run() {
        double result = 0;
        for (int i = 0; i < terms; i++) {
            int exp = 2 * i + 1;
            double term = Math.pow(x, exp) / factorial(exp);
            result += (i % 2 == 0) ? term : -term;
        }
        System.out.println("[SinThread]  Finished computing sin(" + x + ") = " + result);
    }
}

class cosSeries extends Thread {
    double x;
    int terms;

    int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; i++) {
            result = result * i;
        }
        return result;
    }

    public cosSeries(double x, int terms) {
        this.x = x;
        this.terms = terms;
    }

    public void run() {
        double result = 0;
        for (int i = 0; i < terms; i++) {
            int exp = 2 * i;
            double term = Math.pow(x, exp) / factorial(exp);
            result += (i % 2 == 0) ? term : -term;
        }
        System.out.println("[CosThread]  Finished computing cos(" + x + ") = " + result);
    }
}

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x (in radians) : ");
        double x = sc.nextDouble();
        System.out.print("Enter number of terms: ");
        int terms = sc.nextInt();

        sinSeries sinThread = new sinSeries(x, terms);
        cosSeries cosThread = new cosSeries(x, terms);

        sinThread.start();
        cosThread.start();

        sc.close();
    }
}
