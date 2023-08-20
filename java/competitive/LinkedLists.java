import java.util.LinkedList;
public class LinkedLists
{
    public static void main(String args[])
    {
        LinkedList<String> ll = new LinkedList<>();
        ll.add("Linked");
        ll.add("Lists");
        ll.addFirst("Java");
        ll.addLast("Computer");
        ll.add(1, "Gibberish");
        ll.remove(1);
        System.out.println(ll);

        for (String i : ll)
        {
            System.out.println(i);
        }
    }
}
