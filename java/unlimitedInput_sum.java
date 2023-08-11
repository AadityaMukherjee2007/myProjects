import java.util.Scanner;
public class unlimitedInput_sum
{	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter Number: ");
		
		int n = 0;
		while (sc.hasNextDouble())
		{
			n += sc.nextDouble();
		}
		sc.close();
		
		System.out.println("Sum = " + n);
	}
}
