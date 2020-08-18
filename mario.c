#include <cs50.h>
#include <stdio.h>


int main(void)
{
   int n; 
   do 
   {
       n = get_int("Positive Number: "); 
   }
       while (n < 1 || n > 8);                               


   for (int i = 0; i < n; i++ )
       {
          
           for (int x = 0; x <= i; x++)  
             {
                printf("#");
             }

           printf("\n");
       }
}
 
// row 7: here we are declaring a variable, called 'n', with the integer data type.
// row 8: the do command will run the code once to see if the user did what was needed
// row 10: assigining value to the n variable
// row 12: this while loop will keep prompting the user for a number til it is between 1 and 8.
// row 15: here we are creating a loop so that a "#" and a move to the next line is repeated based on the number that was chosen by the use (variable n & has to be between 1 and 8)
//row 17: for the right amount of hashtags to be printed on each line, we need to create another loop in this loop, so that everytime the main loop repeats, "#" is printed the number the counter "i" is on. 
