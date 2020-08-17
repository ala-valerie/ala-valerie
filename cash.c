#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{ 
    float cash;
    do {
    cash = get_float("change owned: ");
       }
    while (cash <= 0);
    
    int cents = round(cash*100);
    
    int coins = 0;
    
    while (cents >= 25)
    { 
        coins ++;
        cents = cents -25;
    }
     
    while (cents >= 10)
    { 
        coins ++;
        cents = cents -10;
    }
     
    while (cents >= 5)
    {
        coins ++;
        cents = cents -5;
    }
    
    while (cents >= 1)
    { 
       coins ++;
       cents --;
    }
     
     printf("%i \n", coins);
}

// lines 1,2,3 include files that gives us 
// the do loop (line 7-11) ensures that the computer keeps prompting the user for a number until they give a positive number. 
// lines 13: a new variable is created, that converts the change into cents, and rounds it to the nearest cent. To use the round function you need to 
//     include the <math.h>
// line 15: a new variable is created