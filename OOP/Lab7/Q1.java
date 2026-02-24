package OOP.Lab7;

import java.util.Scanner;

class Calculate {
    static float interest(int principle, float rate, float years) {
        float amount;
        amount = principle * (rate / 100) * years;
        return amount;
    }
}

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int principle;
        float rate, years;
        System.out.print("Enter principle amount : ");
        principle = sc.nextInt();
        System.out.print("Enter annual rate in %: ");
        rate = sc.nextFloat();
        System.out.print("Enter number of years : ");
        years = sc.nextFloat();
        System.out.print("Simple interest in this time is " + Calculate.interest(principle, rate, years));
        sc.close();
    }
}
