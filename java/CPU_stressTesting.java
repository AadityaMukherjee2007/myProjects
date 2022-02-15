import java.util.Scanner;
public class CPU_stressTesting
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int a = 0, b = 1, c = 0;
		
		System.out.print("Enter Range: ");
		int r = sc.nextInt();
		
		double startTime = System.currentTimeMillis();
		for (int i = 1; i <= r; i++)
		{
			int count = 0;
			for (int j = 1; j < a; j++)
			{
				if (a % j == 0)
				{
					count++;
				}
			}
			if (count == 1)
			{
				System.out.print(a + " ");

			}
			c = a + b;
			a = b; 
			b = c;
		}
		
		double stopTime = System.currentTimeMillis();
		double timeElapsed = (stopTime - startTime) / 1000;
		System.out.println("\n\nTime Elapsed : " + timeElapsed + " seconds");
	}
}
