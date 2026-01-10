import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter three integers");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        System.out.println("Sum of the integers is " + (a + b + c));
        System.out.println("Average of the integers is " + (a + b + c) / 3);
        System.out.println("Product of the integers is " + (a * b * c));
        if (a > b && a > c) {
            System.out.println("Integer:A is largest");
            if (b > c) {
                System.out.println("Integer:C is smallest");
            } else {
                System.out.println("Integer:B is largest");
            }

        } else if (b > a && b > c) {
            System.out.println("Integer:B is largest");
            if (a > c) {
                System.out.println("Integer:C is smallest");
            } else {
                System.out.println("Integer:A is smallest");
            }

        } else if (c > a && c > b) {
            System.out.println("Integer:C is largest");
            if (a > b) {
                System.out.println("Integer:B is smallest");
            } else {
                System.out.println("Integer:A is smallest");
            }
        }
    }
}
