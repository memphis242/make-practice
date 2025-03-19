#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool divideArray(const int * nums, const int numsSize)
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

int main(void)
{
   const int nums1[] = {3, 2, 3, 2, 2, 2};
   const int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
   printf("Test case 1: nums = {");
   for (int i = 0; i < numsSize1; i++) {
      printf("%d", nums1[i]);
      if (i < numsSize1 - 1) {
         printf(", ");
      }
   }
   printf("}, numsSize = %d\n", numsSize1);
   bool result1 = divideArray(nums1, numsSize1);
   printf("Result: %s\n", result1 ? "true" : "false");

   const int nums2[] = {3, 2, 3, 2, 2, 2, 1, 5, 2, 2, 1, 1, 1, 1, 1, 6, 2, 3, 6, 1, 2, 0, 1, 2, 22, 24, 22, 24, 0, 7000};
   const int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
   printf("Test case 2: nums = {");
   for (int i = 0; i < numsSize2; i++) {
      printf("%d", nums2[i]);
      if (i < numsSize2 - 1) {
         printf(", ");
      }
   }
   printf("}, numsSize = %d\n", numsSize2);
   bool result2 = divideArray(nums2, numsSize2);
   printf("Result: %s\n", result2 ? "true" : "false");

    return 0;
}