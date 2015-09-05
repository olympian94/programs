import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

public class ClockPanel extends JPanel {

  final int XCENTER = 100;
  final int YCENTER = 100;
  final double HOUR_HAND_LENGTH = 20;
  final double MINUTE_HAND_LENGTH = 30;
  final double SECOND_HAND_LENGTH = 40;
  int hr;
  int min;
  int sec;
  double secangle;
  double minangle;
  double hrangle;

  /** Main method */
  public static void main(String[] args) {
    JFrame frame = new JFrame("DrawMessage");
    frame.getContentPane().add(new ClockPanel());
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(300, 200);
    frame.setVisible(true);
  }
    /** Paint the message */
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    hr=12;
    min=10;
    sec=15;

    secangle = sec* ((2*Math.PI)/60);
    minangle = (min + sec/60)*((2*Math.PI)/60);
    hrangle = (hr + min/60 +sec/(60*60))*((2*Math.PI)/12);

    //draw hour hand
    g.drawLine(XCENTER, YCENTER, (int)(XCENTER - HOUR_HAND_LENGTH*Math.sin(Math.PI/2-hrangle)), (int)(YCENTER - HOUR_HAND_LENGTH*Math.cos(Math.PI/2-hrangle)));
    //draw min hand
    g.drawLine(XCENTER, YCENTER, (int)(XCENTER - MINUTE_HAND_LENGTH*Math.sin(Math.PI/2-minangle)), (int)(YCENTER - MINUTE_HAND_LENGTH*Math.cos(Math.PI/2-minangle)));
    //draw sec hand
    g.drawLine(XCENTER, YCENTER, (int)(XCENTER - SECOND_HAND_LENGTH*Math.sin(Math.PI/2-secangle)), (int)(XCENTER - SECOND_HAND_LENGTH*Math.cos(Math.PI/2-secangle)));
    g.drawOval(XCENTER, YCENTER, 250, 250);

  }
}