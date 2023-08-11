import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class gui implements ActionListener
{
    // variables for the loginFrame()
    private static JFrame frame;
    private static JPanel panel;
    private static JLabel userLabel;
    private static JLabel userPasswd;
    private static JTextField userText;
    private static JPasswordField userPassword;
    private static JButton login;
    private static JButton register1;

    //variables for the successFrame()
    private static JFrame frame2;
    private static JPanel panel2;
    private static JLabel success;
    private static JButton okButton1;

    //variables for the failFrame()
    private static JFrame frame3;
    private static JPanel panel3;
    private static JLabel fail;
    private static JButton okButton2;

    //variables for the register1Frame()
	private static JFrame frame4;
    private static JPanel panel4;
    private static JLabel userLabel_register;
    private static JTextField userText_register;
    private static JLabel userPasswd_register1;
    private static JLabel userPasswd_register2;
    private static JPasswordField userPassword_register1;
    private static JPasswordField userPassword_register2;
    private static JButton register2;


    String user_name, passwd;



    public void loginFrame()
    {
        panel = new JPanel();
        frame = new JFrame("Login");
        
        frame.setSize(300,170);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);

        panel.setLayout(null);

        userLabel = new JLabel("Username: ");
        userLabel.setBounds(10, 20, 90, 25);
        panel.add(userLabel);

        userText = new JTextField(20);
        userText.setBounds(110, 20, 160, 25);
        panel.add(userText);


        userPasswd = new JLabel("Password: ");
        userPasswd.setBounds(10, 50, 90, 25);
        panel.add(userPasswd);
        
        
        userPassword = new JPasswordField(20);
        userPassword.setBounds(110, 50, 160, 25);
        panel.add(userPassword);


        login = new JButton("login");
        login.setBounds(200, 100, 80, 25);
        login.addActionListener(new gui());
        panel.add(login);

        register1 = new JButton("Register");
        register1.setBounds(10, 100, 100, 25);
        register1.addActionListener(new gui());
        panel.add(register1);
        
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }


    public void successFrame()
    {
        frame2 = new JFrame();
		frame2.setSize(280, 105);
		
		panel2 = new JPanel();
		panel2.setLayout(null);
		frame2.add(panel2);

		success = new JLabel("Login Successful!");
		success.setBounds(70, 5, 150, 40);
		panel2.add(success);

		okButton1 = new JButton("Ok");
		okButton1.setBounds(100, 50, 60, 18);
		okButton1.addActionListener(new gui());
		panel2.add(okButton1);

        frame2.setLocationRelativeTo(null);
		frame2.setVisible(true);
    }

    public void failFrame()
    {
        frame3 = new JFrame();
		frame3.setSize(280, 105);
		
		panel3 = new JPanel();
		panel3.setLayout(null);
		frame3.add(panel3);

		fail = new JLabel("Username or Password is incorrect!");
		fail.setBounds(10, 5, 270, 40);
		panel3.add(fail);

		okButton2 = new JButton("Ok");
		okButton2.setBounds(100, 50, 60, 18);
		okButton2.addActionListener(new gui());
		panel3.add(okButton2);

        frame3.setLocationRelativeTo(null);
		frame3.setVisible(true);
    }

    public void registerFrame()
    {
		frame4 = new JFrame("Register");
		frame4.setSize(350, 200);
		
		panel4 = new JPanel();
		panel4.setLayout(null);
		frame4.add(panel4);
		
		userLabel_register = new JLabel("Username: ");
        userLabel_register.setBounds(10, 20, 90, 25);
        panel4.add(userLabel_register);

        userText_register = new JTextField();
        userText_register.setBounds(110, 20, 160, 25);
        panel4.add(userText_register);


        userPasswd_register1 = new JLabel("Password: ");
        userPasswd_register1.setBounds(10, 50, 90, 25);
        panel4.add(userPasswd_register1);
        
        
        userPassword_register1 = new JPasswordField();
        userPassword_register1.setBounds(110, 50, 160, 25);
        panel4.add(userPassword_register1);
        
        userPasswd_register2 = new JLabel("Rewrite Password: ");
        userPasswd_register2.setBounds(10, 80, 180, 25);
        panel4.add(userPasswd_register2);
        
        
        userPassword_register2 = new JPasswordField();
        userPassword_register2.setBounds(170, 80, 160, 25);
        panel4.add(userPassword_register2);

        register2 = new JButton("Register");
        register2.setBounds(230, 130, 100, 25);
        register2.addActionListener(new gui());
        panel4.add(register2);
		
		frame4.setLocationRelativeTo(null);
		frame4.setVisible(true);
    }



    public static void main(String[] args)
    {
        gui obj = new gui();
        obj.loginFrame();
    }



    public void actionPerformed(ActionEvent e)
    {
        user_name = userText.getText();
        char[] passwd1 = userPassword.getPassword();
        String str = new String(passwd1);
        passwd = String.valueOf(str);

        if (e.getSource() == login)
        {
            successFrame();
            failFrame();
        }
        else if (e.getSource() == register1)
        {
			registerFrame();
        }
        else if (e.getSource() == register2)
        {
			frame4.dispose();
		}
        else if (e.getSource() == okButton1)
        {
            frame2.dispose();
        }
        else if (e.getSource() == okButton2)
        {
			frame3.dispose();
		}
    }
}
