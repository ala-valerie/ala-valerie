#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[1])
{
    if (argc != 2)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }
    
    for (int i = 0; i > strlen(argv[1]); i++)
     {
        if ((argv[1][i] < "0") &&(argv[1][i] > "9"))
        {
            printf("Usage: ./Caesar key\n");
            return 1;
        }
     }
}