package OOP.Lab4;

interface Function {
    int Evaluate(int a);
}

class Half implements Function {

    public int Evaluate(int a) {
        return (a / 2);
    }
}

public class Q6 {
    public static void main(String[] args) {
        Function h = new Half();
        int p = 2;
        System.out.println("Half of the given value of p is : " + h.Evaluate(p));
        int arr[] = { 2, 4, 6, 8, 10 };
        System.out.print("Initial Array : ");
        for (int i = 0; i < 5; i++) {
            System.out.print(arr[i] + " ");
        }
        for (int i = 0; i < 5; i++) {
            arr[i] = h.Evaluate(arr[i]);
        }
        System.out.print("\nAfter halving the Array will be : ");
        for (int i = 0; i < 5; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
