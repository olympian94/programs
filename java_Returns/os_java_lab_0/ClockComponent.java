import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;

public class ClockComponent extends JComponent
{
    final int CENTER = 150;
    final double HOUR_HAND_LENGTH = 20;
    final double MINUTE_HAND_LENGTH = 40;

    private Line2D.Double hourHand;
    private Line2D.Double minuteHand;

    public ClockComponent(double hour, double minute)
    {
        setPreferredSize(new Dimension(300,300));
        hourHand = new Line2D.Double(CENTER, CENTER, 
                CENTER, CENTER - HOUR_HAND_LENGTH);
        minuteHand = new Line2D.Double(CENTER, CENTER, 
                CENTER, CENTER - MINUTE_HAND_LENGTH);

        final int HOURS_ON_CLOCK = 12;
        final int MINUTES_IN_HOUR = 60;
        final double HOURS_TO_RADIANS = 2 * Math.PI / HOURS_ON_CLOCK;
        final double MINUTES_TO_RADIANS = 2 * Math.PI / MINUTES_IN_HOUR;

        hourHand.setLine(CENTER, CENTER, CENTER + HOUR_HAND_LENGTH * 
                Math.sin((hour + minute / MINUTES_IN_HOUR) * HOURS_TO_RADIANS), 
                CENTER - HOUR_HAND_LENGTH * 
                Math.cos((hour + minute / MINUTES_IN_HOUR) * HOURS_TO_RADIANS));
        minuteHand.setLine(CENTER, CENTER,
                CENTER + MINUTE_HAND_LENGTH * Math.sin(minute * MINUTES_TO_RADIANS),
                CENTER - MINUTE_HAND_LENGTH * Math.cos(minute * MINUTES_TO_RADIANS));
    }

    public void paintComponent(Graphics g)
    {
        final int DIAMETER = 100;
        final int POS_X_Y = CENTER - DIAMETER / 2;

        Graphics2D g2 = (Graphics2D) g;

        Ellipse2D.Double clockFace = 
                new Ellipse2D.Double(POS_X_Y, POS_X_Y, DIAMETER, DIAMETER);

        g2.draw(clockFace);
        g2.draw(hourHand);
        g2.draw(minuteHand);
    }

    public static void main(String[] args)
    {
        JFrame frame = new JFrame();
        frame.setTitle("Clock viewer");
        // bad practice
        //frame.setSize(500, 500);
        JPanel panel = new JPanel();

        ClockComponent comps = new ClockComponent(7, 40);

        panel.add(comps);
        frame.add(panel);
        // Good practice.
        frame.pack();

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}