import java.util.ArrayList;
public class ArrayLists
{
    public static void main(String args[])
    {
        ArrayList<String> arr = new ArrayList<String>();
        System.out.println(arr);
        arr.add("Hello");
        arr.add(",");
        //arr.remove(1);
        arr.remove(",");
        arr.add(0, "World");
        System.out.println(arr);
        System.out.println(arr.size());

        for (String x : arr)
        {
            System.out.println(x);
        }
    }
}
