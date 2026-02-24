package OOP.Lab7;

class Course {
    int ID;
    String description;
    float duration;
    float fees;

    Course(int ID, String description, float duration, float fees) {
        this.ID = ID;
        this.description = description;
        this.duration = duration;
        this.fees = fees;
    }

    void GetData(int i) {
        System.out.println("Data for member " + i + " is as follows : ");
        System.out.println(
                "ID : " + ID + "\nDescription : " + description + "\nduration : " + duration + "\nFees : " + fees);
    }
}

public class Q6 {
    public static void main(String[] args) {
        Course arr[] = new Course[5];
        arr[0] = new Course(1, "Java course", 2, 1000);
        arr[1] = new Course(2, "C++ course", 2, 1000);
        arr[2] = new Course(3, "Management course", 6, 3000);
        arr[3] = new Course(4, "DSA course", 3, 1500);
        arr[4] = new Course(5, "Python course", 2, 1000);
        for (int i = 0; i < 5; i++) {
            arr[i].GetData(i + 1);
            System.out.println();
        }
    }
}
