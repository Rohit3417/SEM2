import java.util.Scanner; //java.util is a package

class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two integers");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("Sum is " + (a + b));
        System.out.println("Difference is " + (a - b));
        System.out.println("Product is " + (a * b));
        System.out.println("Quotient is " + (a / b));
        sc.close();
    }
}
