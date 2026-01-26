package OOP.Lab3;

abstract class Figure {
    double a, v;

    public abstract void calcArea();

    public abstract void calcVolume();

    public abstract void dispArea();

    public abstract void dispVolume();
}

class Cone extends Figure {
    double n, s; // n = radius of cone

    Cone(double n, double s) {
        this.s = s;
        this.n = n;
    }

    public void calcArea() {
        a = Math.PI * n * n + Math.PI * n * s;
    }

    public void calcVolume() {
        v = (Math.PI * n * n * s) / 3;
    }

    public void dispArea() {
        System.out.println("Area of cone is " + a);
    }

    public void dispVolume() {
        System.out.println("Volume of cone is " + v);
    }
}

class Sphere extends Figure {
    double r;

    Sphere(double r) {
        this.r = r;
    }

    public void calcArea() {
        a = 4 * Math.PI * r * r;
    }

    public void calcVolume() {
        v = (4 / 3) * (Math.PI * r * r * r);
    }

    public void dispArea() {
        System.out.println("Area of sphere is " + a);
    }

    public void dispVolume() {
        System.out.println("Volume of sphere is " + v);
    }
}

class Cylinder extends Figure {
    double h, r;

    Cylinder(double h, double r) {
        this.h = h;
        this.r = r;
    }

    public void calcArea() {
        a = 2 * Math.PI * r * r + 2 * Math.PI * r * h;
    }

    public void calcVolume() {
        v = Math.PI * r * r * h;
    }

    public void dispArea() {
        System.out.println("Area of cylinder is " + a);
    }

    public void dispVolume() {
        System.out.println("Volume of cylinder is " + v);
    }
}

public class Q2 {
    public static void main(String[] args) {
        Cone fig1 = new Cone(3.4, 12.0);
        fig1.calcArea();
        fig1.dispArea();
        fig1.calcVolume();
        fig1.dispVolume();
        System.out.println();
        Sphere fig2 = new Sphere(3.4);
        fig2.calcArea();
        fig2.dispArea();
        fig2.calcVolume();
        fig2.dispVolume();
        System.out.println();
        Cylinder fig3 = new Cylinder(5.0, 3.0);
        fig3.calcArea();
        fig3.dispArea();
        fig3.calcVolume();
        fig3.dispVolume();
    }
}
