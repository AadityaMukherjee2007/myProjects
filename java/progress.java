public class progress
{
	public static void main(String args[])
	{
		for (int i = 1; i <= 100; i++)
		{
			System.out.print("\rProgress: " + i + "%");
			try
			{
				Thread.sleep(50);
			}
			catch (InterruptedException e)
			{
				System.out.println(e);
			}
		}
	}
}
