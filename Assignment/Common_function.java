package Assignment;

import java.util.Scanner;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import java.sql.Connection;

public abstract class Common_function {

    protected String email;
    protected String pass_by_user;
    // StringBuffer passwor = new StringBuffer("123");
    private static final String ADMIN_PASSWORD = "123";
    protected String rollNo;
    protected String FacultySubject;

    abstract void DisplayFunctionality();

    abstract void menu();

    protected void signup(int choice) {
        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one
        String email;
        String pass;
        System.out.print("Enter your Email-ID : ");
        email = sc.next();
        System.out.print("Create new password : ");
        pass = sc.next();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DBConnection.getConnection();

            int result;

            if (choice == 2) {
                System.out.print("Enter the course code you teach : ");
                FacultySubject = sc.next();

                // stmt.execute(
                // "create table FacultyRegistration (email varchar(30),password
                // varchar(30),Subject varchar(10))");
                PreparedStatement pstmt = con
                        .prepareStatement("insert into FacultyRegistration (email,password,Subject) values(?,?,?)");

                pstmt.setString(1, email);
                pstmt.setString(2, pass);
                pstmt.setString(3, FacultySubject);
                result = pstmt.executeUpdate();
            } else {
                System.out.print("Enter your Roll No. : ");
                rollNo = sc.next();
                // stmt.execute(
                // "create table StudentRegistration (email varchar(30),password
                // varchar(30),rollNo varchar(20))");

                PreparedStatement pstmt = con
                        .prepareStatement("insert into StudentRegistration (email,password,rollNo) values (?,?,?)");

                pstmt.setString(1, email);
                pstmt.setString(2, pass);
                pstmt.setString(3, rollNo);
                result = pstmt.executeUpdate();
            }

            if (result > 0) {
                System.out.println("---------------------------------------------------");
                System.out.println("!! New user registered successfully !!");
            }

        } catch (Exception e) {
            System.out.println(e);
        }

    }

    protected void login(int choice) {

        Scanner sc = ScannerUtil.getInstance(); // reusing the single shared one

        System.out.print("Enter your Email-ID : ");
        email = sc.next();
        System.out.print("Enter password : ");
        pass_by_user = sc.next();
        if (choice == 1) {
            System.out.print("Enter your Roll NO. : ");
            rollNo = sc.next();
        } else if (choice == 2) {
            System.out.print("Enter course code you teach : ");
            FacultySubject = sc.next();
        }
        if (choice == 1 || choice == 2) {

            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DBConnection.getConnection();
                PreparedStatement ptsmt = null;
                if (choice == 1) {
                    ptsmt = con
                            .prepareStatement(
                                    "SELECT*FROM studentregistration WHERE email=? AND password=? AND rollNo=?");
                    ptsmt.setString(1, email);
                    ptsmt.setString(2, pass_by_user);
                    ptsmt.setString(3, rollNo);
                } else {
                    ptsmt = con
                            .prepareStatement(
                                    "SELECT*FROM facultyregistration WHERE email=? AND password=? AND Subject=?");
                    ptsmt.setString(1, email);
                    ptsmt.setString(2, pass_by_user);
                    ptsmt.setString(3, FacultySubject);
                }

                ResultSet rs = ptsmt.executeQuery();

                if (rs.next()) {
                    System.out.println("---------------------------------------------------");
                    System.out.println("Login Successful !!");
                } else {
                    System.out.println("Invalid Credentials try again!!");
                    login(choice);
                }

            } catch (Exception e) {
                System.out.println(e);
            }
        } else if (pass_by_user.equals(ADMIN_PASSWORD)) {
            System.out.println("---------------------------------------------------");
            System.out.println("Login successful");
        } else {
            System.out.println("Incorrect password ,Try again");
            login(choice);
        }

    }

}
