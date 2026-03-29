package OOP.FileHandling;

import java.io.File;
import java.io.FileWriter;

public class FIle2 {
    public static void main(String[] args) {
        File f1 = new File("D:\\Sem2\\OOP\\practice\\Demo.txt");
        FileWriter f = null;
        try {
            f1.createNewFile();
            f = new FileWriter(f1);
            f.write("This will be written");
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                f.flush();
                f.close();
            } catch (Exception e) {
                System.out.println(e);
            }

        }
    }
}