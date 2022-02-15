import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import javax.swing.*;

public class dateTime_gui 
{
    static JFrame frame;
    static JPanel panel;
    static JLabel time;
    static JLabel date;
    public static void main(String args[])
    { 
        frame = new JFrame("Clock");
        frame.setSize(150, 100);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        panel = new JPanel();
        panel.setLayout(null);
        frame.add(panel);

        time = new JLabel();
        time.setBounds(15, 20, 160, 25);
        panel.add(time);

        date = new JLabel();
        date.setBounds(15, 40, 160, 25);
        panel.add(date);

        Thread clock = new Thread()
        {
            public void run()
            {
                try
                {
                    while(true)
                    {
                        time.setText("Time: ");
                        date.setText("Date: ");
                        panel.revalidate();

                        LocalDate d = LocalDate.now();
                        LocalTime t = LocalTime.now();

                        DateTimeFormatter f1 = DateTimeFormatter.ofPattern("dd:MM:yyyy");
                        DateTimeFormatter f2 = DateTimeFormatter.ofPattern("HH:mm:ss");

                        String Date = d.format(f1);
                        date.setText("Date: " + Date);

                        String Time = t.format(f2);
                        time.setText("Time: " + Time);

                        sleep(1000);
                    }
                }
                catch(InterruptedException e)
                {
                    System.out.println("Something went wrong!");
                }
            }
        };
        clock.start();

        frame.setVisible(true);
    }
}
