#include <stdio.h>
#include <cs50.h> //needed to use string 
#include <string.h> //needed to use strlen
#include <stdlib.h> //needed to use the atoi
#include <ctype.h> //needed to use isalpha, islower, isupper

int main(int argc, string argv[1])  //takes in two command line arguments. 
{
    if (argc != 2) //tells the user what the command line argument should look like if they got it wrong.
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }

    string key = argv[1]; //makes sure that the argv[1] is a number/
    for (int i = 0; i < strlen(key); i++)
    {
        if ((key[i] != '0') && (key[i] != '1') && (key[i] != '2') && (key[i] != '3') && (key[i] != '4') && (key[i] != '5')
            && (key[i] != '6') && (key[i] != '7') && (key[i] != '8') && (key[i] != '9'))
        {
            printf("Usage: ./Caesar key\n");
            return 1;
        }
    }

    int keyNumber = atoi(argv[1]); //converts the string argument value into an integer

    string plaintext = get_string("Plaintext: "); //prompts the user for the text they want to encypher. 
    string ciphertext; //variable in which the ciphered text will be stores. 
    printf("ciphertext: "); 
     
    for (int i = 0; i < strlen(plaintext); i++) //iterates thorugh each character in the array
    {
        if ((isalpha(plaintext[i])) && (isupper(plaintext[i])))   //used to encipher and print captial letters.
        {
            plaintext[i] = plaintext[i] - 65;
            int formula = (plaintext[i] + keyNumber) % 26;
            plaintext[i] = formula + 65;
            printf("%c", plaintext[i]);
             
        }
        else if (islower(plaintext[i]))  //used to encipher and print lowercase letters
        {
            plaintext[i] = plaintext[i] - 97;
            int formula = (plaintext[i] + keyNumber) % 26;
            plaintext[i] = formula + 97;
            printf("%c", plaintext[i]);
        }
        else 
        {
            printf("%c", plaintext[i]); //prints punctuation. 
        }
         
    }
    printf("\n");
}