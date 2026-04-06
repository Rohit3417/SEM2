package Assignment;

import java.sql.DriverManager;
import java.util.Scanner;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

public class Admin extends Common_function {

    Admin() {

        System.out.println("-----------------------------------------");
        System.out.printf("| %-39s |\n", "ADMIN LOGIN");
        System.out.println("-----------------------------------------");

    }

    String url = "jdbc:mysql://localhost:3306/Project";
    String username = "root";
    String password = "2007@Rohit";

    @Override
    public void DisplayFunctionality() {

        System.out.println("=========================================");
        System.out.printf("%20s\n", "FUNCTIONALITY AVAILABLE");
        System.out.println("=========================================");

        System.out.printf("| %-3s | %-30s |\n", "No", "Option");
        System.out.println("-----------------------------------------");

        System.out.printf("| %-3d | %-30s |\n", 1, "Manage Course Catalog");
        System.out.printf("| %-3d | %-30s |\n", 2, "Manage Student Records");
        System.out.printf("| %-3d | %-30s |\n", 3, "Assign Professors to Courses");
        System.out.printf("| %-3d | %-30s |\n", 4, "Handle Complaints");
        System.out.printf("| %-3d | %-30s |\n", 5, "Logout");

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
                ManageCourseCatalog();
                menu();
                break;
            case 2:
                ManageStudentRecord();
                menu();
                break;
            case 3:
                AssignProfessor();
                menu();
                break;
            case 4:
                HandleComplaints();
                menu();
                break;
            default:

                System.out.println("=================================");
                System.out.println("|        LOGGED  OUT            |");
                System.out.println("=================================");
        }
    }

    void ManageCourseCatalog() {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one
        System.out.println("\n=================================");
        System.out.println("|      COURSE MANAGEMENT        |");
        System.out.println("=================================");
        System.out.println("|  1. View all courses          |");
        System.out.println("|  2. Add a course              |");
        System.out.println("|  3. Delete a course           |");
        System.out.println("=================================");
        System.out.print("Enter your choice: ");
        int temp = sc.nextInt();

        try {
            Connection con = DriverManager.getConnection(url, username, password);
            Statement stmt = con.createStatement();

            if (temp == 1) {
                ResultSet rs = stmt.executeQuery("select * from Courses");
                System.out.println("\n===========================================");
                System.out.println("|    Course Name    |  Code  | Professor  |");
                System.out.println("===========================================");
                while (rs.next()) {
                    System.out.printf("| %-17s | %-6s | %-10s |%n",
                            rs.getString("Course_Name"),
                            rs.getString("Code"),
                            rs.getString("Professor"));
                    System.out.println("-------------------------------------------");
                }

            } else if (temp == 2) {
                String name, code, professor;
                System.out.println("\n=================================");
                System.out.println("|       ADD NEW COURSE          |");
                System.out.println("=================================");
                System.out.print("| Course title   : ");
                name = sc.next();
                System.out.print("| Course code    : ");
                code = sc.next();
                System.out.print("| Professor name : ");
                professor = sc.next();
                System.out.println("---------------------------------");

                PreparedStatement pstmt = con
                        .prepareStatement("insert into Courses (Course_Name,Code,Professor) values (?,?,?)");
                pstmt.setString(1, name);
                pstmt.setString(2, code);
                pstmt.setString(3, professor);

                int result = pstmt.executeUpdate();
                System.out.println(result > 0
                        ? "| [OK] Course \"" + name + "\" added successfully!"
                        : "| [!!] Failed to add course. Try again.");
                System.out.println("=================================");

            } else if (temp == 3) {
                String code;
                System.out.println("\n=================================");
                System.out.println("|        DELETE COURSE          |");
                System.out.println("=================================");
                System.out.print("| Enter course code to delete : ");
                code = sc.next();
                System.out.println("---------------------------------");

                PreparedStatement pstmt = con.prepareStatement("delete from Courses where Code = ?");
                pstmt.setString(1, code);
                int result = pstmt.executeUpdate();
                System.out.println(result > 0
                        ? "| [OK] Course \"" + code + "\" deleted successfully."
                        : "| [!!] No course found with code \"" + code + "\".");
                System.out.println("=================================");
            }

        } catch (Exception e) {
            System.out.println("\n=================================");
            System.out.println("| [ERR] " + e.getMessage());
            System.out.println("=================================");
        }
    }

    void ManageStudentRecord() {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one
        System.out.println("\n=================================");
        System.out.println("|       MANAGE STUDENT RECORDS    |");
        System.out.println("=================================");
        System.out.println("|  1. View Info              |");
        System.out.println("|  2. Update CGPA of student       |");
        System.out.println("=================================");
        System.out.print("| Enter your choice : ");
        int choice = sc.nextInt();
        System.out.println("---------------------------------");

        try {
            Connection con = DriverManager.getConnection(url, username, password);

            if (choice == 1) {
                PreparedStatement pstmt = con.prepareStatement("select *from studentregistration");
                ResultSet rs = pstmt.executeQuery();

                System.out.println("\n===========================================");
                System.out.printf("| %-25s | %-12s |\n", "Email", "Roll No");
                System.out.println("===========================================");
                while (rs.next()) {
                    System.out.printf("| %-25s | %-12s |\n",
                            rs.getString("email"),
                            rs.getString("rollNo"),
                            rs.getFloat("CGPA"));

                    System.out.println("-------------------------------------------");
                }

            } else if (choice == 2) {
                float newCGPA;
                String roll;

                System.out.println("\n=================================");
                System.out.println("|        UPDATE CGPA            |");
                System.out.println("=================================");
                System.out.print("| Student roll no. : ");
                roll = sc.next();
                System.out.print("| CGPA             : ");
                newCGPA = sc.nextFloat();
                System.out.println("---------------------------------");

                PreparedStatement pstmt = con
                        .prepareStatement("update studentregistration set CGPA = ? where rollNo = ?");
                pstmt.setFloat(1, newCGPA);
                pstmt.setString(2, roll);

                int rs = pstmt.executeUpdate();
                if (rs > 0)
                    System.out.println("| [OK] CGPA updated to " + newCGPA + " for " + roll);
                else
                    System.out.println("| [!!] No student found with roll no. " + roll);
                System.out.println("=================================");
            }

        } catch (Exception e) {
            System.out.println("\n=================================");
            System.out.println("| [ERR] " + e.getMessage());
            System.out.println("=================================");
        }
    }

    void AssignProfessor() {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one
        try {
            Connection con = DriverManager.getConnection(url, username, password);

            String newProfessor;
            String code;

            System.out.println("\n=================================");
            System.out.println("|      ASSIGN NEW PROFESSOR     |");
            System.out.println("=================================");
            System.out.print("| New Professor name : ");
            newProfessor = sc.next();
            System.out.print("| Course code        : ");
            code = sc.next();
            System.out.println("---------------------------------");

            PreparedStatement pstmt = con.prepareStatement("update Courses set Professor = ? where Code = ?");
            pstmt.setString(1, newProfessor);
            pstmt.setString(2, code);

            int check = pstmt.executeUpdate();
            if (check > 0) {
                System.out.println("| [OK] Prof. " + newProfessor + " assigned to course " + code);
            } else {
                System.out.println("| [!!] No course found with code \"" + code + "\"");
            }
            System.out.println("=================================");

        } catch (Exception e) {
            System.out.println("\n=================================");
            System.out.println("| [ERR] " + e.getMessage());
            System.out.println("=================================");
        }
    }

    void HandleComplaints() {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one
        try {
            Connection con = DriverManager.getConnection(url, username, password);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT *FROM complaints");

            if (!rs.isBeforeFirst()) {
                System.out.println(" -----------------------------------------");
                System.out.println("|         !! NO COMPLAINTS !!             |");
                System.out.println(" -----------------------------------------");
            }
            System.out.println("--------------------------------------------------------------------------------");
            System.out.printf("| %-30s | %-25s | %-10s |\n", "Complaint", "Status", "ID");
            System.out.println("--------------------------------------------------------------------------------");

            while (rs.next()) {
                System.out.printf("| %-30s | %-25s | %-10d |\n",
                        rs.getString("Complaint"),
                        rs.getString("Status"),
                        rs.getInt("id"));
            }

            System.out.println("--------------------------------------------------------------------------------");

            System.out.print("Enter id number for which the complaint has been resolved: ");
            int row = sc.nextInt();
            if (row == 0) {
                menu();
            } else {
                PreparedStatement ps = con.prepareStatement("update complaints set Status = 'RESOLVED' WHERE id = ?");
                ps.setInt(1, row);
                int check = ps.executeUpdate();
                if (check > 0) {
                    System.out.println("!!  Complaint resolved successfully  !!");
                } else {
                    System.out.println("No such complaint pending ");
                }

            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}