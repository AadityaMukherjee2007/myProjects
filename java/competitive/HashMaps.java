import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HashMaps
{
    public static void main(String args[])
    {
        HashMap<String, Integer> hm = new HashMap<>();
        hm.put("John", 16);
        hm.put("Peter", 18);
        hm.put("Larry", 15);

        Set<Map.Entry<String, Integer>> set = hm.entrySet();
        for (Map.Entry<String, Integer> x : set)
        {
            System.out.println(x.getKey());
            System.out.println(x.getValue());
        }

        int age = hm.get("Larry");
        hm.put("Larry", age + 5);

        //hm.clear();

        System.out.println(hm);

    }
}
