package Assignment;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        System.out.println("=================================================");
        System.out.printf("%40s\n", "COURSE REGISTRATION SYSTEM");
        System.out.println("=================================================");

        System.out.printf("| %-3s | %-35s |\n", "No", "Login Type");
        System.out.println("-------------------------------------------------");

        System.out.printf("| %-3d | %-35s |\n", 1, "Student Login");
        System.out.printf("| %-3d | %-35s |\n", 2, "Faculty Login");
        System.out.printf("| %-3d | %-35s |\n", 3, "Admin Login");

        System.out.println("=================================================");
        System.out.print("Enter your choice: ");

        Common_function user;
        choice = sc.nextInt();
        if (choice == 1) {
            user = new Student();
        } else if (choice == 2) {
            user = new Faculty();
        } else {
            user = new Admin();
        }

        if ((choice == 1 || choice == 2)) {
            int temp;
            System.out.println("New user enter(1/0) : ");
            temp = sc.nextInt();
            if (temp == 1)
                user.signup(choice);
            else
                user.login(choice);
        } else {
            user.login(choice);
        }

        System.out.println("---------------------------------------------------");
        user.DisplayFunctionality();
        user.menu();

        sc.close();
    }
}
