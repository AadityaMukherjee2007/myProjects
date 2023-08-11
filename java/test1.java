import java.util.Scanner;
public class test1
{
  int[][] arr, tArr;
  int m, n;
  /*
   m = rows
   n = coulmns
  */
  
  // this method is used to take user input and initialize the arrays...
  public void in()
  {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter number of columns: ");
    n = sc.nextInt();

    System.out.print("Enter number of rows: ");
    m = sc.nextInt();

    System.out.println();
    arr = new int[m][n];
    tArr = new int[n][m];

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        System.out.print("Enter Number: ");
        arr[i][j] = sc.nextInt();
      }
    }
  }
  
  // this method computes and inputs the values in the array, tArr...
  public void com()
  {
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        tArr[j][i] = arr[i][j];
      }
    }
  }

  // this method is used for printing the elements of the arrays...
  public void print()
  {
	System.out.println("\nInput: ");
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        System.out.print(arr[i][j] + " ");
      }
      System.out.println();
    }
    
    System.out.println("\nOutput: ");
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        System.out.print(tArr[i][j] + " ");
      }
      System.out.println();
    }
  }

  public static void main(String args[])
  {
    test1 obj = new test1();

    obj.in();
    obj.com();
    obj.print();
  }
}
