class Node
{
    protected int data;
    protected Node next_node;
    Node(int d)
    {
        this.data = d;
        this.next_node = null;
    }

    public int getData()
    {
        return data;
    }
    
    @Override
    public String toString()
    {
        return "<Node Data: " + data + ">";
    }

}

public class linkedList
{
    protected Node head;
    public linkedList()
    {
        head = null;
    }

    public boolean isEmpty()
    {
        return this.head == null;
    }

    public int size()
    {
        Node current = this.head;
        int count = 0;

        while (current != null)
        {
            count += 1;
            current = current.next_node;
        }

        return count;
    }

    public void add(int data)
    {
        Node new_node = new Node(data);
        new_node.next_node = this.head;
        this.head = new_node;
    }

    public int getIndex(int n)
    {
        
    }

    public int search(int n)
    {
        Node current = this.head;
        while (current != null)
        {
            if (current.getData() == n)
            {
                return n;
            }
            current = current.next_node;
        }

        return -1;
    }
    
    @Override
    public String toString()
    {
        Node current = this.head;
        String linkedlist = "";
        linkedlist += "[Head: " + current.getData() + "]";

        if (size() > 1)
        {
            linkedlist += "-> ";
        }

        current = current.next_node;

        while (current != null)
        {
            if (current.next_node == null)
            {
                linkedlist += "[Tail: " + current.getData() + "]";
            }   
            else
            {
                linkedlist += "[" + current.getData() + "]-> ";
            }
            current = current.next_node;
        }

        return linkedlist;
    }
}