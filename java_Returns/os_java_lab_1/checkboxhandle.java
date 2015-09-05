import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

class CheckBoxTest extends JFrame{
	private JTextField t;
	private JCheckBox bold, italic;

	public CheckBoxTest(){
		super ("JCheckBox Test");
		Container c = getContentPane();
		c.setLayout(new FlowLayout());

		t= new JTextField("Watch the font style change",20);
		t.setFont( new Font("TimesRoman",Font.PLAIN,14));
		c.add(t);

		//create checkbox objects
		bold = new JCheckBox("Bold");
		c.add(bold);

		italic = new JCheckBox("Italic");
		c.add(italic);

		CheckBoxHandler handler = new CheckBoxHandler();
		//ItemListener for checkboxes whereas ActionListener for buttons
		bold.addItemListener(handler);
		italic.addItemListener(handler);

		addWindowListener(
			new WindowAdapter(){
				public void windowClosing( WindowEvent e){
					System.out.println("Do run this app again!");
					System.exit(0);
				}

			}
		);

		setSize( 275,100 );
		setVisible(true);
		

	}

	public static void main(String[] args){
		new CheckBoxTest();
	}

	class CheckBoxHandler implements ItemListener{
		private int val = Font.PLAIN;

		public void itemStateChanged( ItemEvent e )
		{
			if (e.getSource() == bold)
				if ( e.getStateChange()	== ItemEvent.SELECTED )
					t.setFont( new Font("TimesRoman",Font.BOLD,14));		
				else if ( e.getStateChange()	== ItemEvent.DESELECTED )
					t.setFont( new Font("TimesRoman",Font.PLAIN,14));		
			if (e.getSource() == italic)
				if ( e.getStateChange()	== ItemEvent.SELECTED )
					t.setFont( new Font("TimesRoman",Font.ITALIC,14));		
				else if ( e.getStateChange()	== ItemEvent.DESELECTED )
					t.setFont( new Font("TimesRoman",Font.PLAIN,14));		
		}
	}
}