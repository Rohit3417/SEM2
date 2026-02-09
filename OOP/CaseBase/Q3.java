package OOP.CaseBase;

import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float v, a;
        System.out.print("Enter speed and acceleration : ");
        v = sc.nextFloat();
        a = sc.nextFloat();
        System.out.print("The minimum runway length is " + ((v * v) / (2 * a)));
        sc.close();
    }
}
