

/*  AnonymousClassAppUseDemo.java */
 
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
 
class AnonymousClassAppUseDemo
{
    public static void main(String[] args)
    {
        GreetingFrame hwf = new GreetingFrame();
        hwf.CreateFrame();
    }
}
 
class GreetingFrame
{
    private JFrame frame;
    private JPanel messagePanel;
    private JPanel buttonPanel;
    private JPanel container;
    private JLabel messageLabel;
    private JButton greetButton;
    private JButton clearButton;
 
    public GreetingFrame ()
    {
        //beautify the frame
        JFrame.setDefaultLookAndFeelDecorated(true);
 
        frame = new JFrame("Hello World");
        messagePanel = new JPanel(); //used to place greeting message
        buttonPanel = new JPanel(); //used to place command button
        container = new JPanel(); //used to place message and button Panels
        messageLabel = new JLabel(" "); // contain greeting message
        greetButton = new JButton("Greeting"); //display greeting message when clicked
        clearButton = new JButton("Clear"); //clears greeting message when clicked
    }
 
    public void CreateFrame ()
    {        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS));
        messagePanel.add(messageLabel);
        buttonPanel.add(greetButton);
        buttonPanel.add(clearButton);
 
        /* brand new class of super type ActionListener
         * will be created anonymously and passed to addActionListener method
         * of greetButton object
         */
        greetButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e)
            {
                messageLabel.setText("Hello User! Greetings of the day!");
            }
        });
 
        /* brand new class of super type ActionListener
         * will be created anonymously and passed to addActionListener method
         * of clearButton object
         */
        clearButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e)
            {
                messageLabel.setText(" ");
            }
         });
 
         container.add(messagePanel);
         container.add(buttonPanel);
         frame.getContentPane().add(container);
         //Display the window.
         frame.setSize(300, 200);
         frame.setLocationByPlatform(true);
         frame.setVisible(true);
    }
}
