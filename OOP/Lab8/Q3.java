package OOP.Lab8;

import java.io.File;
import java.io.FileReader;

public class Q3 {
    public static void main(String[] args) {
        File f = new File("D:\\Sem2\\OOP\\Lab8\\Demo.txt");
        FileReader fr = null;
        try {
            fr = new FileReader(f);

            StringBuffer str = new StringBuffer("");
            int i;
            while ((i = fr.read()) != -1) {
                str.append((char) i);

            }
            System.out.println(str);

            for (int j = -1; j < str.length(); j++) {
                if (j == -1 || str.charAt(j) == ' ' || str.charAt(j) == '.' || str.charAt(j) == ','
                        || str.charAt(j) == '\n') {
                    str.delete(j + 1, j + 4);

                }
            }
            System.out.println("\nAfter deleting the 1st three characters of each name :");
            System.out.println(str);

        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                fr.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}
