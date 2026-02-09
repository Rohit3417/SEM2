package OOP.CaseBase;

import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float v0, v1, t;
        System.out.println("Enter v0,v1 and time (t) : ");
        v0 = sc.nextFloat();
        v1 = sc.nextFloat();
        t = sc.nextFloat();
        System.out.println("The average acceleration is " + ((v1 - v0) / t));
        sc.close();
    }
}
