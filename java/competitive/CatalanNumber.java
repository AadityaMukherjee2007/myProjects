import java.math.BigInteger;
public class CatalanNumber
{
    public static BigInteger fac(int n)
    {
        BigInteger f = new BigInteger("1");
        for (int i = 2; i <= n; i++)
        {
            f= f.multiply(BigInteger.valueOf(i));
        }
        return f;
    }
    public static BigInteger catalan(int n)
    {
        BigInteger num = new BigInteger("0");
        num = fac(2 * n).divide(fac(n + 1).multiply(fac(n)));
        return num;
    }
    public static void main(String args[])
    {
        for (int i = 0; i < 100; i++)
        {
            System.out.println(catalan(i));
        }
    }
}
