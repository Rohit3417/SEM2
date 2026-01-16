package OOP.Lab2;

import java.util.Scanner;

public class Q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter account number");
        int accNum = sc.nextInt();
        System.out.println("Enter Balance at the beginning of month");
        float balance = sc.nextFloat();
        System.out.println("Enter net charges applied this month");
        float charges = sc.nextFloat();
        System.out.println("Enter credits earned"); // Credits = money that decreases what the customer owes
        int credits = sc.nextInt();
        System.out.println("Enter credit card limit");
        float limit = sc.nextFloat();

        float newBalance = balance + charges - credits;

        System.out.println("For the person holding Acc:" + accNum);
        if (newBalance > limit) {
            System.out.println("Limit is exceeded by " + (newBalance - limit));
        } else {
            System.out.println("Limit not exceeded");
        }
        sc.close();
    }
}
