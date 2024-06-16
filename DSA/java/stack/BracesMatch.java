package stack;

public class BracesMatch 
{

    public static void checkValidity(String str)
    {
        char[] ch = str.toCharArray();

        Stack st = new Stack(ch.length);
        st.push(ch[0]);

        for (int i = 1; i < ch.length; i++)
        {
            if (st.current() == '[')
            {
                if (ch[i] == ']')
                    st.pop();
                else
                    st.push(ch[i]);
            }
            else if (st.current() == '{')
            {
                if (ch[i] == '}')
                    st.pop();
                else
                    st.push(ch[i]);
            }
            else if (st.current() == '(')
            {
                if (ch[i] == ')')
                    st.pop();
                else
                    st.push(ch[i]);
            }
        }

        if (st.isEmpty())
            System.out.println("Valid");
        else
            System.out.println("Invalid");
    }
    public static void main(String args[])
    {
        String in_1 = "[[{}]()]"; // output should be valid
        String in_2 = "[{})[]"; // output should be invalid
        String in_3 = "[{(})]"; // output should be invalid

        checkValidity(in_1);
        checkValidity(in_2);
        checkValidity(in_3);
    }
}
