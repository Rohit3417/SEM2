package OOP.Lab6;

import java.util.Scanner;

class Bank {

    float deposit(float amount, float balance) {
        balance += amount;
        return balance;
    }

    float withdraw(float amount, float balance) {
        balance -= amount;
        if (balance >= 0)
            return balance;
        else
            balance += amount;
        System.out.println("Insufficient balance");
        System.out.println("Amount witdrew = " + balance);
        return 0;
    }
}

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Bank customer1 = new Bank();
        float amount, balance;
        balance = 10000;
        System.out.print("Enter amount to deposit to the bank : ");
        amount = sc.nextFloat();
        balance = customer1.deposit(amount, balance);
        System.out.println("Balance for customer 1 : " + balance);
        System.out.println();
        System.out.print("Enter amount to withdraw from the bank : ");
        amount = sc.nextFloat();
        balance = customer1.withdraw(amount, balance);
        System.out.println("Balance for customer 1 : " + balance);
        sc.close();
    }
}
