package OOP.Lab4;

public class Q1 {
    static final int X = 2;
    static final int Y = 2;
    static final int Z = 2;

    static void set(int value, int indexX, int indexY, int indexZ, int[] Arr1D) {
        int index = indexX * (indexY * indexZ) + indexY * indexZ + indexZ;
        Arr1D[index] = value;
    }

    static int get(int indexX, int indexY, int indexZ, int[] Arr1D) {
        int index = indexX * (indexY * indexZ) + indexY * indexZ + indexZ;
        return Arr1D[index];
    }

    public static void main(String[] args) {

        int[] Arr1D = new int[X * Y * Z];
        set(10, 0, 0, 0, Arr1D);
        set(20, 0, 0, 1, Arr1D);
        set(30, 0, 1, 1, Arr1D);
        set(40, 1, 1, 1, Arr1D);

        System.out.println("Value at (0,0,0): " + get(0, 0, 0, Arr1D));
        System.out.println("Value at (0,0,1): " + get(0, 0, 1, Arr1D));
        System.out.println("Value at (0,1,1): " + get(0, 1, 1, Arr1D));
        System.out.println("Value at (1,1,1): " + get(1, 1, 1, Arr1D));
    }
}
