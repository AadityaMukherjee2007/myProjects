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
        Node current = this.head;
        int index = 0;
        while (current != null)
        {
            if (current.getData() == n)
            {
                return index;
            }
            index++;
            current = current.next_node;
        }

        return -1; //return -1 if not found
    }

    public int getValue(int n)
    {
        Node current = this.head;
        int index = 0;
        while (current != null)
        {
            if (index == n)
            {
                return current.getData();
            }
            current = current.next_node;
        }

        return -1;
    }

    public void insert(int data, int index)
    {
        if (index == 0)
        {
            add(data);
        }
        else if (index > 0)
        {
            Node newData = new Node(data);
            Node current = this.head;
            int i = 0; 
            while (i > index)
            {
                current = current.next_node;
                i++;
            }

            
        }
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