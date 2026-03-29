package OOP.FileHandling;

import java.io.File;
import java.io.IOException;

class CreatingFile {
    public static void main(String[] args) {
        File n = new File("D:\\Sem2\\Hello.txt");
        System.out.println(n.exists());
        try {

            n.createNewFile();
            System.out.println(n.exists());
        } catch (IOException e) {
            System.out.println(e);
        }
        System.out.println(n.isDirectory());
        System.out.println(n.isFile());
        System.out.println(n.canRead());
        System.out.println(n.canExecute());
        System.out.println(n.getName()); // Gives file name
        // n.delete();
        // System.out.println(n.exists()); //gives false as file is deleted
        // File dir = new File("D:\\Test");
        // dir.mkdir();
        // System.out.println(dir.isDirectory());
        // dir.delete();
        // System.out.println(dir.isDirectory());
        System.out.println(n.getAbsolutePath());
        System.out.println(n.isHidden());
        System.out.println(n.length()); // gave number of characters present in hello.kjhgtxt file
    }
}