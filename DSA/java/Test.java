public class Test
{
    public static void main(String args[])
    {
        linkedList l = new linkedList();
        l.add(65);
        l.add(44);
        l.add(76);
        l.add(23);
        l.add(54);
        l.add(13);
        l.add(97);
        l.add(74);
        l.add(32);
        l.add(38);

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
        l.sort();
        System.out.println(l);

        l.insert(100, 100);
        l.insert(40, 6);
        l.reverse();
        System.out.println(l);
    }
}