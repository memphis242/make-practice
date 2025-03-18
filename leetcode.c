#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool divideArray(int* nums, int numsSize)
{
   bool result = true;
   unsigned int counts[501] = {0}; // Array to count occurrences of each number (0-500)
   int maxCount = 0;

   if ( (nums != NULL) && (numsSize > 0) && ((numsSize % 2) == 0) )
   {
      for ( int i = 0; i < numsSize; i++ )
      {
         if ( counts[nums[i]] > 0 )
         {
            counts[nums[i]]--;  // Decrement the count if the number has been seen before
         }
         else
         {
            counts[nums[i]]++; // Increment the count for the current number
         }

         if ( nums[i] > maxCount )
         {
            maxCount = nums[i]; // Update maxCount if current count is greater
         }
      }

      for (int i = 0; i <= maxCount; i++)
      {
         if ( counts[i] != 0 ) { // Check if the count is nonzero
            result = false; // If any count is non-zero, we didn't find a match for it, so return false
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

    int nums2[] = {1, 1, 2, 2, 3, 3, 4, 4}; // Example test case 2
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);

    if (divideArray(nums2, numsSize2)) {
        printf("The array can be divided into pairs.\n");
    } else {
        printf("The array cannot be divided into pairs.\n");
    }

    return 0;
}