package OOP.practice;

public class Array1 { // Creating array to store multiple variables in single data type
    public static void main(String[] args) {
        int[] age = new int[3];
        String[] cars = new String[3];
        age[0] = 18;
        age[1] = 23;
        age[2] = 15;
        for (int i = 0; i < age.length; i++) {
            System.out.println(age[i]);
        }
        cars[0] = "Tesla";
        cars[1] = "nano";
        cars[2] = "Tata";
        for (int i = 0; i < cars.length; i++) {
            System.out.println(cars[i]);
        }
        // Defining 2D array
        String[][] car2 = new String[2][2];
        car2[0][1] = "Nexon";
        car2[0][0] = "Bajaj";
        car2[1][0] = "hh";
        car2[1][1] = "dskugu";
        for (int i = 0; i < car2.length; i++) {
            for (int j = 0; j < car2[i].length; j++) {
                System.out.print(car2[i][j] + " ");
            }
            System.out.println();
        }
    }
}