package OOP.Lab3;

class figure {
    double r, a, v;

    public void dispArea() {
        System.out.println("Area of the cone is " + a);
    }

    public void dispVolume() {
        System.out.println("Volume of the cone is " + v);
    }
}

class cone extends figure {
    double h, s;

    void calcArea() { // Area of cone is pi*r*r+pi*r*s where s is slant height
        a = (Math.PI * r * r + Math.PI * r * s);
    }

    public void calcVolume() {
        v = (Math.PI * r * s) / 3;
    }
}

public class Q1 {
    public static void main(String[] args) {
        cone fig1 = new cone();
        fig1.r = 3.2;
        fig1.s = 15;
        fig1.calcArea();
        fig1.dispArea();
        fig1.calcVolume();
        fig1.dispVolume();
    }

}
