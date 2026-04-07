package Assignment;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import java.util.Scanner;

public class Faculty extends Common_function {
    Faculty() {
        System.out.println(" ---------------------");
        System.out.println("|   Faculty Login     |");
        System.out.println(" --------------------- ");
    }

    @Override
    public void DisplayFunctionality() {

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

    @Override
    public void menu() {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one
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
                System.out.println("=================================");
                System.out.println("|        LOGGED  OUT            |");
                System.out.println("=================================");
        }
    }

    void ManageCourses() {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one

        System.out.println("\n=================================");
        System.out.println("|       MANAGE COURSES          |");
        System.out.println("=================================");
        System.out.println("|  1. View courses              |");
        System.out.println("|  2. Update class timing       |");
        System.out.println("|  3. Update subject credits    |");
        System.out.println("=================================");
        System.out.print("| Enter your choice : ");
        int choice = sc.nextInt();
        System.out.println("---------------------------------");

        try {
            Connection con = DBConnection.getConnection();

            if (choice == 1) {
                PreparedStatement pstmt = con.prepareStatement("select *from registeredCourses where Code = ?");
                pstmt.setString(1, FacultySubject);

                ResultSet rs = pstmt.executeQuery();
                System.out.println("\n=================================================================");
                System.out.printf("| %-10s | %-15s | %-6s | %-12s | %-7s | %-10s |\n",
                        "Roll No", "Title", "Code", "Faculty", "Credits", "Timings");
                System.out.println("=================================================================");
                while (rs.next()) {
                    System.out.printf("| %-10s | %-15s | %-6s | %-12s | %-7d | %-10s |\n",
                            rs.getString("RollNo"),
                            rs.getString("Title"),
                            rs.getString("Code"),
                            rs.getString("Faculty"),
                            rs.getInt("Credits"),
                            rs.getString("Timings"));
                    System.out.println("-----------------------------------------------------------------");
                }

            } else if (choice == 2) {
                String newTime;
                System.out.println("\n=================================");
                System.out.println("|      UPDATE CLASS TIMING      |");
                System.out.println("=================================");
                System.out.print("| New timing : ");
                sc.nextLine();
                newTime = sc.nextLine();
                System.out.println("---------------------------------");

                PreparedStatement pstmt = con
                        .prepareStatement("update registeredCourses set Timings = ? where Code = ?");
                pstmt.setString(1, newTime);
                pstmt.setString(2, FacultySubject);

                int result = pstmt.executeUpdate();
                System.out.println(result > 0
                        ? "| [OK] Timing updated to : " + newTime
                        : "| [!!] Could not update. Course not found.");
                System.out.println("=================================");

            } else if (choice == 3) {
                int newCredit;
                System.out.println("\n=================================");
                System.out.println("|      UPDATE SUBJECT CREDITS   |");
                System.out.println("=================================");
                System.out.print("| New credit value : ");
                newCredit = sc.nextInt();
                System.out.println("---------------------------------");

                PreparedStatement pstmt = con
                        .prepareStatement("update registeredCourses set Credits = ? where Code = ?");
                pstmt.setInt(1, newCredit);
                pstmt.setString(2, FacultySubject);

                int result = pstmt.executeUpdate();
                System.out.println(result > 0
                        ? "| [OK] Credits updated to : " + newCredit
                        : "| [!!] Error occurred while updating.");
                System.out.println("=================================");
            }

        } catch (Exception e) {
            System.out.println("\n=================================");
            System.out.println("| [ERR] " + e.getMessage());
            System.out.println("=================================");
        }
    }

    void ViewEnrolledStudents() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DBConnection.getConnection();

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
                        String email = rp.getString("Email");

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