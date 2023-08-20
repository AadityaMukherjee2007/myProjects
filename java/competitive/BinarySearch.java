import java.util.Arrays;
public class BinarySearch
{
    static int[] arr = {3,2,6,8,1,2,9,7,4};

    public static int search(int n)
    {
        Arrays.sort(arr);
        int l = 0, r = arr.length - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] > n)
            {
                r = m - 1;
            }
            else if (arr[m] < n)
            {
                l = m + 1;
            }
            else if (arr[m] == n)
            {
                return m;
            }
        }
        return -1;
    }

    public static void main(String args[])
    {
        System.out.println(arr.length);
        System.out.println(search(33));
    }
}
