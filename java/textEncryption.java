import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

public class textEncryption implements ActionListener
{
    private static JFrame frame;
    private static JPanel panel;
    private static JButton enBut;
    private static JLabel key;
    private static JLabel tLabel;
    private static JLabel eLabel;
    private static JTextField enText;
    private static JTextField userText;
    private static JTextField enKey;
    String encryptedText;


    public static void main(String args[])
    {
        Color bg = new Color(210, 197, 197);

        frame = new JFrame("Text Encryption");
        panel = new JPanel();

        frame.setSize(500, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);

        panel.setLayout(null);


        tLabel = new JLabel("Text: ");
        tLabel.setBounds(10, 20, 80, 25);
        panel.add(tLabel);

        userText = new JTextField();
        userText.setBounds(60, 20, 200, 25);
        panel.add(userText);

        key = new JLabel("Key: ");
        key.setBounds(300, 20, 70, 25);
        panel.add(key);

        enKey = new JTextField();
        enKey.setBounds(350, 20, 40, 25);
        panel.add(enKey);

        eLabel = new JLabel("Encrypted Text: ");
        eLabel.setBounds(10, 60, 120, 25);
        panel.add(eLabel);


        enText = new JTextField();
        enText.setBounds(150, 60, 300, 25);
        panel.add(enText);

        enBut = new JButton("Encrypt Text!");
        enBut.setBackground(bg);
        enBut.setBounds(100, 100, 300, 40);
        enBut.addActionListener(new textEncryption());
        panel.add(enBut);

        frame.setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        encryptedText = "";

        enText.setText(null);
        panel.revalidate();

        String text = userText.getText();
        String key_text = enKey.getText();

        int key = Integer.valueOf(key_text);

        char[] t = text.toCharArray();
        for (char c : t)
        {
            c += key;
            String str = String.valueOf(c);
            encryptedText += str;
        }
        enText.setText(encryptedText);
        panel.revalidate();
    }
}