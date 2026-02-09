package OOP.CaseBase;

import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double weight, height;
        System.out.print("Enter weight in pounds : ");
        weight = sc.nextDouble();
        System.out.print("Enter height in inches : ");
        height = sc.nextDouble();
        Double BMI = ((weight * 0.45359237) / ((height * 0.0254) * (height * 0.0254)));
        System.out.print("BMI is " + BMI);
        sc.close();
    }
}
