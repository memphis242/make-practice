#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

long long int int_pow(int base, int exponent)
{
   int result = 1;

   for ( int i = 0; i < exponent; i++ )
   {
      result *= base;
   }

   return result;
}

bool isPalindrome(int x)
{
   bool retVal = false;

   int digit_stack[11];
   int top = -1;
   long long int temp = (long int)x;

   if ( (x < 0) || ( ((x % 10) == 0) && (x != 0) ) )
   {
      // Leave retVal to initialized value
   }
   else if ( (x % 10) == x )
   {
      retVal = true;
   }
   else
   {
      do
      {
         top++;
         digit_stack[top] = temp % 10;
         temp /= 10;
      } while ( temp > 0 );   // Keep going until we get the last digit

      temp = 0;
      for ( int i = 0; i <= top; i++ )
      {
         temp += ( (long long int)digit_stack[i] ) * int_pow(10, top - i);
      }

      retVal = (temp == (long long int)x);
   }

   return retVal;
}

int main(void)
{
   int test_num = 1234567899; // Example of a non-palindrome
   if (isPalindrome(test_num))
   {
      printf("%d is a palindrome.\n", test_num);
   }
   else
   {
      printf("%d is not a palindrome.\n", test_num);
   }

   test_num = 11; // Example of a palindrome
   if (isPalindrome(test_num))
   {
      printf("%d is a palindrome.\n", test_num);
   }
   else
   {
      printf("%d is not a palindrome.\n", test_num);
   }

   test_num = 121; // Example of a palindrome
   if (isPalindrome(test_num))
   {
      printf("%d is a palindrome.\n", test_num);
   }
   else
   {
      printf("%d is not a palindrome.\n", test_num);
   }
   test_num = -121; // Example of a non-palindrome
   if (isPalindrome(test_num))
   {
      printf("%d is a palindrome.\n", test_num);
   }
   else
   {
      printf("%d is not a palindrome.\n", test_num);
   }

   test_num = 10; // Example of a non-palindrome
   if (isPalindrome(test_num))
   {
      printf("%d is a palindrome.\n", test_num);
   }
   else
   {
      printf("%d is not a palindrome.\n", test_num);
   }

   test_num = 0; // Example of a palindrome
   if (isPalindrome(test_num))
   {
      printf("%d is a palindrome.\n", test_num);
   }
   else
   {
      printf("%d is not a palindrome.\n", test_num);
   }

   return 0;
}