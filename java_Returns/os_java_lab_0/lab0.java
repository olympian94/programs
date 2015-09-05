import java.awt.geom.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

import java.text.SimpleDateFormat;
import java.util.Calendar;

class ClockComponent extends JComponent
{
    final int CENTER = 100;
    final double HOUR_HAND_LENGTH = 25;
    final double MINUTE_HAND_LENGTH = 40;
    final double SECOND_HAND_LENGTH = 55;

    private Line2D.Double hourHand;
    private Line2D.Double minuteHand;
    private Line2D.Double secondHand;

    public ClockComponent(double hour, double minute, double second)
    {
        setPreferredSize(new Dimension(300,300));
        hourHand = new Line2D.Double(CENTER, CENTER, 
                CENTER, CENTER - HOUR_HAND_LENGTH);
        minuteHand = new Line2D.Double(CENTER, CENTER, 
                CENTER, CENTER - MINUTE_HAND_LENGTH);
        secondHand = new Line2D.Double(CENTER, CENTER, 
                CENTER, CENTER - SECOND_HAND_LENGTH);

        final int HOURS_ON_CLOCK = 12;
        final int MINUTES_IN_HOUR = 60;
        final int SECONDS_IN_MINUTE = 60;
        final double HOURS_TO_RADIANS = 2*Math.PI / HOURS_ON_CLOCK;
        final double MINUTES_TO_RADIANS = 2 * Math.PI / MINUTES_IN_HOUR;
	    final double SECONDS_TO_RADIANS = 2 * Math.PI / SECONDS_IN_MINUTE;

/*secangle = sec* ((2*Math.PI)/60);
    minangle = (min + sec/60)*((2*Math.PI)/60);
    hrangle = (hr + min/60 +sec/(60*60))*((2*Math.PI)/12);
*/
        hourHand.setLine(CENTER, CENTER, CENTER + HOUR_HAND_LENGTH * 
                Math.sin((hour + minute / 60 + second/(60*60)) * HOURS_TO_RADIANS), 
                CENTER - HOUR_HAND_LENGTH * 
                Math.cos((hour + minute / 60 + second/(60*60)) * HOURS_TO_RADIANS));
        minuteHand.setLine(CENTER, CENTER,
                CENTER + MINUTE_HAND_LENGTH * Math.sin((minute +second/60) * MINUTES_TO_RADIANS),
                CENTER - MINUTE_HAND_LENGTH * Math.cos((minute +second/60)  * MINUTES_TO_RADIANS));
        secondHand.setLine(CENTER, CENTER,
                CENTER + SECOND_HAND_LENGTH * Math.sin(second * SECONDS_TO_RADIANS),
                CENTER - SECOND_HAND_LENGTH * Math.cos(second * SECONDS_TO_RADIANS));
    }

    public void paintComponent(Graphics g)
    {
        final int DIAMETER = 150;
        final int POS_X_Y = CENTER - DIAMETER / 2;

        Graphics2D g2 = (Graphics2D) g;

        Ellipse2D.Double clockFace = 
                new Ellipse2D.Double(POS_X_Y, POS_X_Y, DIAMETER, DIAMETER);

        g2.draw(clockFace);
        g2.draw(hourHand);
        g2.draw(minuteHand);
        g2.draw(secondHand);
    }

/*    public void drawClock(double hr_arg, double min_arg, double sec_arg)
    {
        JFrame frame = new JFrame();
        frame.setTitle("Clock viewer");
        // bad practice
        //frame.setSize(500, 500);
        JPanel panel = new JPanel();

        ClockComponent comps = new ClockComponent(hr_arg, min_arg, sec_arg);

        panel.add(comps);
        frame.add(panel);
        // Good practice.
        frame.pack();

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
*/
/*    public void updateClock(double hr_arg, double min_arg, double sec_arg)
    {

    }
*/ }
class tasks{
	JFrame frame;
	JPanel mainPanel, clockPanel;
	//place the buttons etc here because we are using anonymous classes as listeners. These variables have to be accessed by the anonymous
	//classes which will innerclasses to the function 'createAndShowGUI' and hence these cannot be local variable of that function.
	JButton button, clearButton, clockRefresh;
	JTextField inputField;
	JLabel actionLabel;
	int noOfClicks;
	Color[] all_colors;
	double hour, minute,second;
	ClockComponent clock1;
    void getDateTime()
    {
    	Calendar now = Calendar.getInstance();
		hour = now.get(Calendar.HOUR_OF_DAY);
		if (hour>12)
			hour-=12;
		minute = now.get(Calendar.MINUTE);
		second = now.get(Calendar.SECOND);
		
    }	

