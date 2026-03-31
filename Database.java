import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Connection;

public class Database {
    public static void main(String[] args) {
        String driver = "com.mysql.cj.jdbc.Driver";
        try {
            Class.forName(driver);
            // DriverManager.register(new driver);
        } catch (Exception e) {
            System.out.println(e);
        }

        String url = "jdbc:mysql://localhost:3306/";

        String username = "root";
        String password = "2007@Rohit";
        Statement stmt = null;
        Connection con = null;
        try {
            con = DriverManager.getConnection(url, username, password);
            stmt = con.createStatement();
            String sql = "CREATE DATABASE NewProject";
            stmt.executeUpdate(sql);

        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                if (stmt != null)
                    stmt.close();
            } catch (SQLException e) {
                System.out.println(e);
            }
            try {
                if (con != null)
                    con.close();
            } catch (SQLException e) {
                System.out.println(e);
            }
        }

    }
}
