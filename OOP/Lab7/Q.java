package OOP.Lab7;

public class Q {
    enum Result {
        CORRECT,
        INCORRECT,
        NOT_ANSWERED
    }

    public static void main(String[] args) {

        char[] correctAnswers = { 'C', 'A', 'B', 'D' };
        int score = 0;

        for (int i = 0; i < correctAnswers.length; i++) {

            Result result;

            if (args[i].equalsIgnoreCase("X")) {
                result = Result.NOT_ANSWERED;
            } else if (args[i].charAt(0) == correctAnswers[i]) {
                result = Result.CORRECT;
                score++;
            } else {
                result = Result.INCORRECT;
            }

            System.out.println("Question " + (i + 1) + ": " + result);
        }

        System.out.println("Total Score: " + score);

        if (score >= 2) {
            System.out.println("Result: PASS");
        } else {
            System.out.println("Result: FAIL");
        }
    }
}
