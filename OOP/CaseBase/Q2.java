package OOP.CaseBase;

import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float M, T1, T0;
        System.out.print("Enter Mass of water in kilograms : ");
        M = sc.nextFloat();
        System.out.print("Enter final temperature of water : ");
        T1 = sc.nextFloat();
        System.out.print("Enter initial temperature of water : ");
        T0 = sc.nextFloat();
        System.out.print("The energy needed is " + (M * (T1 - T0) * 4184));
        sc.close();
    }
}
