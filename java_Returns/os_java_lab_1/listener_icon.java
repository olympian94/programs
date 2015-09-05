import javax.swing.*;        
import java.awt.*;
import java.awt.event.*;

//example 1
/*class ButtonListener implements ActionListener {
   public void actionPerformed (ActionEvent e) {
       System.out.println ("Got a button press:" + e);
   }
}

class Main {
   public static void main(String[] args) {
        JFrame frame = new JFrame("Swing GUI");
        java.awt.Container content = frame.getContentPane();
        content.setLayout(new FlowLayout());
        content.add(new JLabel ("Yo!"));
        JButton button = new JButton ("Click Me");
        button.addActionListener(new ButtonListener());
        content.add(button);
        frame.pack();
        frame.setVisible(true);
    }
}
*/

//example2
//button specific event listeneres in one class
class ButtonListener implements ActionListener {

   public void actionPerformed (ActionEvent e) {

      if (e.getActionCommand().equals ("On")) {
         System.out.println("On!");
      } else if (e.getActionCommand().equals("Off")) {
         System.out.println("Off!");
      } else {
         System.out.println("Unrecognized button press!"); } } }


class CheckBoxHandler implements ItemListener {
    public void itemStateChanged( ItemEvent e )
    {}
}
class Main {
   public static void main(String[] args){
        JFrame frame = new JFrame("Swing GUI");
        java.awt.Container content = frame.getContentPane();
        content.setLayout(new FlowLayout());
        content.add(new JLabel ("Yo!"));

        frame.setVisible(true);

        ButtonListener bl = new ButtonListener();
        JButton onButton = new JButton ("On");
        onButton.addActionListener(bl);
        content.add(onButton);
        JButton offButton = new JButton ("Off");
        offButton.addActionListener(bl);
        content.add(offButton);

        Icon bug1 = new ImageIcon( "img.gif" );
        JButton fancyButton = new JButton("Fancy Button", bug1 );
        fancyButton.setRolloverIcon( bug1 );
        content.add(fancyButton);
    }
}