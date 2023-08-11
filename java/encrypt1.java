import java.util.Scanner;

public class encrypt1
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        String enText = "", choice;
        int key;

        System.out.print("Text: ");
        String text = sc.nextLine();

        System.out.print("Key: ");
        key = sc.nextInt();

        char[] t = text.toCharArray();
        for (char c : t)
        {
            c += key;
            String str = String.valueOf(c);
            enText += str;
        }
        System.out.println("\nEncrypted Text: " + enText);
    }
}