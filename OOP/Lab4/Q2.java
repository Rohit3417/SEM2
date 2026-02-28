package OOP.Lab4;

import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter password : ");
        String pass = sc.next();
        int len = pass.length(), temp = 0;
        if (len < 5 || len > 12) {
            System.out.println("Password not acceptable");
            temp = 1;
        }
        for (int j = 1; j < len; j++) {
            if (pass.charAt(j) == pass.charAt(j - 1)) {
                System.out.println("Password not acceptable");
                temp = 1;
                break;
            }
            if (pass.charAt(j - 1) < 'a' || pass.charAt(j - 1) > 'z') {
                System.out.println("Password not acceptable");
                temp = 1;
                break;
            }
            for (int i = 0; i < len; i++) {

                if (i != 0 && pass.charAt(j - 1) == pass.charAt(i)) {
                    int p = i;
                    temp = 1;
                    for (int k = j; k < i && p < len - 1; k++) {
                        if (pass.charAt(k) == pass.charAt(p + 1)) {
                            temp = 1;
                            System.out.println("Password not acceptable");
                            return;
                        }
                        p++;
                    }
                }

            }

            if (temp == 0) {
                System.out.println("Password acceptable");
            }

            sc.close();
        }
    }
}
