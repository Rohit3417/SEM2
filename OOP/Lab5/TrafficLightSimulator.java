package OOP.Lab5;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

// 1. The Main GUI Class
public class TrafficLightSimulator extends JPanel {

    // Constants for positions
    private static final int WIDTH = 800;
    private static final int HEIGHT = 400;
    private static final int ROAD_Y = 250;
    private static final int LIGHT_X = 550;

    // State Variables
    private LightColor currentColor = LightColor.RED; // Start Red
    private int carX = 0; // Car starts at left edge
    private int carSpeed = 5;

    public TrafficLightSimulator() {
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setBackground(Color.CYAN); // Sky color

        // Start the Traffic Light Timer (Independent Thread)
        new Thread(new TrafficLightLogic()).start();

        // Start the Animation Loop (Moves the car)
        Timer timer = new Timer(30, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                moveCar();
                repaint(); // Redraw everything
            }
        });
        timer.start();
    }

    // 2. The Logic to Move the Car
    private void moveCar() {
        // Stop logic: If light is RED and car is near the stop line
        if (currentColor == LightColor.RED && carX >= LIGHT_X - 120 && carX < LIGHT_X - 100) {
            return; // Don't move (STOP)
        }

        // Slow down logic: If YELLOW, move slower
        if (currentColor == LightColor.YELLOW) {
            carX += 2;
        } else {
            carX += carSpeed; // Normal speed
        }

        // Loop car back to start if it leaves screen
        if (carX > WIDTH) {
            carX = -100;
        }
    }

    // 3. The Drawing Logic (Paint)
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        // -- Draw Road --
        g.setColor(Color.GRAY);
        g.fillRect(0, ROAD_Y, WIDTH, 100);
        g.setColor(Color.WHITE);
        for (int i = 0; i < WIDTH; i += 40) { // Lane markings
            g.fillRect(i, ROAD_Y + 45, 20, 5);
        }

        // -- Draw Traffic Light Box --
        g.setColor(Color.BLACK);
        g.fillRect(LIGHT_X, 50, 60, 160); // The pole/box
        g.fillRect(LIGHT_X + 25, 210, 10, ROAD_Y - 210); // The post

        // -- Draw The Lights --
        // Red
        if (currentColor == LightColor.RED)
            g.setColor(Color.RED);
        else
            g.setColor(new Color(50, 0, 0)); // Dim Red
        g.fillOval(LIGHT_X + 15, 60, 30, 30);

        // Yellow
        if (currentColor == LightColor.YELLOW)
            g.setColor(Color.YELLOW);
        else
            g.setColor(new Color(50, 50, 0)); // Dim Yellow
        g.fillOval(LIGHT_X + 15, 100, 30, 30);

        // Green
        if (currentColor == LightColor.GREEN)
            g.setColor(Color.GREEN);
        else
            g.setColor(new Color(0, 50, 0)); // Dim Green
        g.fillOval(LIGHT_X + 15, 140, 30, 30);

        // -- Draw Car --
        g.setColor(Color.BLUE);
        g.fillRect(carX, ROAD_Y + 20, 80, 40); // Car Body
        g.setColor(Color.BLACK);
        g.fillOval(carX + 10, ROAD_Y + 50, 20, 20); // Wheel 1
        g.fillOval(carX + 50, ROAD_Y + 50, 20, 20); // Wheel 2

        // -- Draw Text Info --
        g.setColor(Color.BLACK);
        g.drawString("Current Light: " + currentColor, 20, 30);
    }

    // 4. The Traffic Light Timing Logic (Runnable)
    // This runs in the background so it doesn't freeze the GUI
    private class TrafficLightLogic implements Runnable {
        @Override
        public void run() {
            try {
                while (true) {
                    // RED (Stop)
                    currentColor = LightColor.RED;
                    Thread.sleep(4000); // 4 Seconds

                    // GREEN (Go)
                    currentColor = LightColor.GREEN;
                    Thread.sleep(4000); // 4 Seconds

                    // YELLOW (Slow)
                    currentColor = LightColor.YELLOW;
                    Thread.sleep(2000); // 2 Seconds
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    // Enum for readability
    enum LightColor {
        RED, YELLOW, GREEN
    }

    // 5. Main Method to Start App
    public static void main(String[] args) {
        JFrame frame = new JFrame("Java Traffic Light Simulator");
        TrafficLightSimulator sim = new TrafficLightSimulator();

        frame.add(sim);
        frame.pack(); // Sizes frame to fit the panel
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center on screen
        frame.setVisible(true);
    }
}