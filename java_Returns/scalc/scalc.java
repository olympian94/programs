import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;

class ScientificCalc{
	JFrame frame;
	JButton[] normalButtonsArray = new JButton[15];
	JButton[] advancedButtonsArray = new JButton[15];
	JPanel normalButtonsPanel;
	JPanel advancedButtonsPanel;
	JPanel mainpanel;
	JPanel allButtonsPanel;
	JTextField inputField;

	public void createFrame()
	{
		frame = new JFrame();
		frame.setSize(700,300);
		frame.setVisible(true);
		frame.setLocation(400,100);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	/*public void addMenus()
	{

	}*/
	
	public void createNormalButtonsPanel()
	{
		String[] normalButtonLabels = new String[15];
		int j;
		for(j=0; j<10; j++)
		{
			normalButtonLabels[j] = Integer.toString(j+1);
		}
		normalButtonLabels[j++]="*";
		normalButtonLabels[j++]="+";
		normalButtonLabels[j++]="-";
		normalButtonLabels[j++]="/";
		normalButtonLabels[j++]="=";
		int size = j;

		normalButtonsPanel = new JPanel();
		for(j=0; j<size; j++)
		{
			normalButtonsArray[j]= new JButton(normalButtonLabels[j]);
			normalButtonsArray[j].setText(normalButtonLabels[j]);
			normalButtonsPanel.add(normalButtonsArray[j]);
		}
		normalButtonsPanel.setLayout(new GridLayout(0,3));
	}

	public void createAdvancedButtonsPanel()
	{
		String[] advancedButtonLabels = new String[15];
		int j=0;
		advancedButtonLabels[j++]="sin";
		advancedButtonLabels[j++]="cos";
		advancedButtonLabels[j++]="tan";
		advancedButtonLabels[j++]="sec";
		advancedButtonLabels[j++]="cosec";
		advancedButtonLabels[j++]="cot";
		advancedButtonLabels[j++]="log_base10";
		advancedButtonLabels[j++]="log_base2";
		advancedButtonLabels[j++]="exp";
		advancedButtonLabels[j++]="pow(x,y)";
		int advancedButtonsTotal = j;

		advancedButtonsPanel = new JPanel();
		for(j=0; j<advancedButtonsTotal; j++)
		{
			advancedButtonsArray[j]= new JButton(advancedButtonLabels[j]);
			advancedButtonsArray[j].setText(advancedButtonLabels[j]);
			advancedButtonsPanel.add(advancedButtonsArray[j]);
		}
		advancedButtonsPanel.setLayout(new GridLayout(0,3));
	}	

	public void createInputTextField()
	{
		inputField = new JTextField();

	}

	public void createApp()
	{
		mainpanel = new JPanel();
		mainpanel.setLayout(new GridLayout(0,1));
		mainpanel.add(inputField);
		
		allButtonsPanel = new JPanel();
		allButtonsPanel.setLayout(new GridLayout(0,2));
		allButtonsPanel.add(advancedButtonsPanel);
		allButtonsPanel.add(normalButtonsPanel);

		mainpanel.add(allButtonsPanel);
		frame.add(mainpanel);		
	}

	public void runApp()
	{
		createAdvancedButtonsPanel();
		createNormalButtonsPanel();
		createInputTextField();
		createFrame();
		createApp();
	}	
}

public class scalc{
	public static void main(String[] args) {
		ScientificCalc app1 = new ScientificCalc();
		app1.runApp();
	}
}