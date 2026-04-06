package Assignment;

import java.util.Scanner;

public class ScannerUtil {

    private static final Scanner sc = new Scanner(System.in);

    public static Scanner getInstance() {
        return sc;
    }

    public static void close() {
        sc.close();
    }
}