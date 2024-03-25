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

    public void add(int data)
    {
        Node new_node = new Node(data);
        new_node.next_node = this.head;
        this.head = new_node;
    }
    
    @Override
    public String toString()
    {
        Node current = this.head;
        String linkedlist = "";
        linkedlist += "[Head: " + current.getData() + "]";

        if (!isEmpty())
        {
            linkedlist += "-> ";
        }

        while (!current.isEmpty())
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
    
    public static void main(String args[])
    {
        
    }
}