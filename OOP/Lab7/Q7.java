package OOP.Lab7;

import java.util.Scanner;

public class Q7 {
    public static void main(String[] args) {
        String Ans = "CABD";
        Scanner sc = new Scanner(System.in);
        String SubAns;
        String status[] = new String[4];
        System.out.println("Enter the submitted answers : ");
        SubAns = sc.next();
        int correct = 0, wrong = 0, Unattempted = 0;
        for (int i = 0; i < SubAns.length(); i++) {
            if (Ans.charAt(i) == SubAns.charAt(i)) {
                correct++;
                status[i] = "Correct";
            } else if (SubAns.charAt(i) == 'X') {
                Unattempted++;
                status[i] = "Unattempted";
            } else {
                wrong++;
                status[i] = "Wrong";
            }
        }

        sc.close();

    }
}
