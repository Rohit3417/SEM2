package Assignment;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        System.out.println("!! WELCOME TO THE COURSE REGISTRATION PROGRAM !!");
        System.out.println("Enter : ");
        System.out.println("1 for Student login");
        System.out.println("2 for Faculty login");
        System.out.println("3 for Admin");

        Common_function user;
        choice = sc.nextInt();
        if (choice == 1) {
            user = new Student();
        } else if (choice == 2) {
            user = new Faculty();
        } else {
            user = new Admin();
        }

        user.login(choice);
        System.out.println("---------------------------------------------------");
        user.DisplayFunctionality();
        user.menu();

        sc.close();
    }
}
