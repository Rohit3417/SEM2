import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of circle");
        int radius = sc.nextInt();
        System.out.println("Diameter of circle is " + (radius * 2));
        System.out.println("Circumference is " + (2 * Math.PI * radius));
        System.out.println("Area of the circle is " + (Math.PI * radius * radius));
        sc.close();
    }

}
