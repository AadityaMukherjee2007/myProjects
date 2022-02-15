package mypackages.math;
import java.util.Scanner;
public class opMath1
{
    double a, b, c;

    void ip()
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Number: ");
        a = sc.nextDouble();
        
        System.out.print("Enter Number: ");
        b = sc.nextDouble();
    }

    void add()
    {
        c = a + b;
    }

    void sub()
    {
        c = a - b;
    }

    void mul()
    {
        c = a * b;
    }

    void div()
    {
        c = a / b;
    }


    public static void main(String[] args)
    {
        opMath1 obj = new opMath1();

        obj.ip();

        obj.add();
        obj.sub();
        obj.mul();
        obj.div();
    }
}
