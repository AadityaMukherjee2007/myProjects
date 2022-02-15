import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

public class tempConv1 implements ActionListener
{
	static JFrame frame;
	static JPanel panel;
	static JLabel fLabel;
	static JLabel cLabel;
	static JLabel kLabel;
	static JTextField fText;
	static JTextField cText;
	static JTextField kText;
	static JButton conv1;
	static JButton conv2;
	static JButton conv3;
	
	public static void main(String[] args)
	{
		Color bColor = new Color(208, 208, 208);
		
		frame = new JFrame("Temperature Conversion");
		frame.setSize(330, 225);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		panel = new JPanel();
		panel.setLayout(null);
		frame.add(panel);
		
		cLabel = new JLabel("Celsius: ");
		cLabel.setBounds(10, 10, 100, 25);
		panel.add(cLabel);
		
		cText = new JTextField();
		cText.setBounds(100, 10, 150,25);
		panel.add(cText);
			
		fLabel = new JLabel("Fahrenheit: ");
		fLabel.setBounds(10, 40, 100, 25);
		panel.add(fLabel);
		
		fText = new JTextField();
		fText.setBounds(100, 40, 150,25);
		panel.add(fText);
		
		kLabel = new JLabel("Kelvin: ");
		kLabel.setBounds(10, 70, 100, 25);
		panel.add(kLabel);
		
		kText = new JTextField();
		kText.setBounds(100, 70, 150, 25);
		panel.add(kText);
		
		conv1 = new JButton("Convert Celsius");
		conv1.setBounds(10, 120, 150, 25);
		conv1.setBackground(bColor);
		conv1.addActionListener(new tempConv1());
		panel.add(conv1);
		
		conv2 = new JButton("Convert Fahrenheit");
		conv2.setBounds(60, 155, 180, 25);
		conv2.setBackground(bColor);
		conv2.addActionListener(new tempConv1());
		panel.add(conv2);
		
		conv3 = new JButton("Convert Kelvin");
		conv3.setBounds(170, 120, 150, 25);
		conv3.setBackground(bColor);
		conv3.addActionListener(new tempConv1());
		panel.add(conv3);
				
		frame.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent evt)
	{
		if (evt.getSource() == conv1)
		{
			
		}
		else if (evt.getSource() == conv2)
		{
			
		}
		else if (evt.getSource() == conv3)
		{
			
		}
	}
}
