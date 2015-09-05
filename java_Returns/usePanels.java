import javax.swing.*;
class usePanels{
	public static void main(String[] args)
	{
		//TOp Down creation
		//1.Frame
		JFrame frame = new JFrame("Has Panels");
		frame.setSize(400,300);
		frame.setVisible(true);
		//set location of upper left point of frame
		frame.setLocation(500,200);
	
		//2.Panel
		JPanel panel = new JPanel();
		
		//3.Panel Component
		JButton startButton = new JButton("Start");
		startButton.setText("Start!");
	
		//ADD Bottom Up
		//1. would be to add listeners to component
		//2. add component to panel
		panel.add(startButton);
		//3. add panel to frame
		frame.setContentPane(panel);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}