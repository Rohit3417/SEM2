package OOP.Lab5;

import java.util.Scanner;

class NotHex extends Exception {
    NotHex() {
        System.out.println("Not an Hexadecimal number");
    }

}

class check {
    void ifHex(String num) throws NotHex {
        if (!num.matches("[0-9A-Fa-f]+"))
            throw new NotHex();
    }
}

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        check q = new check();
        String num;
        System.out.print("Enter the number to check : ");
        num = sc.next();
        try {
            q.ifHex(num);
            System.out.println("Hexadecimal number is " + num);
        } catch (NotHex e) {

        } finally {
            System.out.println("Ending program");
        }
        sc.close();
    }
}
