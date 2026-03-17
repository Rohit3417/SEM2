package OOP.Lab2;

import java.util.Scanner;

class Infor {
    float miles;
    int gasMeasure;
}

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Infor trip = new Infor();
        int choice = 1;
        float sum = 0, temp;
        while (choice != 0) {
            System.out.println("Enter miles drove for this trip");
            trip.miles = sc.nextInt();
            System.out.println("Enter in gallons petrol used");
            trip.gasMeasure = sc.nextInt();
            temp = trip.miles / trip.gasMeasure;
            System.out.println("miles per gallons for this trip is " + temp);
            sum += temp;
            System.out.println("Do you want to enter more info(1:continue,0;end)");
            choice = sc.nextInt();
        }
        System.out.println("Total gasMeasure is " + sum);
        sc.close();
    }
}
