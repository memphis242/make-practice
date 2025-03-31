#include <stdbool.h>

bool HeapifyArray( const void * array, size_t length, size_t size_of_member, int (* comp)(const void * a, const void * b) );
bool InsertIntoHeap( const void * element );