	public void createAndShowGUI()
	{
		frame = new JFrame();
		frame.setSize(400,600);
		frame.setVisible(true);
		frame.setTitle("Lab0");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//configure main panel
		mainPanel = new JPanel();
		mainPanel.setLayout(new GridLayout(0,1));

		//colors for buttons
		all_colors = new Color[7];
		all_colors[0] = Color.RED;
		all_colors[1] = Color.BLUE;
		all_colors[2] = Color.GREEN;
		all_colors[3] = Color.BLACK;
		all_colors[4] = Color.WHITE;
		all_colors[5] = Color.MAGENTA;
		


		//button to show no of clicks
		button = new JButton("Click Counter");
		all_colors[6] = button.getBackground();
		noOfClicks=0;
		button.setText("Clicks: "+Integer.toString(noOfClicks));
		button.addActionListener(new ActionListener() 
        {
			public void actionPerformed(ActionEvent e)
            {
                noOfClicks++;
                button.setText("Clicks: "+Integer.toString(noOfClicks));
                int rand = (int)(Math.random()*6);
                button.setBackground(all_colors[rand]);
            }
        });

		//clear counter button
		clearButton = new JButton("Clear Counter");
		clearButton.setText("Clear Counter");
		clearButton.addActionListener(new ActionListener() 
        {
			public void actionPerformed(ActionEvent e)
            {
                noOfClicks=0;
                button.setText("Clicks: "+Integer.toString(noOfClicks));
                button.setBackground(all_colors[6]);
            }
        });		

        JPanel buttonpanel = new JPanel();
        buttonpanel.setLayout(new GridLayout(0,2));
        buttonpanel.add(button);
        buttonpanel.add(clearButton);

        //text field panel
        JPanel textFieldPanel = new JPanel();
        //create text field
        inputField = new JTextField();
        //create a message label to display what the user typed
        actionLabel = new JLabel();
        actionLabel.setText("Type something in the Field and press Enter");
        //add listener for the textfield.Its called when the user enters something and presses enter
		inputField.addActionListener(new ActionListener() 
        {
			public void actionPerformed(ActionEvent e)
            {
                JTextField source = (JTextField)e.getSource();
            	actionLabel.setText("You typed \"" + source.getText() + "\"");
            }
        });
		//add the textfield and the action label to a panel
		textFieldPanel.setLayout(new GridLayout(0,1));
		textFieldPanel.add(inputField);
		textFieldPanel.add(actionLabel);


		//add text field panel to mainpanel
		mainPanel.add(textFieldPanel);
		//add button panel to mainpanel
		mainPanel.add(buttonpanel);
		//add mainpanel to frame
		frame.setContentPane(mainPanel);

		//add a clock component 
		getDateTime();
        clock1 = new ClockComponent(hour,minute,second);

		//button to refresh clock
		clockRefresh = new JButton();
		clockRefresh.setText("Refresh Clock");

		clockPanel = new JPanel();
		clockPanel.setLayout(new GridLayout(0,2));
		clockPanel.add(clock1);
		clockPanel.add(clockRefresh);
		mainPanel.add(clockPanel);		
		clockRefresh.addActionListener(new ActionListener() 
        {
			public void actionPerformed(ActionEvent e)
            {
           		mainPanel.remove(clockPanel);
           		frame.repaint();
           		frame.revalidate();

            	//nullify old component
                clock1 = null;
                //reinitialize clock component with current time
                getDateTime();
                clock1 = new ClockComponent(hour,minute,second);
                mainPanel.add(clockPanel);
                System.out.println(hour+" "+minute+" "+second);
                frame.repaint();
           		frame.revalidate();
            }
        });

	}
}

public class lab0{
	public static void main(String[] args) {
		tasks app = new tasks();
		app.createAndShowGUI();
	}
}