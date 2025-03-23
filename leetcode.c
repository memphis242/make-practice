#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

static const unsigned char MAX_ITERATIONS = 100;
static const unsigned char MAX_DIGITS_EASILY_REPRESENTABLE = 18;
static struct ListNode DEFAULT_LIST = { .val = 0, .next = NULL };

/* Local Function Declarations */
static long long int int_pow(int base, int exponent);
static unsigned int GetNumberFromList(const struct ListNode * list_head, unsigned char * i);
static struct ListNode * ConstructListFromNumber(unsigned int num, const unsigned char MAX_DIGITS);
static struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
static struct ListNode* addTwoNumbersWithExtraction(struct ListNode* l1, struct ListNode* l2);
static void printList(struct ListNode * head);
static void freeList(struct ListNode * head);

int main(void)
{
   struct ListNode test1_1 = { .val = 2, .next = NULL };
   struct ListNode test1_2 = { .val = 4, .next = NULL };
   struct ListNode test1_3 = { .val = 3, .next = NULL };

   struct ListNode test2_1 = { .val = 5, .next = NULL };
   struct ListNode test2_2 = { .val = 6, .next = NULL };
   struct ListNode test2_3 = { .val = 4, .next = NULL };

   struct ListNode test3_1 = { .val = 9, .next = NULL };
   struct ListNode test3_2 = { .val = 9, .next = NULL };
   struct ListNode test3_3 = { .val = 9, .next = NULL };
   struct ListNode test3_4 = { .val = 9, .next = NULL };
   struct ListNode test3_5 = { .val = 9, .next = NULL };
   struct ListNode test3_6 = { .val = 9, .next = NULL };
   struct ListNode test3_7 = { .val = 9, .next = NULL };

   struct ListNode test4_1 = { .val = 9, .next = NULL };
   struct ListNode test4_2 = { .val = 9, .next = NULL };
   struct ListNode test4_3 = { .val = 9, .next = NULL };
   struct ListNode test4_4 = { .val = 9, .next = NULL };

   struct ListNode * result;
   unsigned int result_num;

   test1_1.next = &test1_2;
   test1_2.next = &test1_3;

   test2_1.next = &test2_2;
   test2_2.next = &test2_3;

   test3_1.next = &test3_2;
   test3_2.next = &test3_3;
   test3_3.next = &test3_4;
   test3_4.next = &test3_5;
   test3_5.next = &test3_6;
   test3_6.next = &test3_7;

   test4_1.next = &test4_2;
   test4_2.next = &test4_3;
   test4_3.next = &test4_4;

   printf("Round One!\n");

   printf("First Number: %d\t\t", GetNumberFromList(&test1_1, NULL));
   printf("First Number List: ");
   printList(&test1_1);
   printf("Second Number: %d\t\t", GetNumberFromList(&test2_1, NULL));
   printf("Second Number List: ");
   printList(&test2_1);

   result = addTwoNumbers(&test1_1, &test2_1);
   result_num = GetNumberFromList(result, NULL);

   printf("Sum Number: %d\t\t\t", GetNumberFromList(result, NULL));
   printf("Sum List: ");
   printList(result);
   freeList(result);

   assert( GetNumberFromList(&test1_1, NULL) == 342u );
   assert( GetNumberFromList(&test2_1, NULL) == 465u );
   assert( result_num == 807u );

   /*********************************************************************/

   printf("\n\n");

   printf("Round Two!\n");

   printf("First Number: %d\t\t", GetNumberFromList(&test3_1, NULL));
   printf("First Number List: ");
   printList(&test3_1);
   printf("Second Number: %d\t\t", GetNumberFromList(&test4_1, NULL));
   printf("Second Number List: ");
   printList(&test4_1);

   result = addTwoNumbers(&test3_1, &test4_1);
   result_num = GetNumberFromList(result, NULL);

   printf("Sum Number: %d\t\t", GetNumberFromList(result, NULL));
   printf("Sum List: ");
   printList(result);
   freeList(result);

   assert( GetNumberFromList(&test3_1, NULL) == 9999999u );
   assert( GetNumberFromList(&test4_1, NULL) == 9999u );
   assert( result_num == 10009998u );

   /*********************************************************************/

   // Free the lists!
   freeList(&test1_1);
   freeList(&test2_1);
   freeList(&test3_1);
   freeList(&test4_1);
   freeList(&test4_1);

   return 0;
}


/* Function Definitions */

static long long int int_pow(int base, int exponent)
{
   int result = 1;

   for ( int i = 0; i < exponent; i++ )
   {
      result *= base;
   }

   return result;
}

