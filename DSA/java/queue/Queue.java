public class Queue
{
	int[] arr;
	int f, r, size;

	Queue (int len)
	{
		arr = new int[len];
		f = -1;
		r = -1;
		size = len;
	}

	public void enqueue(int n)
	{
		if (r == -1)
		{
			arr[++r] = n;
			f = 0;
		}
		else if (r == (size - 1))
		{
			System.out.println("Overflow");
		}
		else
		{
			arr[++r] = n;
		}

		print();
	}

	public void dequeue()
	{
		if (f == -1)
		{
			System.out.println("Underflow");
		}
		else if (f == (size - 1))
		{
			System.out.println("Nothing to delete!");
		}
		else
		{
			f++;
			if (f > r)
			{
				System.out.println("Underflow");
				return;
			}
		}

		print();
	}

	public void print()
	{
		for (int i = f; i <= r; i++)
		{
			System.out.println(arr[i]);
		}
		System.out.println();
	}

	public void peek()
	{
		if (r == -1)
			System.out.println("Nothing to peek!");
		else
			System.out.println(arr[f]);
	}

	public static void main(String args[])
	{
		Queue obj = new Queue(5);
		
		obj.enqueue(5);
		obj.enqueue(10);
		obj.enqueue(1);
		obj.dequeue();
		obj.peek();
	}
}