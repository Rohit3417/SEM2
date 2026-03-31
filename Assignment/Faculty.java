package Assignment;

import java.util.ArrayList;
import java.util.Scanner;

public class Faculty extends Common_function {
    Faculty() {
        System.out.println("Faculty login");
    }

    void DisplayFunctionality() {
        System.out.println("            FUNTIONALITY AVAILABLE");
        System.out.println("            ----------------------");
        System.out.println("1).Manage Courses ");
        System.out.println("2).View Enrolled Students ");
    }

    void menu() {
        Scanner sc = new Scanner(System.in);
        int function;
        System.out.print("Enter the number to choose a function from list : ");
        function = sc.nextInt();
        switch (function) {
            case 1:
                ManageCourses();
                menu();
                break;

            default:
                System.out.println(" LOGOUT ");
        }
    }

    int sem;
    ArrayList<Courses> list = new ArrayList<Courses>();

    void ViewCourses() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter semester number : ");
        sem = sc.nextInt();
        System.out.println("\tAvailable Courses in this Semester!!");
        System.out.println("\t-----------------------------------");
        System.out.println("Course\t|\tCode\t| Professor\t|\tcredits\t|\tTimings");
        System.out.println("-----------------------------------------------------------------------------");
        if (sem == 1) {
            list.clear();
            list.add(new Courses("IoP", "AI103", "Sir1", 4, "8.30AM - 9.30AM"));
            list.add(new Courses("EC", "AI105", "Mam1", 4, "9.30AM - 10.30AM"));
            list.add(new Courses("IoCS", "AI101", "Mam2", 4, "10.30AM - 11.30AM"));
            list.forEach(System.out::print);
        } else if (sem == 2) {
            list.clear();
            list.add(new Courses("OOP", "AI106", "Sir1", 4, "2.00PM - 3.00PM"));
            list.add(new Courses("DS", "AI102", "Sir2", 4, "3.00PM - 4.00PM"));
            list.add(new Courses("EC", "EC106", "Sir3", 4, "4.00PM - 5.00PM"));
            list.forEach(System.out::print);
        }

    }

    void ManageCourses() {
        Scanner sc = new Scanner(System.in);
        ViewCourses();
        String faculty_course;
        System.out.print("Enter the course code you teach : ");
        faculty_course = sc.next();

    }
}
