package OOP.Lab6;

import java.util.Scanner;

class Model3D {
    int x, y, z;

    Model3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

public class Q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Model3D point = new Model3D(0, 0, 0);
        System.out.print("Enter the coordinates of a point : ");
        point.x = sc.nextInt();
        point.y = sc.nextInt();
        point.z = sc.nextInt();

        System.out.println("Input coordinates are : (" + point.x + "," + point.y + "," + point.z + ")");
        double dist;
        dist = Math.sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
        System.out.println("Distance of the given point from origin is " + dist);
        sc.close();
    }
}
