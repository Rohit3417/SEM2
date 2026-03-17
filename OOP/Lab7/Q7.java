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
        System.out.println("Question  Submitted Ans  Correct Ans  Result");
        System.out.println("-----------------------------------------------");
        for (int i = 0; i < 4; i++) {
            System.out.println((i + 1) + "\t\t" + SubAns.charAt(i) + "\t\t" + Ans.charAt(i) + "\t" + status[i]);
        }

        System.out.println("No. of Correct answers : " + correct);
        System.out.println("No. of Wrong answers : " + wrong);
        System.out.println("No. of Unattempted questions : " + Unattempted);
        if (correct >= 5) {
            System.out.println("Student passed the exam");
        }
        sc.close();

    }
}
