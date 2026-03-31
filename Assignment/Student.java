package Assignment;

import java.util.*;
import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class Student extends Common_function {
    Student() {
        System.out.println("Student login");
    }

    void DisplayFunctionality() {
        System.out.println("            FUNTIONALITY AVAILABLE");
        System.out.println("            ----------------------");
        System.out.println("1).View Available Course");
        System.out.println("2).Registration for course");
        System.out.println("3).View Schedule");
        System.out.println("4).Drop Course");
        System.out.println("5).Submit Complaint");
        System.out.println("6).Track Academic Progress");

        System.out.println("------------------------------------------------------");

    }

    void menu() {
        Scanner sc = new Scanner(System.in);
        int function;
        System.out.print("Enter the number to choose a function from list : ");
        function = sc.nextInt();
        switch (function) {
            case 1:
                ViewCourses();
                menu();
                break;
            case 2:
                RegisterCourse();
                menu();
                break;

            case 3:
                ViewSchedule();
                menu();
                break;

            case 4:
                DropCourse();
                menu();
                break;

            case 5:
                Complaints();
                menu();
                break;

            default:
                System.out.println("Log out");
        }
    }

    int sem, temp = 0;
    ArrayList<Courses> list = new ArrayList<Courses>();

    void ViewCourses() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter semester number : ");
        sem = sc.nextInt();
        System.out.println("\tAvailable Courses in this Semester!!");
        System.out.println("\t-----------------------------------");
        System.out.println("Course\t|\tCode\t| Professor\t|\tcredits\t|\tTimings");
        System.out.println(
                "--------------------------------------------------------------------------------------------------");
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

    ArrayList<Courses> RegisteredCourses = new ArrayList<Courses>();

    void RegisterCourse() {
        Scanner sc = new Scanner(System.in);
        temp = 1;
        System.out.println("\tWELCOME TO REGISTRATION COURSE PAGE");
        System.out.println("\t-----------------------------------");
        ViewCourses();
        int more;
        do {
            String course;
            System.out.print("Enter Course code for which you want to register : ");
            course = sc.next();
            if (!course.contains("AI") && !course.contains("10") && !course.contains("EC")) {
                System.out.println("No such Course exists in this semester");
            } else if (course.contains("AI102")) {
                String preq;
                System.out.println("To register to this course :");
                System.out.println("Have you cleared IoCS(AI101) course in sem 1 :");
                preq = sc.next();
                if (preq.contains("NO") || preq.contains("no") || preq.contains("No")) {
                    System.out.println("You need to complete the AI101 course before!!");
                } else {
                    Register(course);
                }
            } else {
                Register(course);
            }

            System.out.println("Do you want to register for more courses(1/0) ??");
            more = sc.nextInt();
        } while (more == 1);
        System.out.println("\t--------------------------------");

    }

    ArrayList<Schedule> list2 = new ArrayList<>();

    void Register(String course) {
        for (int i = 0; i < 3; i++) {
            if (course.equals(list.get(i).code)) {
                System.out.println(list.get(i).code);
                list2.add(new Schedule(course));
            }
        }
        System.out.println("\t---------------------------");
        System.out.println("\t!!Registration successfully!!");
        System.out.println("\t---------------------------");
    }

    void ViewSchedule() {
        System.out.println("\t-----------------------------------------------");
        System.out.println("\t !! SCHEDULE ACCORDING TO REGISTERED COURSES !!");
        System.out.println("\t-----------------------------------------------");
        if (list2.size() == 0) {
            System.out.println("No registered Courses");
        } else {
            System.out.println("Course\t|\tCode\t|Professor\t|");
            System.out.println("--------------------------------------------");
            for (int i = 0; i < list2.size(); i++) {
                for (int j = 0; j < list.size(); j++) {
                    if (list2.get(i).code.equals(list.get(j).code)) {
                        System.out
                                .println(
                                        list.get(i).Title + "\t|\t" + list.get(i).code + "\t|\t" + list.get(i).Faculty);
                        break;
                    }
                }
            }
        }

    }

    void DropCourse() {
        Scanner sc = new Scanner(System.in);
        int more;
        do {
            String course;
            System.out.print("Enter the course code you want to drop : ");
            course = sc.next();
            int temp = 0;
            for (int i = 0; i < list2.size(); i++) {
                if (course.equals(list2.get(i).code)) {
                    list2.remove(i);
                    temp = 1;
                    break;
                }
            }
            if (temp == 0)
                System.out.println("No such Course Registered for");
            else {
                System.out.println("\t---------------------------");
                System.out.println("\t!! Course " + course + " dropped successfully!!");
                System.out.println("\t---------------------------");
            }
            if (!list2.isEmpty()) {
                System.out.print("Do you want to drop more of the courses (1/0) ? : ");
                more = sc.nextInt();
            } else {
                System.out.println("No more courses left to drop");
                break;
            }

        } while (more == 1);

    }

    void Complaints() {
        Scanner sc = new Scanner(System.in);
        String complaints;

        String username = "root";
        String password = "2007@Rohit";
        String url = "jdbc:mysql://localhost:3306/Project";

        System.out.println("Type the problem you have been facing below : ");
        complaints = sc.nextLine();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, username, password);
            // Statement stmt = con.createStatement(); //for the first time
            // stmt.execute("create table complaints (complaint varchar(1000))");
            PreparedStatement ptsmt = con.prepareStatement("insert into complaints (complaint) values(?)");

            ptsmt.setString(1, complaints);

            int result = ptsmt.executeUpdate();

            if (result > 0) {
                System.out.println("---------------------------------------------------");
                System.out.println("!! Complaint registered successfully !!");
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

}
