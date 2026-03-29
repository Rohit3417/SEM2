package OOP.Lab8;

import java.io.File;
import java.io.FileReader;

public class Q4 {
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

            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == ' ' || str.charAt(j) == '.' || str.charAt(j) == ','
                        || str.charAt(j) == '\n') {
                    char temp = Character.toUpperCase(str.charAt(j + 1));
                    str.setCharAt(j + 1, temp);
                }
                if (j == 0) {
                    char temp = Character.toUpperCase(str.charAt(j));
                    str.setCharAt(j, temp);
                }
            }
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
