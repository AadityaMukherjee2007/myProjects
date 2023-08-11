import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Color;

public class diceRole implements ActionListener
{
    static JFrame frame;
    static JPanel panel;
    static JLabel op;
    static JButton generate;

    public void mainFrame()
    {
        Color bColor = new Color(208, 208, 208);

        frame = new JFrame("Dice Role");
        frame.setSize(200, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel();
        panel.setLayout(null);
        frame.add(panel);

		generate = new JButton("Roll");
		generate.setBounds(75, 100, 60, 25);
        generate.addActionListener(new diceRole());
        generate.setBackground(bColor);
        panel.add(generate);

        frame.setVisible(true);
    }

    public static void main(String args[])
    {
		diceRole obj = new diceRole();
		obj.mainFrame();
    }
    public void actionPerformed(ActionEvent e)
    {

    }
}
