package Assignment;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Scanner;

public class Faculty extends Common_function {
    Faculty() {
        System.out.println(" ---------------------");
        System.out.println("|   Faculty Login     |");
        System.out.println(" --------------------- ");
    }

    String url = "jdbc:mysql://localhost:3306/Project";
    String username = "root";
    String password = "2007@Rohit";

    void DisplayFunctionality() {

        System.out.println("=========================================");
        System.out.printf("%20s\n", "FUNCTIONALITY");
        System.out.println("=========================================");

        System.out.printf("| %-3s | %-30s |\n", "No", "Option");
        System.out.println("-----------------------------------------");

        System.out.printf("| %-3d | %-30s |\n", 1, "Manage Courses");
        System.out.printf("| %-3d | %-30s |\n", 2, "View Enrolled Students");
        System.out.printf("| %-3d | %-30s |\n", 3, "Logout");

        System.out.println("=========================================");
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
            case 2:
                ViewEnrolledStudents();
                menu();
                break;

            default:
                System.out.println(" LOGOUT ");
        }
    }

    void ManageCourses() {
        Scanner sc = new Scanner(System.in);

        System.out.println("----------------------------------------------");
        System.out.println("Enter : ");
        System.out.println("1). TO view Courses ");
        System.out.println("2).TO update Timing of classes ");
    }

    void ViewEnrolledStudents() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, username, password);
            Statement stmt = con.createStatement();

            PreparedStatement pstmt = con.prepareStatement("select RollNo from registeredCourses WHERE Code = ?");

            pstmt.setString(1, FacultySubject);
            ResultSet rs = pstmt.executeQuery();

            if (!rs.isBeforeFirst()) {

                System.out.println("==============================================================");
                System.out.printf("%30s\n", "NO STUDENT ENROLLED");
                System.out.println("==============================================================");

            } else {

                System.out.println("==============================================================");
                System.out.printf("| %-30s | %-25s |\n", "Roll No", "Contact (Email)");
                System.out.println("==============================================================");

                while (rs.next()) {

                    String rollNo = rs.getString("RollNo");

                    PreparedStatement ps = con.prepareStatement(
                            "SELECT email FROM studentregistration WHERE rollNo = ?");
                    ps.setString(1, rollNo);

                    ResultSet rp = ps.executeQuery();

                    if (rp.next()) {
                        String email = rp.getString("email");

                        System.out.printf("| %-30s | %-25s |\n", rollNo, email);
                    }
                }

                System.out.println("==============================================================");

            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
