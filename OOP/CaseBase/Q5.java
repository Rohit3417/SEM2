package OOP.CaseBase;

import java.util.Scanner;

class Rectangle {
    double x, y, h, w;
}

public class Q5 {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        Rectangle r2 = new Rectangle();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter center,height,width for rectangle 1 : ");
        r1.x = sc.nextDouble();
        r1.y = sc.nextDouble();

        r1.h = sc.nextDouble();
        r1.w = sc.nextDouble();

        System.out.print("Enter center,height,width for rectangle 2 : ");
        r2.x = sc.nextDouble();
        r2.y = sc.nextDouble();

        r2.h = sc.nextDouble();
        r2.w = sc.nextDouble();

        if (Math.abs(r1.y - r2.y) <= r1.h / 2 && Math.abs(r1.y + r1.h / 2) >= Math.abs(r2.y + r2.h / 2)
                && Math.abs(r1.x - r2.x) <= r1.w / 2 && Math.abs(r1.x + r1.w / 2) >= Math.abs(r2.x + r2.w / 2)) {
            System.out.println("r2 inside r1");
        } else if (Math.abs(r1.y - r2.y) == r1.h / 2 || Math.abs(r1.x - r2.x) == r1.x / 2) {
            System.out.println("r2 overlaps r1");
        } else if (Math.abs(r2.y) < Math.abs(r1.y) + r1.h / 2 && Math.abs(r2.x) + r2.w / 2 > r1.w
                || Math.abs(r2.x) < Math.abs(r1.x) + r1.w / 2 && Math.abs(r2.x) + r2.w / 2 > r1.w) {
            System.out.println("r2 overlaps r1");
        } else if (Math.abs(r1.y - r2.y) < (r1.h + r2.h) / 2 && Math.abs(r1.x - r2.x) < (r1.w + r2.w) / 2) {
            System.out.println("r2 overlaps r1");
        }

        else {
            System.out.println("r2 does not overlap r1");
        }
        sc.close();
    }
}
