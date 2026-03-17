package OOP.Lab5;

import java.util.Scanner;

public class Q7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] arr = new String[8];
        int correct = 0, wrong = 0, Unattempted = 0;
        String UserAns;
        String Ans = "CABDBCCA";
        System.out.println("Enter the submitted answers : ");
        UserAns = sc.nextLine();

        for (int i = 0; i < 8; i++) {
            if (UserAns.charAt(i) == Ans.charAt(i)) {
                correct++;
                arr[i] = "Correct";
            } else if (UserAns.charAt(i) == 'X') {
                Unattempted++;
                arr[i] = "Unattempted";
            } else {
                wrong++;
                arr[i] = "Wrong";
            }

        }

        System.out.println("Question  Submitted Ans  Correct Ans  Result");
        System.out.println("-----------------------------------------------");
        for (int i = 0; i < 8; i++) {
            System.out.println((i + 1) + "\t\t" + UserAns.charAt(i) + "\t\t" + Ans.charAt(i) + "\t" + arr[i]);
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
