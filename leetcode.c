#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Constraints:
// - The number of nodes in each linked list is in the range [1, 100].
// - 0 <= Node.val <= 9
// - It is guaranteed that the list represents a number that does not have leading zeros.

struct ListNode
{
   unsigned char val;
   struct ListNode *next;
};

long long int int_pow(int base, int exponent)
{
   int result = 1;

   for ( int i = 0; i < exponent; i++ )
   {
      result *= base;
   }

   return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
   // Locals
   // Persistent
   static const unsigned char MAX_ITERATIONS = 100;
   static struct ListNode DefaultReturn = { .val = 0, .next = NULL };
   // Autos
   unsigned int a;
   unsigned int b;
   unsigned long long int sum;
   unsigned char i = 1;
   unsigned char j = 1;
   unsigned char max_digits;
   struct ListNode * list_head;
   struct ListNode * iterator;

   // Extract digits
   // First number
   iterator = l1;
   a = iterator->val;
   while ( (i < MAX_ITERATIONS) && (iterator->next != NULL) )
   {
      i++;
      iterator = iterator->next;

      // Extract next digit and shift into place
      a += iterator->val * int_pow(10, i);
   }

   // Second number
   iterator = l2;
   b = iterator->val;
   while ( (i < MAX_ITERATIONS) && (iterator->next != NULL) )
   {
      i++;
      iterator = iterator->next;

      // Extract next digit and shift into place
      b += iterator->val * int_pow(10, i);
   }

   // Sum
   sum = a + b;

   // Construct linked-list
   // Determine number of digits needed
   if ( i > j )
   {
      max_digits = i + 2;
   }
   else
   {
      max_digits = j + 2;
   }
   // Start constructing
   for ( unsigned char k = 0; k < max_digits; k++ )
   {
      unsigned char digit;
      struct ListNode * node;

      digit = sum % 10;
      sum /= 10;

      node = (struct ListNode *)malloc(sizeof(struct ListNode));
      if ( node == NULL )
      {
         return &DefaultReturn;
      }
      if ( k == 0 )
      {
         list_head = node;
      }
      node->val = digit;
      node->next = NULL;
      iterator->next = node;

      if ( sum == 0 )
      {
         break;
      }
   }

   // Prune leading zero if applicable
   // Ehhh, shouldn't have to if we're breaking at (sum == 0)

   return list_head;
}

int main(void)
{
   return 0;
}