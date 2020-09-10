#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> //needed to use the atoi function
#include <ctype.h>

int main (int argc, string argv[1])
{
    if (argc != 2)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }

    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
     {
        if ((key[i] != '0') &&(key[i] != '1') &&(key[i] != '2') &&(key[i] != '3') &&(key[i] != '4') &&(key[i] != '5') &&(key[i] != '6') &&(key[i] != '7') &&(key[i] != '8') &&(key[i] != '9'))
        {
            printf("Usage: ./Caesar key\n");
            return 1;
        }
     }

     int keyNumber = atoi(argv[1]); //converts the string argument value into an integer

     string plaintext = get_string("Plaintext: ");
     string ciphertext; 
     printf("ciphertext: ");
     
     for (int i = 0; i < strlen(plaintext); i++)
     {
         if (( isalpha (plaintext[i])) && (isupper (plaintext[i])))
         {
             plaintext[i] = plaintext[i] - 65;
             int formula = (plaintext[i] + keyNumber) % 26;
             plaintext[i] = formula + 65;
             printf("%c",plaintext[i]);
             
         }
         else if (islower (plaintext[i]))
         {
             plaintext[i] = plaintext[i] - 97;
             int formula = (plaintext[i] + keyNumber) % 26;
             plaintext[i] = formula + 97;
             printf("%c",plaintext[i]);
         }
         else 
         {
             printf("%c", plaintext[i]);
         }
         
     }
     printf("\n");
}