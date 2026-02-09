package OOP.CaseBase;

import java.util.Random;

public class Q7 {
    public static void main(String[] args) {
        Random rand = new Random();
        double x, y;
        double count = 0;
        for (int i = 0; i < 1000000; i++) {
            x = rand.nextDouble(-1, 1);
            y = rand.nextDouble(-1, 1);

            if (x >= -1 && x <= 0 && y >= -1 && y <= 1 || x >= 0 && y >= 0 && (x + y) <= 1) {
                count++;
            }

        }
        System.out.println(count);
        System.out.println("Probability is : " + count / 1000000);

    }
}
