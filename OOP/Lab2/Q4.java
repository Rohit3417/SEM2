package OOP.Lab2;

class Date {
    int month;
    int day;
    int year;

    Date(int month, int day, int year) {
        this.month = month;
        this.day = day;
        this.year = year;
    }

    int getMonth() { // GETTER METHOD
        return month;
    }

    int getDay() { // GETTER METHOD
        return day;
    }

    int getYear() { // GETTER METHOD
        return year;
    }

    void setMonth(int month) { // SETTER METHOD
        this.month = month;
    }

    void setDay(int day) { // SETTER METHOD
        this.day = day;
    }

    void setYear(int year) { // SETTER METHOD
        this.year = year;
    }

    void DisplayDate() {
        System.out.println("Date is given as : " + day + "/" + month + "/" + year);
    }
}

public class Q4 {
    public static void main(String[] args) {
        Date by1 = new Date(12, 12, 2026);
        System.out.println("Initial date");
        by1.DisplayDate();
        by1.setMonth(11);
        by1.setDay(03);
        by1.setYear(2007);
        System.out.println("Changed date using set method :");
        by1.DisplayDate();
    }
}
