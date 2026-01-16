import java.util.Scanner;

class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter tow integers");
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a > b) {
            System.out.println("Larger number is " + a);
        } else if (b > a) {
            System.out.println("Larger number is " + b);
        } else {
            System.out.println("The numbers are equal");
        }
        sc.close();
    }
}
