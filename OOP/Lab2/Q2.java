//Use CONSTRUCTORS !!!!!!
/*
setters and getters help to protect object data and add rules for accessing or modifying 
Setters = Methods that make a field writable
Getters = Methods that make a field readable
*/
package OOP.Lab2;

class Invoice {
    private String num;
    private String descr; // Description
    private int quantity;
    private int price;

    Invoice(String num, String descr, int quantity, int price) { // This is the constructor
        this.num = num;
        this.descr = descr;
        this.quantity = quantity;
        this.price = price;
    }

    String getNum() {
        return num;
    }

    String getDescr() {
        return descr;
    }

    void setQuantity(int quantity) {
        if (quantity < 0) {
            this.quantity = 0;
        } else
            this.quantity = quantity;
    }

    int getQuantity() {
        return quantity;
    }

    void setPrice(int price) {
        if (price < 0) {
            this.price = 0;
        } else
            this.price = price;
    }

    int getPrice() {
        return price;
    }

    double getInvoiceAmount() {
        return (quantity * price);
    }
}

public class Q2 {
    public static void main(String[] args) {
        Invoice customer1 = new Invoice("12P32", "udhgiud", 3, 100);
        System.out.println("Part number is " + customer1.getNum());
        System.out.println("Description is " + customer1.getDescr());
        System.out.println("Net quantity of item is " + customer1.getQuantity());
        System.out.println("Price of each item is " + customer1.getPrice());
        System.out.println("Total amount is " + customer1.getInvoiceAmount());

        customer1.setQuantity(5);
        customer1.setPrice(200);
        System.out.println("After changing the quantity and price of the amount");
        System.out.println("Total amount is " + customer1.getInvoiceAmount());

    }
}
