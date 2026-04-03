package Assignment;

import java.util.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class Student extends Common_function {
    Student() {
        System.out.println(" --------------------- ");
        System.out.println("|   Student Login     |");
        System.out.println(" --------------------- ");
    }

    String username = "root";
    String password = "2007@Rohit";
    String url = "jdbc:mysql://localhost:3306/Project";

    void DisplayFunctionality() {

        System.out.println("=================================================");
        System.out.printf("%25s\n", "FUNCTIONALITY");
        System.out.println("=================================================");

        System.out.printf("| %-3s | %-35s |\n", "No", "Option");
        System.out.println("-------------------------------------------------");

        System.out.printf("| %-3d | %-35s |\n", 1, "View Available Course");
        System.out.printf("| %-3d | %-35s |\n", 2, "Registration for Course");
        System.out.printf("| %-3d | %-35s |\n", 3, "View Schedule");
        System.out.printf("| %-3d | %-35s |\n", 4, "Drop Course");
        System.out.printf("| %-3d | %-35s |\n", 5, "Submit Complaint");
        System.out.printf("| %-3d | %-35s |\n", 6, "Track Academic Progress");
        System.out.printf("| %-3d | %-35s |\n", 7, "Logout");

        System.out.println("=================================================");
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
            case 6:
                TrackCG();
                menu();
                break;
            default:
                System.out.println("=================================");
                System.out.println("|        LOGGED  OUT            |");
                System.out.println("=================================");
        }
    }

    int sem, temp = 0;
    ArrayList<Courses> list = new ArrayList<Courses>();

    void ViewCourses() {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter semester number: ");
        int sem = sc.nextInt();

        System.out.println("======================================================================");
        System.out.printf("%30s\n", "AVAILABLE COURSES");
        System.out.println("======================================================================");

        System.out.printf("| %-10s | %-8s | %-12s | %-8s | %-18s |\n",
                "Course", "Code", "Professor", "Credits", "Timings");
        System.out.println("----------------------------------------------------------------------");

        list.clear();

        if (sem == 1) {

            list.add(new Courses("IoP", "AI103", "Sir1", 4, "8.30AM - 9.30AM"));
            list.add(new Courses("EC", "AI105", "Mam1", 4, "9.30AM - 10.30AM"));
            list.add(new Courses("IoCS", "AI101", "Mam2", 4, "10.30AM - 11.30AM"));

        } else if (sem == 2) {

            list.add(new Courses("OOP", "AI106", "Sir1", 4, "2.00PM - 3.00PM"));
            list.add(new Courses("DS", "AI102", "Sir2", 4, "3.00PM - 4.00PM"));
            list.add(new Courses("EC", "EC106", "Sir3", 4, "4.00PM - 5.00PM"));

        } else {

            System.out.printf("%30s\n", "Invalid Semester");
            System.out.println("======================================================================");
            return;
        }

        list.forEach(System.out::print);

        System.out.println("======================================================================");
    }

    ArrayList<Courses> RegisteredCourses = new ArrayList<Courses>();

    void RegisterCourse() {
        Scanner sc = new Scanner(System.in);
        temp = 1;
        System.out.println("-------------------------------------------------");
        System.out.printf("| %-47s |\n", "WELCOME TO COURSE REGISTRATION PAGE");
        System.out.println("-------------------------------------------------");
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

        int i;
        for (i = 0; i < 3; i++) {
            if (course.equals(list.get(i).code)) {
                list2.add(new Schedule(course));
                break;
            }
        }

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, username, password);
            // Statement stmt = con.createStatement(); // for the first time
            // stmt.execute(
            // "create table registeredCourses (RollNo varchar(1000),Title varchar(20),Code
            // varchar(10),Faculty varchar(30),Credits int,Timings varchar(100))");
            PreparedStatement ptsmt = con.prepareStatement(
                    "insert into registeredCourses (RollNo,Title,Code,Faculty,Credits,Timings) values (?,?,?,?,?,?)");

            ptsmt.setString(1, rollNo);
            ptsmt.setString(2, list.get(i).Title);
            ptsmt.setString(3, list.get(i).code);
            ptsmt.setString(4, list.get(i).Faculty);
            ptsmt.setInt(5, list.get(i).Credits);
            ptsmt.setString(6, list.get(i).timings);

            int result = ptsmt.executeUpdate();

            if (result > 0) {
                System.out.println("=================================================");
                System.out.printf("%35s\n", "REGISTRATION SUCCESSFUL");
                System.out.println("=================================================");
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void ViewSchedule() {
        System.out.println("======================================================================");
        System.out.printf("%35s\n", "COURSE SCHEDULE");
        System.out.println("======================================================================");

        try {
            Connection con = DriverManager.getConnection(url, username, password);
            PreparedStatement pstmt = con.prepareStatement(
                    "select * from registeredCourses where RollNo = ?");
            pstmt.setString(1, rollNo);
            ResultSet rs = pstmt.executeQuery();

            System.out.println("===============================================================");
            System.out.println(" Title              | Code   | Faculty           | Timings     ");
            System.out.println("---------------------------------------------------------------");

            while (rs.next()) {
                System.out.printf(" %-18s | %-6s | %-16s | %-12s \n",
                        rs.getString("Title"),
                        rs.getString("Code"),
                        rs.getString("Faculty"),
                        rs.getString("Timings"));
            }

            System.out.println("===============================================================");

        } catch (Exception e) {
            System.out.println(e);
        }

    }

    void DropCourse() {
        Scanner sc = new Scanner(System.in);
        int more;
        do {
            String course;
            System.out.print("Enter the course code you want to drop : ");
            course = sc.next();

            if (dropFromDatabase(course)) {

                System.out.println("=================================================");
                System.out.printf("| %-47s |\n", "COURSE DROPPED SUCCESSFULLY");
                System.out.printf("| %-47s |\n", "Course: " + course);
                System.out.println("=================================================");

            } else {

                System.out.println("=================================================");
                System.out.printf("| %-47s |\n", "NOT REGISTERED FOR THIS COURSE");
                System.out.println("=================================================");

            }

            System.out.print("Do you want to drop more of the courses (1/0) ? : ");
            more = sc.nextInt();

        } while (more == 1);

    }

    boolean dropFromDatabase(String course) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, username, password);

            PreparedStatement pstmt = con.prepareStatement("delete from registeredCourses WHERE Code = ?");
            pstmt.setString(1, course);

            int rs = pstmt.executeUpdate();
            if (rs > 0) {
                return true;
            } else {
                return false;
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        return false;
    }

    void Complaints() {
        Scanner sc = new Scanner(System.in);
        String complaints;

        System.out.println("Type the problem you have been facing below : ");
        complaints = sc.nextLine();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, username, password);
            Statement stmt = con.createStatement(); // for the first time
            // stmt.execute("create table complaints (Complaint varchar(1000),Status
            // varchar(20))");
            PreparedStatement ptsmt = con.prepareStatement("insert into complaints (Complaint,Status) values(?,?)");

            ptsmt.setString(1, complaints);
            ptsmt.setString(2, "PENDING");

            int result = ptsmt.executeUpdate();

            if (result > 0) {
                System.out.println("---------------------------------------------------");
                System.out.println("!!  Complaint registered successfully  !!");
                System.out.println("---------------------------------------------------");
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void TrackCG() {
        try {
            Connection con = DriverManager.getConnection(url, username, password);

            Statement stmt = con.createStatement();
            PreparedStatement pstmt = con.prepareStatement(
                    "select * from studentregistration where rollNo = ?");
            pstmt.setString(1, rollNo);
            ResultSet rs = pstmt.executeQuery();

            System.out.println("========================================");
            System.out.println("         STUDENT CGPA DETAILS           ");
            System.out.println("----------------------------------------");

            while (rs.next()) {

                System.out.println("| CGPA (Previous Semester) :           |");
                System.out.printf("| %-35.2f |\n", rs.getFloat("CGPA"));

            }

            System.out.println("========================================");

        } catch (Exception e) {
            System.out.println(e);
        }
    }

}
