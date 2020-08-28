#include <stdio.h>
#include <cs50.h>
#include <string.h> //needed for the strlen(text) function
#include <math.h> // needed for the round function



int main(void)
{
    string text = get_string("Text: ");
    long numberOfLetters = 0; 
    long numberOfWords = 1;  
    long numberOfSentences = 0;
 
//NumberOfWords = counter starts at 1 because words are counted the loop runs through a space, and there is no space after the last word.
//The loop below runs through each character in the string, and inside the loop there are a bunch of if statements which calcualte the number of 
//words, letters and sentences.The strlen()function calculates the lenght of the string, so it can tell the loop how many times we want it to run. 
    for (long i = 0; i <= strlen(text); i++) 
    {

        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
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


//The below calculations take the calculated number of letters/words/sentences.
// l = avergae number letters per 100 words.
// s = avergae number of sentences per 100 words
// index = the formula for the Coleman-Liau index
// We have to convert the variables to float because the varable needs to be able to handle decimal points, which are needed for accurate calculations. 

    float l = numberOfLetters / (float) numberOfWords * 100;
    float s = numberOfSentences / (float) numberOfWords * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

// Below is a set of if statements, that tell the computer what to print to the terminal depending on the index value. 
   
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade 16+\n");
    }

}