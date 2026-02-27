package OOP.Lab5;

class Product {
    int PID;
    String name;
    int CID;
    float unitPrice;
}

class ElectricalProduct extends Product {
    int VoltageRange;
    int Wattage;

    ElectricalProduct(int PID, String name, int CID, float unitPrice, int VoltageRange, int Wattage) {
        this.PID = PID;
        this.name = name;
        this.CID = CID;
        this.unitPrice = unitPrice;
        this.VoltageRange = VoltageRange;
        this.Wattage = Wattage;
    }

    void change(float unitPrice, int Wattage) {
        this.unitPrice = unitPrice;
        this.Wattage = Wattage;
    }

    void display() {
        System.out.println("PID = " + PID);
        System.out.println("Product name = " + name);
        System.out.println("CID = " + CID);
        System.out.println("Per unit price = " + unitPrice);
        System.out.println("VoltageRange = " + VoltageRange);
        System.out.println("Wattage = " + Wattage);
    }
}

class Q3 {
    public static void main(String[] args) {
        ElectricalProduct P1 = new ElectricalProduct(123, "Machine", 1234, 20.0f, 5, 5);
        System.out.println("After changing the price and wattage : ");
        System.out.println();

        P1.display();
        P1.change(30.0f, 10);
        System.out.println();
        System.out.println("After changing the price and wattage : ");
        System.out.println();
        P1.display();

    }
}