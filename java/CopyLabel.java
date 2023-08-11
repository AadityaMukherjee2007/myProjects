import javax.swing.*;
import java.awt.Font;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CopyLabel implements ActionListener
{
	//var for infoFrame()
	JFrame frame;
	JPanel panel;
	JTextField name, roll, sub;
	JComboBox<String> Class, Section;
	JLabel status;

	public void infoFrame()
	{
		frame = new JFrame("Info");
		frame.setSize(350, 230);
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		panel = new JPanel();
		panel.setLayout(null);
		frame.add(panel);

		JLabel nameL = new JLabel("Name: ");
		nameL.setBounds(10, 10, 50, 25);
		panel.add(nameL);

		name = new JTextField();
		name.setBounds(80, 10, 180, 25);
		panel.add(name);

		JLabel classL = new JLabel("Class: ");
		classL.setBounds(10, 50, 50, 25);
		panel.add(classL);

		String[] standard = new String[12];
		for (int i = 0; i < 12; i++)
		{
			standard[i] = String.valueOf(i + 1);
		}

		Class = new JComboBox<>(standard);
		Class.setBounds(80, 50, 45, 25);
		panel.add(Class);

		JLabel secL = new JLabel("Section: ");
		secL.setBounds(150, 50, 80, 25);
		panel.add(secL);

		String[] section = new String[5];
		for (int i = 0; i < 5; i++)
		{
			int alph = 65 + i;
			section[i] = String.valueOf((char) alph);
		}

		Section = new JComboBox<>(section);
		Section.setBounds(230, 50, 45, 25);
		panel.add(Section);

		JLabel rollL = new JLabel("Roll: ");
		rollL.setBounds(10, 90, 50, 25);
		panel.add(rollL);

		roll = new JTextField();
		roll.setBounds(80, 90, 45, 25);
		panel.add(roll);

		JLabel subL = new JLabel("Subject: ");
		subL.setBounds(150, 90, 80, 25);
		panel.add(subL);

		sub = new JTextField();
		sub.setBounds(230, 90, 100, 25);
		panel.add(sub);

		JButton create = new JButton("Create");
		create.setBounds(230, 150, 100, 30);
		create.addActionListener(new CopyLabel());
		panel.add(create);

		status = new JLabel("");
		status.setBounds(10, 150, 100, 25);
		panel.add(status);

		frame.setVisible(true);
	}

	public void labelFrame()
	{

	}

	public void actionPerformed(ActionEvent e)
	{
		try
		{
			int rollNo = Integer.parseInt(roll.getText());
			if (name.getText() == null || sub.getText() == null)
			{
				status.setForeground(Color.RED);
				status.setText("Error!");
				panel.revalidate();
			}
		}
		catch (Exception err)
		{
			status.setForeground(Color.RED);
			status.setText("Error!");
			panel.revalidate();
		}
	}

	public static void main(String args[])
	{
		CopyLabel obj = new CopyLabel();
		obj.infoFrame();
	}
}