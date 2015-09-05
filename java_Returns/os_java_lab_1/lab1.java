import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

public class lab1 extends JFrame{
		private JTextField textField;
		private JButton buttonA, buttonB, buttonC, buttonD;
		private int[] total_no_of_clicks = new int [4];
		public lab1(){
			super("lab1");
			Container c = getContentPane();
			c.setLayout(new GridLayout(0,1));

			textField = new JTextField("You clicked on : ");
			c.add(textField);

			total_no_of_clicks[0] = 0;
			total_no_of_clicks[1] = 0;
			total_no_of_clicks[2] = 0;
			total_no_of_clicks[3] = 0;

			buttonA = new JButton();
			buttonA.setText("A"+"   clicks = "+Integer.toString(total_no_of_clicks[0]));
			buttonB = new JButton();
			buttonB.setText("B"+"   clicks = "+Integer.toString(total_no_of_clicks[1]));
			buttonC = new JButton();
			buttonC.setText("C"+"   clicks = "+Integer.toString(total_no_of_clicks[2]));
			buttonD = new JButton();
			buttonD.setText("D"+"   clicks = "+Integer.toString(total_no_of_clicks[3]));

			buttonA.addActionListener(new ActionListener() 
        	{
				public void actionPerformed(ActionEvent e)
            	{
	                total_no_of_clicks[0]++;
                	buttonA.setText("A"+"   clicks = "+Integer.toString(total_no_of_clicks[0]));
					String prefix = textField.getText();
					prefix += " A";
					textField.setText(prefix);
            	}
        	});

        	buttonB.addActionListener(new ActionListener() 
        	{
				public void actionPerformed(ActionEvent e)
            	{
	                total_no_of_clicks[1]++;
                	buttonB.setText("B"+"   clicks = "+Integer.toString(total_no_of_clicks[1]));
					String prefix = textField.getText();
					prefix += " B";
					textField.setText(prefix);
            	}
        	});

        	buttonC.addActionListener(new ActionListener() 
        	{
				public void actionPerformed(ActionEvent e)
            	{
	                total_no_of_clicks[2]++;
                	buttonC.setText("C"+"   clicks = "+Integer.toString(total_no_of_clicks[2]));
					String prefix = textField.getText();
					prefix += " C";
					textField.setText(prefix);
            	}
        	});

        	buttonD.addActionListener(new ActionListener() 
        	{
				public void actionPerformed(ActionEvent e)
            	{
	                total_no_of_clicks[3]++;
                	buttonD.setText("D"+"   clicks = "+Integer.toString(total_no_of_clicks[3]));
					String prefix = textField.getText();
					prefix += " D";
					textField.setText(prefix);
            	}
        	});

        	c.add(buttonA);
        	c.add(buttonB);
        	c.add(buttonC);
        	c.add(buttonD);

        	setSize(300,200);
			setVisible(true);
			setDefaultCloseOperation(EXIT_ON_CLOSE);
		}

		public static void main(String[] args) {
			new lab1();
		}
}