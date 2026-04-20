package OOP.Lab9;

import java.util.Stack;

class SharedData {
    String postfix;
    String infix = "";
    boolean part1Done = false;
    boolean part2Done = false;
}

// Thread 1: Convert Postfix → Infix
class ConvertThread extends Thread {

    SharedData data;

    ConvertThread(SharedData data) {
        this.data = data;
    }

    @Override
    public void run() {
        setName("ConvertThread");
        System.out.println(getName() + " Starting postfix to infix conversion...");

        Stack<String> stack = new Stack<>();

        for (int i = 0; i < data.postfix.length(); i++) {
            char c = data.postfix.charAt(i);

            // ── If operand, push to stack ──
            if (Character.isLetterOrDigit(c)) {
                stack.push(String.valueOf(c));
            }

            // ── If operator, pop two operands and form expression ──
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                String operand2 = stack.pop();
                String operand1 = stack.pop();
                String expr = operand1 + c + operand2;
                stack.push(expr);
            }
        }

        data.infix = stack.pop();

        System.out.println(getName() + " Conversion done : " + data.infix);

        // Notify DisplayThread
        synchronized (data) {
            data.part1Done = true;
            data.notify();
        }
    }
}

// Thread 2: Display the Result
class DisplayThread extends Thread {

    SharedData data;

    DisplayThread(SharedData data) {
        this.data = data;
    }

    @Override
    public void run() {
        setName("DisplayThread");

        // Wait until ConvertThread finishes
        synchronized (data) {
            while (!data.part1Done) {
                try {
                    data.wait(); // sleep until notified
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }

        System.out.println(getName() + " Received result, displaying...");

        // Display full breakdown

        System.out.println("Postfix (Polish) : " + data.postfix);
        System.out.printf("Infix Expression : " + data.infix);

        synchronized (data) {
            data.part2Done = true;
            data.notify();
        }
    }
}

public class Q5 {
    public static void main(String[] args) {

        // Postfix expressions to convert
        String expressions = "AB*CD/+";

        System.out.println("  Input Postfix : " + expressions);
        System.out.println("──────────────────────────────────────────");

        SharedData data = new SharedData();
        data.postfix = expressions;

        ConvertThread converter = new ConvertThread(data);
        DisplayThread displayer = new DisplayThread(data);

        // Start both threads
        converter.start();
        displayer.start();

        // Wait for DisplayThread to finish before next round
        synchronized (data) {
            try {
                data.wait();
            } catch (InterruptedException e) {
                System.out.println(e);
            }

        }
        System.out.println("\n Conversions complete!");

    }
}
