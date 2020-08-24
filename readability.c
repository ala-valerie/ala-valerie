#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main (void)
{
    string text = get_string("Text: ");
    int numberOfLetters = strlen(text);
    printf("%i letter(s) \n", numberOfLetters);

    int numberOfWords = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == (int) 32)
        {
            numberOfWords ++;
        }

    }
    
    printf("%i word(s)\n", numberOfWords);
    
    int numberOfSentences = 0;
    for (int i = 0; i < strlen(text); i++)
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
    
    printf("%i sentence(s) \n",numberOfSentences);
    float s = numberOfLetters / numberOfWords * 100;
    float l = numberOfSentences / numberOfWords * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    printf("Grade: %f \n",index);

}
// Next i need to write a function that will count the number of words in a sentence. I think i will need to use an array here and increment my way
// through the array, and as i do that i will have an if, else loop to either increment my word counter, or leave it blank
//ascii characters needed: ? = 63, ! = 33, . = 46

//functions will go outside of the main body. 32 is the Ascii code for a space

