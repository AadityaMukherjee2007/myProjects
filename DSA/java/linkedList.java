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

    public void setData(int n)
    {
        this.data = n;
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

        return -1; //return -1 if not found
    }

    // needs error handling
    public Node returnNodeAtIndex(int index)
    {
        Node toBeReturned = this.head;
        int i = 0;
        while (i < index)
        {
            toBeReturned = toBeReturned.next_node;
            i++;
        }

        return toBeReturned;
    }

    //needs error handling
    public void delete(int n)
    {
        int index = getIndex(n);
        Node a = returnNodeAtIndex(index - 1);
        Node b = returnNodeAtIndex(index + 1);

        a.next_node = b;
    }

    //needs error handling 
    public void insert(int data, int index)
    {
        if (index < 0 || index > size() - 1)
        {
            System.out.println("Invalid index!");
            return;
        }

        if (index == 0)
        {
            add(data);
        }
        else if (index > 0)
        {
            Node newData = new Node(data);
            Node current = this.head;
            int i = 0; 
            while (i < index)
            {
                current = current.next_node;
                i++;
            }

            Node next = current.next_node;
            current.next_node = newData;
            newData.next_node = next;
        }
    }

    public void sort()
    {
        // implementing selection sort 
        int x = 0;
        for (Node i = head; i != null; i = i.next_node, x++)
        {
            int largest = i.getData(), index = x + 1, pos = x;
            for (Node j = i.next_node; j != null; j = j.next_node, index++)
            {
                if (largest < j.getData())
                {
                    largest  = j.getData();
                    pos = index;
                }
            }

            int temp = i.getData();
            i.setData(largest);
            returnNodeAtIndex(pos).setData(temp);
        }
    }
    
    public void reverse()
    {
        Node current = this.head;
        int i = 0, l = size(), mid = 0;

        if (l < 2)
        {
            return;
        }

        if (l % 2 == 0)
        {
            mid = (l / 2) - 1;
        }
        else
        {
            mid = (l + 1) / 2;
        }

        while (i <= mid)
        {
            int j = l - (i + 1), val = current.getData();
            current.setData(returnNodeAtIndex(j).getData());
            returnNodeAtIndex(j).setData(val);
            current = current.next_node;
            i++;
        }
    }

    public void merge(linkedList list)
    {
        returnNodeAtIndex(size() - 1).next_node = list.head;
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