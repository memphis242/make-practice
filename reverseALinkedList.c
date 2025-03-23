#include <stdio.h>
#include <stdlib.h>

static const unsigned char MAX_NODES = 200;

struct ListNode_S
{
   int val;
   struct ListNode_S * next;
};

struct ListNode_S * ReverseLinkedList(struct ListNode_S * head);
void PrintList(struct ListNode_S * head);

int main(void)
{
   struct ListNode_S n1 = { .val = 1, .next = NULL };
   struct ListNode_S n2 = { .val = 2, .next = NULL };
   struct ListNode_S n3 = { .val = 3, .next = NULL };
   struct ListNode_S n4 = { .val = 4, .next = NULL };
   struct ListNode_S n5 = { .val = 5, .next = NULL };
   struct ListNode_S * head;
   struct ListNode_S * new_head;

   n1.next = &n2;
   n2.next = &n3;
   n3.next = &n4;
   n4.next = &n5;

   head = &n1;
   PrintList(head);

   new_head = ReverseLinkedList(head);
   PrintList(new_head);

}

void PrintList(struct ListNode_S * head)
{
   // Early return opportunity
   if ( head == NULL )
   {
      return;
   }

   struct ListNode_S * iterator = head;
   do
   {
      printf("%d", iterator->val);
      if ( iterator->next != NULL ) printf(" -> ");
      else printf("\n");
      iterator = iterator->next;
   } while ( iterator != NULL );
}

struct ListNode_S * ReverseLinkedList(struct ListNode_S * head)
{
   // Early return opportunity
   if ( (NULL == head) || (head->next == NULL) )
   {
      return head;
   }

   struct ListNode_S * prev_node = head;
   struct ListNode_S * mid_node = head->next;
   struct ListNode_S * next_node = head->next->next;
   unsigned char i = 0; // Constrain # of loops
   // For the first node, its next becomes NULL
   prev_node->next = NULL;
   do
   {
      i++;
      mid_node->next = prev_node;
      prev_node = mid_node;
      mid_node = next_node;
      if ( next_node != NULL )
      {
         next_node = next_node->next;
      }

   } while ( (i < MAX_NODES) && (mid_node != NULL ) );
   
   return prev_node;
}
