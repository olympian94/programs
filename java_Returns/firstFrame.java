import javax.swing.*;
class MyFrame{
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("First Frame");
		frame.setSize(400,300);
		frame.setVisible(true);
		//set location of upper left point of frame
		frame.setLocation(500,200);
		//add button
		frame.getContentPane().add(new JButton("OK"));
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
	}
}
