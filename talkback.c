// Listing 4.1 The talkback.c Program
// talkback.c -- nosy, informative program
#include <stdio.h>      // For printf and scanf
#include <string.h>     // For strlen() function prototype

#define DENSITY 62.4f   // Human density in lbs/ft^3

int main(void)
{
    float weight;
    float volume;
    int name_size;
    int name_length;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);

    name_size   = sizeof( name );
    name_length = strlen( name );

    volume = weight / DENSITY;

    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, (double)volume);

    printf("Also, your first name has %d letters,\n", name_length);
    printf("and we have %d bytes to store it.", name_length, name_size);

    return 0;
}
