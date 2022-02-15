import java.util.Scanner;
public class test1
{	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[5];
		for (int i = 0; i < arr.length; i++)
		{
			System.out.print("Enter number: ");
			arr[i] = sc.nextInt();
		}
		int smallest = 0;
		int greatest = 0;
		int index = 0;
		
		
		for (int i = 0; i < arr.length; i++)
		{
			if (greatest < arr[i])
			{
				greatest = arr[i];
				index = i;
			}
			else if (smallest > arr[i])
			{
				smallest = arr[i];
			}
		}
		System.out.println(greatest);
		System.out.println(smallest);
		
		arr[index] = smallest;
		greatest = 0;
		index = 0;
		for (int i = 0; i < arr.length; i++)
		{
			if (greatest < arr[i])
			{
				greatest = arr[i];
			}
		}
		System.out.println(greatest);
	}
}
