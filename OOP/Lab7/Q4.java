package OOP.Lab7;

class Teacher {
    void call() {
        System.out.println("Teacher");
    }
}

class Student extends Teacher {
    void calls() {
        System.out.println("Student");
    }
}

public class Q4 {
    public static void main(String[] args) {
        Student s1 = new Student();
        System.out.println("Called by its own class");
        s1.calls();
        System.out.println();
        System.out.println("Called the method of its super class");
        s1.call();
    }
}
