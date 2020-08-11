#include <stdio.h>
#include <cs50.h> //This allows you to use the data type string to create a string variable.

int main(void)
{
    string name = get_string("what is your name?");
    printf("Hello, %s\n", name);
}

// You use the relevant placeholder "%s" so that you can insert the name that will be stored in the name variable. 
// The "\n" is used to go to the next line in the terminal. 
// You need to finish some lines of code, like in line 6 and 7, with a semicolon.