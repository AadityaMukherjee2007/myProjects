import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

public class distConv_1 implements ActionListener
{
	static JFrame frame;
	static JPanel panel;
	static JLabel mLabel;
	static JLabel kLabel;
	static JTextField kInput;
	static JTextField mInput;
	static JButton convert1;
	static JButton convert2;
	
	double mile = 0, km = 0, k = 1.609344, m = 0.621371;

	// add calories to the program

	// 1 mile = 1.609344 km
	// 1 km = 0.621371 mile
	public double mtok()
	{
		double con = mile * k;
		return con;
	}
	
	public double ktom()
	{
		double con = km * m;
		return con;
	}
	
	public static void main(String args[])
	{
		Color bcolor = new Color(205, 205, 205);
		
		frame = new JFrame("Distance Conversion");
		frame.setSize(335, 160);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE	);
		
		panel = new JPanel();
		panel.setLayout(null);
		panel.setBackground(new Color(233, 233, 233));
		frame.add(panel);
		
		mLabel = new JLabel("Mile: ");
		mLabel.setBounds(10, 20, 80, 25);
		panel.add(mLabel);
		
		mInput = new JTextField();
		mInput.setBounds(50, 20, 150, 25);
		panel.add(mInput);
		
		kLabel = new JLabel("Kilometer: ");
		kLabel.setBounds(10, 50, 80, 25);
		panel.add(kLabel);
		
		kInput = new JTextField();
		kInput.setBounds(90, 50, 150, 25);
		panel.add(kInput);
		
		convert1 = new JButton("Covert to Mile");
		convert1.setBounds(5, 90, 140, 28);
		convert1.setBackground(bcolor);
		convert1.addActionListener(new distConv_1());
		panel.add(convert1);
		
		convert2 = new JButton("Covert to Kilometer");
		convert2.setBounds(150, 90, 180, 28);
		convert2.setBackground(bcolor);
		convert2.addActionListener(new distConv_1());
		panel.add(convert2);
		
		frame.setVisible(true);
	}
	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == convert1)
		{
			String ktext = kInput.getText();
			km = Double.parseDouble(ktext);
			double c = ktom();
			String conv = String.valueOf(c);
			mInput.setText(null);
			panel.revalidate();
			mInput.setText(conv);
		}
		else if (e.getSource() == convert2)
		{
			String mtext = mInput.getText();
			mile = Double.parseDouble(mtext);
			double c = mtok();
			String conv = String.valueOf(c);
			kInput.setText(null);
			panel.revalidate();
			kInput.setText(conv);
		}
	}
}
