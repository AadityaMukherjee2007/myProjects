package stack;

public class Stack 
{
    char[] arr;
    int top = 0;

    Stack(int len)
    {
        arr = new char[len];
    }

    public void push(char ch)
    {
        if (isFull())
        {
            System.out.println("Stack is full!");
            return;
        }   

        arr[top] = ch;
        top++;
    }

    public void pop()
    {
        if (isEmpty())
        {
            System.out.println("Stack is empty!");
        }
        arr[--top] = '\0';
    }

    public boolean isEmpty()
    {
        if (top == 0)
            return true;
        
        return false;
    }

    public boolean isFull()
    {
        if (top == arr.length - 1)
            return true;
        
        return false;
    }

    public char current()
    {
        if (isEmpty())
            return '\0';
        else
            return arr[top - 1];
    }

    public void print()
    {
        for (int i = 0; i <= top; i++)
        {
            System.out.println(arr[i]);
        }
    }
    /*
    public static void main(String args[])
    {
        Stack obj = new Stack(10);
        obj.push('a');
        obj.push('b');
        obj.push('c');
        obj.push('s');

        obj.print();

        obj.pop();

        obj.print();

        System.out.println(obj.current());
    } 
    */
}
