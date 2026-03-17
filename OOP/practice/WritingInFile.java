package OOP.practice;

import java.io.File;
import java.io.FileWriter;

public class WritingInFile {
    public static void main(String[] args) {
        File n = null;
        FileWriter fw = null;
        try {
            n = new File("D:\\Sem2\\Hello.txt");
            fw = new FileWriter(n);
            fw.write("Hello World");
            System.out.println(n.length());
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                fw.flush();
            } catch (Exception e) {
                System.out.println(e);
            }
            try {
                fw.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        System.out.println(n.exists());

    }
}
