#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>



int main (void)
{
  string text = get_string("Text: ");
  long numberOfLetters = 0;
  long numberOfWords = 1;
  long numberOfSentences = 0;


      for (long i = 0; i < text[i];i++)
       {

            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <='Z'))
              {
                 numberOfLetters ++;
              }

             else if (text[i] == 32)
              {
                 numberOfWords ++;
              }
              
            else if ((text[i] == '!') || (text[i] == '.') || (text[i] == '?'))
              {
                 numberOfSentences ++;
              }
       }

       printf("%li letters(s)\n",numberOfLetters);
       printf("%li word(s)\n",numberOfWords);
       printf("%li sentence(s)",numberOfSentences);


    //write my own function for counting letters and then update the code following that //
    //write out functions

    float l = numberOfLetters / numberOfWords * 100;
    float s = numberOfSentences / numberOfWords * 100;
    int index = round (0.0588 * l - 0.296 * s - 15.8);

    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }

    else if (index < 1)
    {
        printf("before grade 1");
    }

    else
    {
        printf("Grade 16+");
    }

}