import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

public class RadioButtonTest extends JFrame{
	private JTextField t;
	private Font plainFont, boldFont, italicFont, boldItalicFont;
	private JRadioButton plain, bold, italic, bolditalic;
	private ButtonGroup radioGroup;
	public RadioButtonTest()
	{
		super("RadioButton Test");
		Container c = getContentPane();
		c.setLayout(new GridLayout(0,1));

		t = new JTextField("Watch it change");
		c.add(t);

		plain = new JRadioButton("Plain",true);
		c.add(plain);
		bold = new JRadioButton("Bold",false);
		c.add(bold);
		italic = new JRadioButton("Italic",false);
		c.add(italic);
		bolditalic = new JRadioButton("Bold/Italic",false);
		c.add(bolditalic);

		//register events
		RadioButtonHandler handler = new RadioButtonHandler();
		plain.addActionListener(handler);
		bold.addActionListener(handler);
		italic.addActionListener(handler);
		bolditalic.addActionListener(handler);

		//create logical relationship between JRadioButton
		radioGroup = new ButtonGroup();
		radioGroup.add(plain);
		radioGroup.add(bold);
		radioGroup.add(italic);
		radioGroup.add(bolditalic);
 
		plainFont = new Font("TimesRoman",Font.PLAIN,14);
		boldFont = new Font("TimesRoman",Font.BOLD,14);
		italicFont = new Font("TimesRoman",Font.ITALIC,14);
		boldItalicFont = new Font("TimesRoman",Font.BOLD|Font.ITALIC,14);



		setSize(300,200);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);	
	}

	class RadioButtonHandler implements ActionListener{
	private int val = Font.PLAIN;
		public void actionPerformed(ActionEvent e)
		{
			if (e.getSource() == bold)
				t.setFont(boldFont);		
			else if (e.getSource() == italic)
				t.setFont(italicFont);		
			else if (e.getSource() == bolditalic)
				t.setFont(boldItalicFont);		
			else if (e.getSource() == plain)
				t.setFont(plainFont);		
		}
	}

	public static void main(String[] args) {
		new RadioButtonTest();
	}
}