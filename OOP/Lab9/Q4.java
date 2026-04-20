package OOP.Lab9;

import java.util.Random;
import java.util.Scanner;

import WeatherApp.src.Main;

class Player1 extends Thread {
    int random = 0;
    int Score = 0;
    int input = 0;
    Random r = new Random();

    public void run() {
        setName("Player 1");
        Scanner sc = new Scanner(System.in);

        System.out.println(getName() + " : Enter a number : ");
        input = sc.nextInt();
        random = r.nextInt(1, 100) + 1;

        System.out.println(getName() + " : lucky number is : " + random);
        try {
            sleep(10);
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }

}

class Player2 extends Thread {
    int random = 0;
    int Score = 0;
    int input = 0;
    Random r = new Random();

    public void run() {
        setName("Player 2");
        Scanner sc = new Scanner(System.in);
        System.out.println(getName() + " : Enter a number : ");
        input = sc.nextInt();
        random = r.nextInt(1, 100) + 1;

        System.out.println(getName() + " : lucky number is : " + random);
        try {
            sleep(10);
        } catch (InterruptedException e) {
            System.out.println(e);
        }

    }
}

public class Q4 {
    public static void main(String[] args) {
        Player1 p1 = new Player1();
        Player2 p2 = new Player2();

        p1.start();
        try {
            p1.join(); // main waits until player1 finishes
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        p2.start();
        try {
            p2.join(); // main waits until player2 finishes
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        int diff = Math.abs(p1.random - p2.random);
        if (p1.random > p2.random) {
            System.out.println("Player1 Wins and points gained = " + diff);
        } else
            System.out.println("Player2 Wins and points gained = " + diff);
    }
}
