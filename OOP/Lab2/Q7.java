package OOP.Lab2;

class time {
    int hours;

    double charges(int Time) {
        double charge = 0;
        if (Time > 3 && Time != 24) {
            charge = 2 + (Time - 3) * 0.5;
        } else if (Time == 24) {
            charge = 10;
        } else {
            charge = 2;
        }
        return charge;
    }
}

public class Q7 {
    public static void main(String[] args) {
        time customer1 = new time();
        time customer2 = new time();
        time customer3 = new time();
        customer1.hours = 13;
        customer2.hours = 24;
        customer3.hours = 2;
        System.out.println("Customer 1's charges are " + customer1.charges(customer1.hours));
        System.out.println("Customer 2's charges are " + customer2.charges(customer2.hours));
        System.out.println("Customer 3's charges are " + customer3.charges(customer3.hours));
        System.out.println("Total of yestarday's is " + (customer1.charges(customer1.hours)
                + customer2.charges(customer2.hours) + customer3.charges(customer3.hours)));
    }
}
