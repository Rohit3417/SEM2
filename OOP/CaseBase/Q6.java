package OOP.CaseBase;

import java.util.Scanner;

public class Q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= 8 - i; j++) {
                System.out.printf("%3s ", " ");
            }
            for (int j = 1; j <= i; j++) {
                // System.out.print(((int) Math.pow(2, j - 1)) + " ");
                System.out.printf("%3d ", (int) Math.pow(2, j - 1));
            }
            for (int j = i - 2; j >= 0 && i != 1; j--) {
                System.out.printf("%3d ", (int) Math.pow(2, j));
            }
            System.out.print("\n");
        }
    }
}
