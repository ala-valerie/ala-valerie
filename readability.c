#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>



int main (void)
{
  string text = get_string("Text: ");
  long numberOfLetters = 0;

      
      for (long i = 0; i < text[i];i++)
       {

           if (text[i] >= 65 && text[i] <= 90)
              {
                 numberOfLetters ++;
              }

           else if (text[i] >= 97 && text[i] <=122)
              {
                  numberOfLetters ++;
              }
              
       }
    

    //write my own function for counting letters and then update the code following that //
    //write out functions



  
   long numberOfWords = 1;

    for (long i = 0; i < text[i]; i++)
    {
        if (text[i] == (int) 32)
        {
            numberOfWords ++;
        }

    }

   

    long numberOfSentences = 0;
    for (long i = 0; i < text[i]; i++)
    {
        if (text[i] == (int) 33)
        {
            numberOfSentences ++;
        }

        else if (text[i] == (int) 63)
        {
            numberOfSentences ++;
        }

        else if (text[i] == (int) 46)
        {
            numberOfSentences ++;
        }
    }


    float l = numberOfLetters / numberOfWords * 100;
    float s = numberOfSentences / numberOfWords * 100;
    int index = round (0.0588 * l - 0.296 * s - 15.8);
    
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n",index);
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
// Next i need to write a function that will count the number of words in a sentence. I think i will need to use an array here and increment my way
// through the array, and as i do that i will have an if, else loop to either increment my word counter, or leave it blank
//ascii characters needed: ? = 63, ! = 33, . = 46

//functions will go outside of the main body. 32 is the Ascii code for a space

