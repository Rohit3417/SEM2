package OOP.practice;

import java.util.ArrayList;

public class ListArray {
    public static void main(String[] args) {
        // Array list are resizable array
        // Elements can be added and removed after compilation phase
        // store reference data types

        ArrayList<String> food = new ArrayList<String>(); // for primitive data types we need wrapper class

        food.add("pizza");
        food.add("Burger");
        food.add("Sandwich");

        food.set(0, "nachos");
        food.remove(2);
        // printing the list
        for (int i = 0; i < food.size(); i++) {
            System.out.println(food.get(i));
        }

        food.clear(); // Removes all the elements
        for (int i = 0; i < food.size(); i++) {
            System.out.println(food.get(i));
        }
    }
}
