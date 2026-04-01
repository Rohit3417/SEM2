package Assignment;

import java.sql.DriverManager;
import java.util.Scanner;
import java.nio.charset.StandardCharsets;
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

    void DisplayFunctionality() {

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

    void menu() {
        Scanner sc = new Scanner(System.in);
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
                System.out.println("!!  LOGGED OUT  !!");
        }
    }

    void ManageCourseCatalog() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter : ");
        System.out.println("1).To View all courses| 2).To add Course | 3).To delete a course");
        int temp = sc.nextInt();

        try {
            Connection con = DriverManager.getConnection(url, username, password);

            Statement stmt = con.createStatement();

            if (temp == 1) {
                ResultSet rs = stmt.executeQuery("select *from Courses");
                System.out.println("Course Name | Code | Professor");
                System.out.println("-------------------------------");
                while (rs.next()) {
                    System.out.println(rs.getString("Course_Name") + " | " + rs.getString("Code") + " | "
                            + rs.getString("Professor"));
                    System.out.println("---------------------------------------");
                }
            } else if (temp == 2) {
                String name, code, professor;
                System.out.println("TO ADD NEW COURSE");
                System.out.print("Enter course title : ");
                name = sc.next();
                System.out.print("Enter Course code : ");
                code = sc.next();
                System.out.print("Enter Professor name for this course : ");
                professor = sc.next();

                PreparedStatement pstmt = con
                        .prepareStatement("insert into Courses (Course_Name,Code,Professor) values (?,?,?)");
                pstmt.setString(1, name);
                pstmt.setString(2, code);
                pstmt.setString(3, professor);

                int result = pstmt.executeUpdate();
                if (result > 0)
                    System.out.println("Courses added successfully");
                else
                    System.out.println("Course not added");
            } else if (temp == 3) {
                String code;
                System.out.print("Enter course code to delete : ");
                code = sc.next();
                PreparedStatement pstmt = con.prepareStatement("delete from Courses where Code = ?");
                pstmt.setString(1, code);
                int result = pstmt.executeUpdate();
                if (result > 0)
                    System.out.println("Course deleted successfully");
                else
                    System.out.println("No such Course available");
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void ManageStudentRecord() {

    }

    void AssignProfessor() {
        Scanner sc = new Scanner(System.in);
        try {
            Connection con = DriverManager.getConnection(url, username, password);
            Statement stmt = con.createStatement();

            String newProfessor;
            String code;
            System.out.print("Enter the name of new Professor : ");
            newProfessor = sc.next();
            System.out.print("Their Course Expertise code : ");
            code = sc.next();

            PreparedStatement pstmt = con.prepareStatement("update Courses set Professor = ? where Code = ?");
            pstmt.setString(1, newProfessor);
            pstmt.setString(2, code);

            int check = pstmt.executeUpdate();
            if (check > 0)
                System.out.println("New professor assigned successfully");
            else
                System.out.println("Error occured");

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void HandleComplaints() {
        Scanner sc = new Scanner(System.in);
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
