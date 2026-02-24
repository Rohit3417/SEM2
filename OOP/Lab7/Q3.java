package OOP.Lab7;

import java.util.Scanner;

class Book {
    int ID;
    String Title;
    String Author;
    float price;

    void display() {
        System.out.println("Book details are as follows :");
        System.out.println("Book ID = " + ID);
        System.out.println("Book Title = " + Title);
        System.out.println("Book Author = " + Author);
        System.out.println("Book price = " + price);
    }
}

class Periodical extends Book {
    String period = "weekly";

    void modify(float price, String period) {
        this.price = price;
        this.period = period;
    }
}

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Periodical book1 = new Periodical();

        System.out.print("Enter Book ID : ");
        book1.ID = sc.nextInt();

        System.out.print("Enter Book Title : ");
        book1.Title = sc.next();

        System.out.print("Enter Book Author : ");
        book1.Author = sc.next();

        System.out.print("Enter Book price : ");
        book1.price = sc.nextFloat();
        System.out.println("Period of book : " + book1.period);

        book1.display();
        System.out.println("Period of book : " + book1.period);
        book1.modify(100, "monthly");

        System.out.println("\nAfter updating :");
        book1.display();
        System.out.println("Period of book : " + book1.period);

        sc.close();
    }
}
