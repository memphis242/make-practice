#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool divideArray(int* nums, int numsSize)
{
   bool result = true;
   unsigned int counts[501] = {0}; // Array to count occurrences of each number (0-500)
   int maxCount = 0;
   // unsigned int i;

   if ( (nums != NULL) && (numsSize > 0) && ((numsSize % 2) == 0) )
   {
      for ( int i = 0; i < numsSize; i++ )
      {
         counts[nums[i]]++; // Increment the count for the current number

         if ( nums[i] > maxCount )
         {
            maxCount = nums[i]; // Update maxCount if current count is greater
         }
      }

      for (int i = 0; i <= maxCount; i++)
      {
         if (counts[i] % 2 != 0) { // Check if the count is odd
            result = false; // If any count is odd, return false
            break;
         }
      }
   }
   else
   {
      // Initial conditions indicate that nums cannot be divided into pairs
      result = false;
   }

   return result; // If all counts are even, return true
}

// write a main functin that calls divideArray with a test case
int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4}; // Example test case
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (divideArray(nums, numsSize)) {
        printf("The array can be divided into pairs.\n");
    } else {
        printf("The array cannot be divided into pairs.\n");
    }

    return 0;
}