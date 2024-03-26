public class Test
{
    public static void main(String args[])
    {
        linkedList l = new linkedList();
        l.add(10);
        l.add(20);
        l.add(30);
        l.add(40);
        l.add(50);
        l.add(60);
        l.add(70);
        l.add(80);
        l.add(90);
        l.add(100);

        System.out.println(l);
        System.out.println(l.size());
        System.out.println(l.isEmpty());
        System.out.println(l.getIndex(80));
        System.out.println(l.getValue(0));

        l.insert(55, 4);
        System.out.println(l);
        System.out.println();
        l.delete(55);
        System.out.println(l);
    }
}