#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_HEAP_SIZE     10000000   // 10 million
#define MAXIMUM_HEAP_HEIGHT   24         // ⌈ log2(10,000,000) ⌉

static void * Heap = NULL;
static size_t HeapSize;
static int (* CompareElements)(const void * a, const void * b);
static size_t SizeOfMember;
static bool HeapInitialized;

bool HeapifyArray( const void * array, size_t length, size_t size_of_member, int (* comp)(const void * a, const void * b) )
{
   // Early return opportunities
   if ( (NULL == array) || (0 == length) || (0 == size_of_member) || (size_of_member > MAXIMUM_HEAP_SIZE) || (NULL == comp) )
   {
      // Invalid arguments passed in!
      return false;
   }
   else if ( length == 1 )
   {
      Heap = malloc( size_of_member );
      if ( NULL == Heap )
      {
         // Failed to dynamically allocate memory!
         return false;
      }

      (void)memcpy(Heap, array, size_of_member);
      HeapSize = 1;
      CompareElements = comp;
      SizeOfMember = size_of_member;
      HeapInitialized = true;

      return true;
   }
   
   // Loop through elements in the array, inserting into the heap one-at-a-time and
   // swapping as needed to maintain the necessary heap properties.
   Heap = malloc( length * size_of_member );
   if ( NULL == Heap )
   {
      // Failed to dynamically allocate memory!
      return false;
   }
   CompareElements = comp;
   SizeOfMember = size_of_member;
   HeapInitialized = true;

   char * ptr = (char *)array;
   for ( size_t i = 0; i < length; i++, HeapSize++ )
   {
      InsertIntoHeap( (const void *)ptr, size_of_member );
      ptr += i * size_of_member;
   }


   return true;
}

bool InsertIntoHeap( const void * element )
{
   // Early return opportunity
   if ( (NULL == element) || (HeapInitialized != true) )
   {
      return false;
   }

   char * ptr_to_heap_root = (char *)Heap;
   // Insert to the bottom layer's left-most open spot (indexed wonderfully by HeapSize)
   char * ptr_to_new_member_slot = ptr_to_heap_root + (HeapSize * SizeOfMember);
   (void)memcpy( ptr_to_new_member_slot, element, SizeOfMember );

   // Check against parent and perform necessary bubble-up swaps until the necessary heap property is satisfied
   size_t present_idx = HeapSize;
   size_t parent_idx = (present_idx - 1) / 2;
   size_t idx_diff = present_idx - parent_idx;
   char * ptr_to_inserted_element = ptr_to_new_member_slot;
   char * ptr_to_parent = ptr_to_inserted_element - (idx_diff * SizeOfMember);
   unsigned long long int counter = 0;
   void * temp = malloc(SizeOfMember);
   // Until newly inserted element's position respects the heap property...
   while ( (present_idx != 0) && (CompareElements( element, ptr_to_parent ) > 0) && (counter < MAXIMUM_HEAP_HEIGHT) )
   {
      // Swap
      if ( NULL == temp )
      {
         // Failed to dynamically allocate memory!
         return false;
      }

      // c = a
      (void)memcpy(temp, element, SizeOfMember);
      // a = b
      (void)memcpy(element, ptr_to_inserted_element, SizeOfMember);
      // b = c
      (void)memcpy(ptr_to_inserted_element, temp, SizeOfMember);

      counter++;
      present_idx = parent_idx;
      parent_idx = (present_idx - 1) / 2;
      idx_diff = present_idx - parent_idx;
      ptr_to_inserted_element = ptr_to_parent;
      ptr_to_parent = ptr_to_inserted_element - (idx_diff * SizeOfMember);
   }
   free(temp);

   return true;
}