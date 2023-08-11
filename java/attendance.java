import java.util.Scanner;

public class attendance
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Month: ");
        String month = sc.nextLine();
        String mon = month.toLowerCase();

        int len = 0;
        switch (mon)
        {
            case "january":
            case "march":
            case "may":
            case "july":
            case "august":
            case "october":
            case"december":
                len = 31;
                break;

            case "april":
            case "june":
            case "september":
            case "november":
                len = 30;
                break;

            case "february":
            {
                System.out.print("Enter Year: ");
                short yr = sc.nextShort();

                if (yr % 4  == 0)
                {
                    len = 29;
                }
                else
                {
                    len = 28;
                }
                break;
            }
            default: System.out.println("Enter a proper month!!");
        }

        int[] at = new int[len];

        int day = 1;

        int i = 0;
        while (i < at.length)
        {
            while (true)
            {
                System.out.println("\nDay " + day);
                System.out.print("Enter number of presentees: ");
                try {
                    at[i] = sc.nextByte();
                } catch (Exception e) {
                    System.out.println("Enter proper input!!");
                }

                if (at[i] > 9) {
                    System.out.println("Enter proper input!!");
                    continue;
                }
                else
                {
                    break;
                }
            }
            day++;
            i++;
        }

        int x = 1;
        System.out.println("\n\nAttendance for the month of " + month + ": \nDay of Month\tNumber of presentees");
        System.out.println("------------\t--------------------\n");
        while(x <= day)
        {
            try
            {
                System.out.println(x + "\t\t" + at[x - 1]);
            }
            catch (ArrayIndexOutOfBoundsException e)
            {
                System.out.println();
            }
            x++;
        }
    }
}
