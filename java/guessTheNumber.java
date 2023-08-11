import java.util.Scanner;
public class guessTheNumber 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int tries = 0, random, guess;

        System.out.println("Guess the number from 0 to 9\n");
		
		random = (int) (Math.random() * 10);
		
        while (true)
        {
            System.out.print("Guess: ");
            guess = sc.nextInt();

            if (guess == random)
            {
                
				if (tries == 0)
				{
					System.out.println("\nBull's Eye!!!!!\n");
					System.out.println("You Win!!  :)");
                	System.out.println("Tries = " + tries);				
					System.exit(0);
				}
				else if (tries == 1)
				{
					System.out.println("\nExcellent!!!!\n");
					System.out.println("You Win!!  :)");
                	System.out.println("Tries = " + tries);
					System.exit(0);
				}
				else if (tries == 2)
				{
					System.out.println("\nGreat!!!\n");
					System.out.println("You Win!!  :)");
                	System.out.println("Tries = " + tries);
					System.exit(0);
				}
				else if (tries == 3)
				{
					System.out.println("\nVery Good!!\n");
					System.out.println("You Win!!  :)");
                	System.out.println("Tries = " + tries);
					System.exit(0);
				}
				else if (tries == 4)
				{
					System.out.println("\nGood!  :|\n");
					System.out.println("You Win!!");
                	System.out.println("Tries = " + tries);
					System.exit(0);
				}    
			}	
			else if (tries > 4)
			{
				System.out.println("\nYou Lose!!  :(");
				break;
			}
			else
			{
				tries++;
				continue;
			}
		}		
    }
}
