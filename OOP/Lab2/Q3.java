package OOP.Lab2;

class Employee {
    String name;
    String LastName; // Instance variables
    double salary;

    Employee(String name, String LastName, double salary) {
        this.name = name;
        this.LastName = LastName;
        this.salary = salary;
    }

}

public class Q3 {
    public static void main(String[] args) {
        Employee e1 = new Employee("Rohit", "Mandale", 1200);
        Employee e2 = new Employee("EG", "Man", 120);
        System.out.println("Yearly salary of employee 1 is " + e1.salary);
        System.out.println("Yearly salary of employee 2 is " + e2.salary);

        e1.salary += e1.salary / 10;
        e2.salary += e2.salary / 10;
        System.out.println("After 10% hike of these two employees their salaries are :");
        System.out.println("Yearly salary of employee 1 is " + e1.salary);
        System.out.println("Yearly salary of employee 2 is " + e2.salary);
    }
}
