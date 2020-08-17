#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{ 
    float cash;
    do {
    cash = get_float("change owned: ");
    }
    while (cash <= 0);
    
    int cents = round(cash*100);
    
    
    int coins = 0;
    while (cents >= 25)
     { coins ++;
       cents = cents -25;
       
     }
    while (cents >= 10)
    { coins ++;
      cents = cents -10;
      
    }
    while (cents >= 5)
    { coins ++;
      cents = cents -5;
      
    }
    while (cents >= 1)
    { coins ++;
      cents = cents - 1;
      
    }
     
     printf("%i \n", coins);
}