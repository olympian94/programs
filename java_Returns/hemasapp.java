import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class hemasapp_class{
	JFrame frame;
	JPanel panel;
	public void runapp()
	{
		frame = new JFrame();
		frame.setSize(400,300);
		frame.setVisible(true);
		frame.setLocation(500,200);
		
		panel = new JPanel();

		JButton[] arrayOfButtons = new JButton[10];
		int j;
		for(j=0; j<10; j++)
		{
			String label = Integer.toString(j+1);

			arrayOfButtons[j]= new JButton(label);
			arrayOfButtons[j].setText(label);

			panel.add(arrayOfButtons[j]);
		}
		panel.setLayout(new GridLayout(0,2));

		frame.setContentPane(panel);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
	}
}

public class hemasapp{
	public static void main(String[] args)
	{
		hemasapp_class app1 = new hemasapp_class();	
		app1.runapp();
	}
}