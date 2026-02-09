package OOP.Lab4;

import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        System.out.println("Enter your String");
        str = sc.nextLine();
        int temp = 0;
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                if (str.charAt(i) == str.charAt(j)) {
                    temp = 1;
                    break;
                }
            }
            if (temp == 1)
                break;
        }
        if (temp == 0) {
            System.out.println("Entered String is a perfect String");
        } else {
            System.out.println("Entered string is not a perfect String");
        }
        sc.close();
    }
}
