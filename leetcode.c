#include <stdbool.h> // For bool type
#include <stddef.h>  // For NULL macro def
#include <stdio.h>   // For printf
#include <stdlib.h>  // For malloc
#include <assert.h>  // For assert

/* Local Function Declarations */
void fizzBuzz(int n);

int main(void)
{
   fizzBuzz(25);
   fizzBuzz(100);
   fizzBuzz(0);
}


/* Function Definitions */

/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n)
{
   // Early return opportunity
   if ( (0 == n) || (1 == n) )
   {
      printf("%d\n");
      return;
   }

   for ( unsigned int i = 1; i <= (unsigned int)n; i++ )
   {
      if ( 0 == (i % 3) )
      {
         if ( 0 == (i % 5) )
         {
            printf("FizzBuzz\n");
         }
         else
         {
            printf("Fizz\n");
         }
      }
      else if ( 0 == (i % 5) )
      {
         printf("Buzz\n");
      }
      else
      {
         printf("%d\n", i);
      }
   }
}