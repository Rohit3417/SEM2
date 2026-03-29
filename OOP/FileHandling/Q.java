package OOP.FileHandling;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Q {

    public static void main(String[] args) {

        FileInputStream fis = null;
        FileOutputStream fos = null;
        File f1 = null;

        try {
            // Open file
            f1 = new File("D:\\images.jpg");
            fis = new FileInputStream(f1);

            // Read file
            long len = f1.length();
            byte[] all = new byte[(int) len];
            fis.read(all);

            // Write to new file
            fos = new FileOutputStream("D:\\images1.jpg");
            fos.write(all);

            // Print byte data
            for (int i = 0; i < all.length; i++) {
                System.out.print(" " + all[i]);
            }

        } catch (IOException ex) {
            ex.printStackTrace();
        } finally {
            try {
                if (fis != null) {
                    fis.close();
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }

            try {
                if (fos != null) {
                    fos.close();
                    fos = null;
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}