package Assignment;

import java.util.Scanner;

public abstract class Common_function {

    String email;
    String pass_by_user;
    StringBuffer password = new StringBuffer("123");
    String temp, temp2;

    abstract void DisplayFunctionality();

    abstract void menu();

    void login(int choice) {

        Scanner sc = new Scanner(System.in);

        // CREATING ACCOUNT FOR 1ST TIME
        if (choice == 1 || choice == 2) {
            System.out.println("First Create Account");
            while (true) {
                System.out.print("Enter your Email-ID : ");
                temp2 = sc.next();
                if (temp2.contains("@gmail.com"))
                    break;
                else
                    System.out.println("Invalid Email try again");
            }
            System.out.print("Enter new password : ");
            temp = sc.next();
        }
        // LOGIN SECTION

        if (choice == 1 || choice == 2) {
            System.out.println("After creating an account you need to login :");
        }
        while (true) {
            System.out.print("Enter your Email-ID : ");
            email = sc.next();
            if (choice != 3 && !temp2.equals(email)) {
                System.out.println("Invalid Email try again");
            } else if (email.contains("@gmail.com"))
                break;
            else
                System.out.println("Invalid Email try again");
        }

        while (true) {
            System.out.print("Enter password : ");
            pass_by_user = sc.next();
            if (choice == 1 || choice == 2) {
                if (pass_by_user.equals(temp)) {
                    System.out.println("---------------------------------------------------");
                    System.out.println("Login successful");
                    break;
                } else
                    System.out.println("Incorrect password , Try again");
            } else if (pass_by_user.equals(password.toString())) {
                System.out.println("---------------------------------------------------");
                System.out.println("Login successful");
                break;
            } else
                System.out.println("Incorrect password ,Try again");
        }
        // sc.close();

    }

}
