package OOP.Lab8;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Q5 {
    public static void main(String[] args) {
        File f = new File("D:\\Sem2\\OOP\\Lab8\\sdj.txt");
        StringBuffer newContent = new StringBuffer();
        FileReader fr = null;
        FileWriter fw = null;
        try {
            f.createNewFile();
            fr = new FileReader(f); /*
                                     * !!!!IMP : file reading should be closed before writing otherwise it is
                                     * cleared
                                     */
            int i;
            while ((i = fr.read()) != -1) {
                newContent.append((char) i);
            }
            fr.close();
            fw = new FileWriter(f);
            System.out.println(newContent);
            String str = newContent.toString()
                    .replace("his", "her")
                    .replace("His", "Her");
            System.out.println(str);

            fw.write(str);
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {

                fw.flush();
                fw.close();

            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}
