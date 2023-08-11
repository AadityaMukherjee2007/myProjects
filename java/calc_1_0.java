import mypackages.math.opMath1;
import java.util.Scanner;



public class calc_1_0
{
    char choice;

    void ip1()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Operator: \n1 --> addition\n2 --> subtraction\n3 --> multiplication\n4 --> division\n5 --> power");
        System.out.print("\n\nEnter Operator: ");
        choice = sc.next().charAt(0);
    }

    void switch1()
    {

        switch(choice)
        {
            case 1 : ;
        }
    }

    public static void main(String[] args)
    {
        opMath1 obj1 = new opMath1();
        calc_1_0 obj = new calc_1_0();

        obj.ip1();

    }
}
