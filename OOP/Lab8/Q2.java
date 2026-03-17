package OOP.Lab8;

import java.io.File;
import java.io.FileReader;

public class Q2 {
    public static void main(String[] args) {
        File f = new File("D:\\Sem2\\OOP\\Lab8\\vowels.txt");
        FileReader fr = null;
        try {
            f.createNewFile();
            fr = new FileReader(f);
            int i, j = 1;
            while ((i = fr.read()) != -1) {
                if (((char) i) == 'a' || ((char) i) == 'e' || ((char) i) == 'i' || ((char) i) == 'o'
                        || ((char) i) == 'u') {
                    System.out.println("Position = " + j + ",vowel = " + (char) i);
                } else if (((char) i) == 'A' || ((char) i) == 'E' || ((char) i) == 'I' || ((char) i) == 'O'
                        || ((char) i) == 'U') {
                    System.out.println("Position = " + j + ",vowel = " + (char) i);
                }
                j++;
            }

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
