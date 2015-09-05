import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.border.EtchedBorder;


class theapp{
	JFrame frame;
	JLabel messageLabel;

	public void run(){
		frame = new JFrame("First App");
		frame.setSize(500,400);
		frame.setVisible(true);
		frame.setLocation(400,100);

		//will have buttons and text
		JPanel panelButtonsAndText = new JPanel();
		JPanel panelOnlyButtons = new JPanel();
		JPanel mainPanel = new JPanel();

		//message label
		messageLabel = new JLabel("mssg label",null,SwingConstants.LEFT);
		messageLabel.setText("Whats up");
		messageLabel.setToolTipText("just a mssg label");

		//start button
		JButton startButton = new JButton("Start");
		startButton.setText("Oye..click here");

		//array of buttons
		JButton[] buttons = new JButton[15];
		int j=0, l=0;
		for(j=0; j<10; j++)
		{
			String label = Integer.toString(j+1);
			buttons[j]=new JButton(label);
			buttons[j].setText(label);
		}
		
		String[] specialChars = {"!","@","#","$","%"};
		l=0;
		//j value continued from above loop
		for(; j<15; j++)
		{
			buttons[j]= new JButton(specialChars[l]);
			buttons[j].setText(specialChars[l++]);
		}
		
		panelOnlyButtons.setLayout(new GridLayout(0,3));
		for(j=0; j<buttons.length; j++)
			panelOnlyButtons.add(buttons[j]);

		panelButtonsAndText.setLayout(new BoxLayout(panelButtonsAndText, BoxLayout.Y_AXIS));
		panelButtonsAndText.add(messageLabel);
		panelButtonsAndText.add(panelOnlyButtons);

		mainPanel.setLayout(new GridLayout(0,2));
		mainPanel.add(startButton);
		mainPanel.add(panelButtonsAndText);

		frame.setContentPane(mainPanel);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//listeners
		//anonymous class is used 
		startButton.addActionListener(new ActionListener() 
        {
			public void actionPerformed(ActionEvent e)
            {
                Object[] options = {"Yes its working", "No its failing miserably", "Cant say"};
                int n= JOptionPane.showOptionDialog(
                		frame, "Is it working?\n",
                		"Must ask you this...",
                		JOptionPane.YES_NO_CANCEL_OPTION,
                		JOptionPane.QUESTION_MESSAGE,
                		null,
                		options,
                		options[2]	
                		
                	);
                messageLabel.setText("You said: "+(String)options[n]);
            }
        });
 
 		//borders
 		Border blackline, raisedetched, loweredetched,raisedbevel, loweredbevel, empty;
		blackline = BorderFactory.createLineBorder(Color.black);
		raisedetched = BorderFactory.createEtchedBorder(EtchedBorder.RAISED);
		loweredetched = BorderFactory.createEtchedBorder(EtchedBorder.LOWERED);
		raisedbevel = BorderFactory.createRaisedBevelBorder();

		loweredbevel = BorderFactory.createLoweredBevelBorder();
		empty = BorderFactory.createEmptyBorder();

		mainPanel.setBorder(empty);
		panelButtonsAndText.setBorder(blackline);
		panelOnlyButtons.setBorder(raisedetched);

		//menus
		JMenuBar menuBar1 = new JMenuBar();
		JMenu fileMenu = new JMenu("FileMenu");
		menuBar1.add(fileMenu);
		fileMenu.setMnemonic(KeyEvent.VK_F); //hot key for file menu
		JMenuItem option1 = new JMenuItem("Option1 (O)",KeyEvent.VK_O);
		JMenuItem option2 = new JMenuItem("Option2 (P)",KeyEvent.VK_P);
		fileMenu.add(option1);
		fileMenu.addSeparator(); //adds a menu separator
		fileMenu.add(option2);

		JMenu viewMenu = new JMenu("ViewMenu");
		menuBar1.add(viewMenu);
		viewMenu.setMnemonic(KeyEvent.VK_V);
		JMenuItem option3 = new JMenuItem("Option3 (Q)",KeyEvent.VK_Q);
		JMenuItem option4 = new JMenuItem("Option4 (W)",KeyEvent.VK_W);
		viewMenu.add(option3);
		viewMenu.addSeparator();
		viewMenu.add(option4);

		frame.setJMenuBar(menuBar1);

		frame.pack();
		//icon



	}
}

class manyPanels{

	public static void main(String[] args)
	{
		theapp app = new theapp();
		app.run();
	}
}
