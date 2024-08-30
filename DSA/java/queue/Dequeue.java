// incomplete code
public class Dequeue
{
	int front, rear, capacity;
	int[] arr;
	Dequeue(int len)
	{
		arr = new int[len];
		front = -1;
		rear = -1;
		capacity = len;
	}

	public boolean isFull()
	{
		if (rear == capacity - 1 && front == 0)
			return true;
		return false;
	}

	public boolean isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		return false;
	}

	// improve function
	public void addFront(int n)
	{
		if (isFull())
			System.out.println("Queue Overflow!");
		else if (isEmpty())
		{
			front = rear = 0;
			arr[++front] = n;
		}
		else
		{
			if (front > 0)
				arr[--front] = n;
			else
				System.out.println("Underflow");
		}
	}

	public void addRear(int n)
	{

	}

	public void removeFront()
	{

	}

	public void addRear()
	{

	}

	public void print()
	{
		for (int i = front; i <= rear; i++)
			System.out.println(arr[i]);
	}

	public static void main(String args[])
	{
		Dequeue obj = new Dequeue(5);
		System.out.println(obj.isEmpty());
		obj.addFront(5);
		obj.addFront(2);
		obj.addFront(1);
		obj.print();
	}
}