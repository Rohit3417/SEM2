package OOP.Lab5;

import java.util.Scanner;

class Student {
    Scanner sc = new Scanner(System.in);
    String name;

    boolean Average(int m1, int m2, int m3) {
        int avg;
        // String name;
        avg = (m1 + m2 + m3) / 3;
        if (avg < 50)
            return false;
        else
            return true;
    }

    String Name() {
        name = sc.next();
        return name;
    }
}

public class Q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student s = new Student();
        System.out.print("Enter name of student : ");
        String name = s.Name();
        System.out.println("Enter marks of the 3 examinations out of 100 : ");
        int m1 = sc.nextInt();
        int m2 = sc.nextInt();
        int m3 = sc.nextInt();

        System.out.print("Status of " + name + " : ");
        if (s.Average(m1, m2, m3)) {
            System.out.print("Pass");
        } else {
            System.out.print("Fail");
        }
        sc.close();
    }
}
