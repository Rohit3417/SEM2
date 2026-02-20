package OOP.Lab6;

import java.util.Scanner;

class TotalProfit {

    int numofattendee;
    int Income;
    int cost;

    float profit(int numofattendee) {
        float result;
        result = numofattendee * 5 - 20 - numofattendee * 0.5f;
        return result;
    }
}

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TotalProfit show1 = new TotalProfit();
        System.out.print("Enter number of attendees for show 1 : ");
        show1.numofattendee = sc.nextInt();
        float profit1 = show1.profit(show1.numofattendee);
        System.out.println("Thus profit of show 1 = " + profit1);
        sc.close();
    }
}
