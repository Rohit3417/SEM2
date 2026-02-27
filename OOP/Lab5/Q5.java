package OOP.Lab5;

//tax rate = 15 %
import java.util.Scanner;

class Calculate {
    int hrsWorked;
    float grossPay;

    float set() {
        grossPay = 12 * hrsWorked;
        return grossPay;
    }

    float tax, netpay;

    float calculateTax() {
        tax = 0.15f * grossPay;
        return tax;
    }

    float calculateNetPay() {
        netpay = grossPay - tax;
        return netpay;
    }
}

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Calculate employee = new Calculate();
        System.out.print("Enter the number of hours an emplyeed worked : ");
        employee.hrsWorked = sc.nextInt();
        employee.set();
        System.out.println("Tax paid by the employee : " + employee.calculateTax());
        System.out.println("Netpay paid to the employee : " + employee.calculateNetPay());
        sc.close();
    }
}
