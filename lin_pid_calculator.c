#include <stdio.h>

#define BIT_MASK(val, bit_place)  ( val & (1u << bit_place) )
#define GET_BIT_VAL(val, bit_place)   ( ( val & (1u << bit_place) ) >> bit_place )

int main( int argc, char * argv[] )
{
   int num_of_converted_items;
   unsigned int message_id;
   _Bool p0;
   _Bool p1;
   unsigned char protected_id;

   if ( argc == 2 )
   {
      // Get the first argument as a number
      message_id &= 0x3F;  // mask out upper two bits to 0
      num_of_converted_items = sscanf( argv[1], "%X", &message_id );
      // Compute PID from parity bit equations specified in LIN 2.1 spec
      if ( num_of_converted_items > 0 )
      {
         p0 =    GET_BIT_VAL( message_id, 0 ) ^ GET_BIT_VAL( message_id, 1 ) ^ GET_BIT_VAL( message_id, 2 ) ^ GET_BIT_VAL( message_id, 4 );
         p1 = ( ~( GET_BIT_VAL( message_id, 1 ) ^ GET_BIT_VAL( message_id, 3 ) ^ GET_BIT_VAL( message_id, 4 ) ^ GET_BIT_VAL( message_id, 5 ) ) ) & 0x01;
         protected_id = ( p1 << 7 ) | ( p0 << 6 ) | message_id;

         printf( "Message ID: \t%X\nProtected ID: \t%X\n", message_id, protected_id );
      }
   }
   else
   {
      fprintf( stderr, "Incorrect number of arguments passed in! Please only invoke the program name with 1 argument.\nFor example: ./lin_pid_calculator.exe 0x2A" );
   }

}