package OOP.Lab2;

import java.util.Scanner;

class Info {
    float miles; // All are per day
    int cost; // cost of gasoline per day
    float avgfees;
    int tolls;

    double drivingCost(float miles, int cost, float avgfees, int tolls) {
        return (miles * cost + avgfees + tolls);
    }
}

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Info Person = new Info();
        System.out.println("Enter miles drove per day in Rs.");
        Person.miles = sc.nextFloat();
        System.out.println("Enter cost of gasoline per mile in Rs.");
        Person.cost = sc.nextInt();
        System.out.println("Enter average fees per day in Rs.");
        Person.avgfees = sc.nextFloat();
        System.out.println("Enter toll fees per day in Rs.");
        Person.tolls = sc.nextInt();
        double Tcost = Person.drivingCost(Person.miles, Person.cost, Person.avgfees, Person.tolls);
        System.out.println("Daily driving cost is " + Tcost);
        sc.close();
    }

}
