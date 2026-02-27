package OOP.Lab5;

class Overflow extends Exception {
    Overflow() {
        System.out.println("Queue is full");
    }
}

class Underflow extends Exception {
    Underflow() {
        System.out.println("Queue is empty");
    }
}

interface QueueImpl {
    void Insert() throws Overflow;

    void delete() throws Underflow;

    int display();
}

class QueueDemo implements QueueImpl {
    int[] arr = new int[10];
    int start = -1;
    int end = -1;

    public void Insert() throws Overflow {
        if (end == 9) {
            throw new Overflow();
        }
        if (start == end || start == -1) {
            start++;
            end++;
        } else {
            end++;
        }

        arr[end] = 1;

    }

    public void delete() throws Underflow {
        if (end == -1) {
            throw new Underflow();
        }
        if (start == end) {
            start--;
            end--;
        } else {
            end--;
        }

    }

    public int display() {
        return end + 1;
    }
}

public class Q1 {
    public static void main(String[] args) {
        QueueDemo Q = new QueueDemo();
        try {
            for (int i = 0; i < 11; i++) {
                Q.Insert();
            }
        } catch (Overflow e) {

        }
        try {
            for (int i = 0; i < 10; i++) {
                Q.delete();
            }
        } catch (Underflow e) {

        }
        System.out.println("Number of people in line : " + Q.display());

    }
}
