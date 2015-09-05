import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

public class DrawMessage extends JPanel {
  /** Main method */
  public static void main(String[] args) {
    JFrame frame = new JFrame("DrawMessage");
    frame.getContentPane().add(new DrawMessage());
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(300, 200);
    frame.setVisible(true);
  }
    /** Paint the message */
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.drawString("Welcome to Java!", 40, 40);
    GraphicsEnvironment e =  GraphicsEnvironment.getLocalGraphicsEnvironment();
    String[] fontnames =   e.getAvailableFontFamilyNames();
    for (int i = 0; i < fontnames.length; i++)
    {
      g.setFont(new Font(fontnames[i],Font.PLAIN,15));
      g.drawString(fontnames[i], 40, 40+(i*20+10));
    }

  }
}