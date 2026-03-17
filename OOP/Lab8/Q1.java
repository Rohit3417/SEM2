package OOP.Lab8;

import java.io.File;
import java.io.FileReader;

public class Q1 {
    public static void main(String[] args) {
        File f = new File("D:\\Sem2\\OOP\\Lab8\\Demo.txt");
        FileReader fr = null;
        try {
            f.createNewFile();
            fr = new FileReader(f);
            StringBuffer str = new StringBuffer("");
            int i;
            while ((i = fr.read()) != -1) {
                str.append((char) i);
            }
            int first = str.indexOf("the");
            int last = str.lastIndexOf("the");
            System.out.println(str);
            System.out.println("First = " + first + " last = " + last);

            StringBuffer temp = new StringBuffer("");
            temp.append(str, first + 4, last);
            System.out.println(temp);

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
