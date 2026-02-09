package OOP.Lab4;

import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b;
        System.out.print("Enter Range : ");
        a = sc.nextInt();
        b = sc.nextInt();
        int patt, i = 0, count = 0;
        System.out.println("Enter Pattern");
        patt = sc.nextInt();
        String[] temp = new String[b - a + 1];
        for (int j = a; j <= b; j++) {
            temp[i] = String.valueOf(j);
            i++;
        }
        String substr = String.valueOf(patt);

        for (int k = 0; k < temp.length; k++) {
            if (temp[k].indexOf(substr) != -1) {
                count++;
            }
        }
        System.out.println(count);

        sc.close();
    }
}
