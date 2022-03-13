public class multidimensionalArray_1
{
    public static void main(String args[])
    {
        int n = 1;
        int arr[][] = new int[4][5];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                arr[i][j] = n;
                n++;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}