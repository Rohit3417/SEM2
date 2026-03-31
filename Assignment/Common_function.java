package Assignment;

import java.util.Scanner;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Connection;

public abstract class Common_function {

    String email;
    String pass_by_user;
    StringBuffer password = new StringBuffer("123");

    abstract void DisplayFunctionality();

    abstract void menu();

    void signup() {
        Scanner sc = new Scanner(System.in);
        String email;
        String pass;
        System.out.print("Enter your Email-ID : ");
        email = sc.next();
        System.out.print("Create new password : ");
        pass = sc.next();

        String url = "jdbc:mysql://localhost:3306/Project";
        String username = "root";
        String password = "2007@Rohit";
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, username, password);
            // Statement stmt = con.createStatement();
            // stmt.execute("create table Project (email varchar(30),pass varchar(30))");
            PreparedStatement pstmt = con.prepareStatement("insert into Project (email,pass) values(?,?)");

            pstmt.setString(1, email);
            pstmt.setString(2, pass);

            int result = pstmt.executeUpdate();

            if (result > 0) {
                System.out.println("---------------------------------------------------");
                System.out.println("!! New user registered successfully !!");
            }

        } catch (Exception e) {
            System.out.println(e);
        }

    }

    void login(int choice) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your Email-ID : ");
        email = sc.next();
        System.out.print("Enter password : ");
        pass_by_user = sc.next();
        if (choice == 1 || choice == 2) {
            String url = "jdbc:mysql://localhost:3306/Project";
            String username = "root";
            String password = "2007@Rohit";
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DriverManager.getConnection(url, username, password);

                PreparedStatement ptsmt = con.prepareStatement("SELECT*FROM Project WHERE email=? AND pass=?");
                ptsmt.setString(1, email);
                ptsmt.setString(2, pass_by_user);

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
        } else if (pass_by_user.equals(password.toString())) {
            System.out.println("---------------------------------------------------");
            System.out.println("Login successful");
        } else {
            System.out.println("Incorrect password ,Try again");
            login(choice);
        }
        // sc.close();

    }

}
