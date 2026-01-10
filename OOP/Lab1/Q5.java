import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a 5 digit number");
        int num = sc.nextInt(), sum = 0;
        while (num != 0) {
            sum = sum * 10 + num % 10;
            num /= 10;
        }
        while (sum != 0) {
            System.out.print(" " + (sum % 10));
            sum /= 10;
        }
    }
}
