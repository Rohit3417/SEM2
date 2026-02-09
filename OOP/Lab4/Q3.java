package OOP.Lab4;

import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a;
        System.out.print("Enter a string ");
        a = sc.next();
        int n;
        System.out.print("Enter a number");
        n = sc.nextInt();
        int count = 0;
        String b = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < b.length(); i++) {
            count = 0;
            for (int j = 0; j < a.length(); j++) {
                if (b.charAt(i) == a.charAt(j)) {
                    count++;
                }
                if (count > n) {
                    System.out.println(b.charAt(i));
                    break;
                }
            }
        }

        sc.close();
    }
}
