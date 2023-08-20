import java.math.BigInteger;

public class factorial
{
    public static BigInteger factorial(int n)
    {
        BigInteger f = new BigInteger("1");
        for (int i = 2; i <= n; i++)
        {
            f = f.multiply(BigInteger.valueOf(i));
        }
        return f;
    }
    public static void main(String args[])
    {
        System.out.println(factorial(100));
    }
}
