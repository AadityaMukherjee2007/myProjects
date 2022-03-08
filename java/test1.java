import java.util.Scanner;
public class test1
{	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= (5 - i); j++)
			{
				System.out.print(" ");
			}
			for (int k = i; k >= 1; k--)
			{
				System.out.print(k);
			}
			System.out.println();
		}
	}
}