static unsigned int GetNumberFromList(const struct ListNode * list_head, unsigned char * i)
{
   const struct ListNode * iterator;
   unsigned int num;
   unsigned char j = 0;

   // Early return opportunity
   if ( list_head == NULL )
   {
      return 0;
   }
   else if ( list_head->next == NULL )
   {
      return list_head->val;
   }

   num = list_head->val;
   iterator = list_head;
   while ( (j < MAX_DIGITS_EASILY_REPRESENTABLE) && (iterator->next != NULL) )
   {
      j++;
      iterator = iterator->next;

      // Extract next digit and shift into place
      num += iterator->val * int_pow(10, j);
   }

   if ( i != NULL )
   {
      *i = j;
   }

   return num;
}

static struct ListNode * ConstructListFromNumber(unsigned int num, const unsigned char MAX_DIGITS)
{
   struct ListNode * iterator = NULL;
   struct ListNode * list_head = NULL;

   for ( unsigned char k = 0; k < MAX_DIGITS; k++ )
   {
      unsigned char digit;
      struct ListNode * node;

      digit = num % 10;
      num /= 10;

      node = (struct ListNode *)malloc(sizeof(struct ListNode));
      if ( node == NULL )
      {
         return &DEFAULT_LIST;
      }

      node->val = digit;
      node->next = NULL;
      // For the first iteration, mark the head of the list
      if ( k == 0 )
      {
         list_head = node;
      }
      else
      {
         iterator->next = node;
      }
      iterator = node;

      if ( num == 0 )
      {
         break;
      }
   }

   return list_head;
}

static struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
   struct ListNode * sum_list = NULL;
   struct ListNode * iterator = NULL;
   unsigned char temp;
   bool carry = false;

   // Early return opportunity
   if ( (NULL == l1) || (NULL == l2) )
   {
      return NULL;
   }
   else if ( (NULL == l1->next) && (NULL == l2->next) && (l1->val < 5) && (l2->val < 5) )
   {
      sum_list = (struct ListNode *)malloc(sizeof(struct ListNode));
      sum_list->val = l1->val + l2->val;
      sum_list->next = NULL;

      return sum_list;
   }

   // Add column-wise, accounting for carry-over
   sum_list = (struct ListNode *)malloc(sizeof(struct ListNode));
   iterator = sum_list;
   while ( (l1 != NULL) || (l2 != NULL) || (carry == true) )
   {
      unsigned char a;
      unsigned char b;

      // Get next numbers to add, accounting for the possiblity that we reached the end of one list
      if ( l1 != NULL )
      {
         a = l1->val;
      }
      else
      {
         a = 0;
      }

      if ( l2 != NULL )
      {
         b = l2->val;
      }
      else
      {
         b = 0;
      }

      temp = a + b + carry;
      carry = (temp > 9u);
      if ( carry )
      {
         iterator->val = temp % 10;
      }
      else
      {
         iterator->val = temp;
      }

      if ( ( (l1 != NULL) && (l1->next != NULL) ) || ( (l2 != NULL) && (l2->next != NULL) ) || (carry == true) )
      {
         iterator->next = (struct ListNode *)malloc(sizeof(struct ListNode));
         iterator = iterator->next;
      }
      else
      {
         iterator->next = NULL;
      }

      if ( l1 != NULL )  l1 = l1->next;
      if ( l2 != NULL )  l2 = l2->next;
   }
   
   return sum_list;
}

static struct ListNode* addTwoNumbersWithExtraction(struct ListNode* l1, struct ListNode* l2)
{
   // Locals
   // Persistent
   // Autos
   unsigned int a;
   unsigned int b;
   unsigned long long int sum;
   unsigned char first_num_digit_count = 0;
   unsigned char second_num_digit_count = 0;
   unsigned char max_digits;
   struct ListNode * list_head;

   /** Extract Numbers From Lists **/
   a = GetNumberFromList( l1, &first_num_digit_count );
   b = GetNumberFromList( l2, &second_num_digit_count );

   /** Sum **/
   sum = a + b;

   /** Construct Sum Linked-List **/
   // Determine number of digits needed
   if ( first_num_digit_count > second_num_digit_count )
   {
      max_digits = first_num_digit_count + 2;
   }
   else
   {
      max_digits = second_num_digit_count + 2;
   }
   list_head = ConstructListFromNumber( sum, max_digits );

   // Prune leading zero if applicable
   // Ehhh, shouldn't have to if we're breaking at (sum == 0)

   return list_head;
}

static void printList(struct ListNode * head)
{
   struct ListNode * iterator = head;
   unsigned char i = 0;

   while ( (i < 100) && (iterator != NULL) )
   {
      i++;
      printf("%d -> ", iterator->val);
      iterator = iterator->next;
   }
   printf("NULL\n");
}

static void freeList(struct ListNode * head)
{
   struct ListNode * iterator = head;
   struct ListNode * node_to_free;

   while ( iterator != NULL )
   {
      node_to_free = iterator;
      iterator = iterator->next;
      free(node_to_free);
   }
}
