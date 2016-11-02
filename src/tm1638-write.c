#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <bcm2835.h>
#include <tm1638.h>

int main(int argc, char *argv[])
{
    if( argc < 1 ) {
        printf( "Text up to 8 characters must be given\n" );
        return -3;
    }

    tm1638_p t;

    if( !bcm2835_init() ) {
        printf( "Unable to initialize BCM library\n" );
        return -1;
    }

    t = tm1638_alloc( 17, 27, 22 ); /* Used GPIO pins */

    if( !t ) {
        printf( "Unable to allocate TM1638\n" );
        return -2;
    }

    char text[10];
    memcpy( text, argv[0], 8 );
    text[9] = '\0';

    tm1638_set_7seg_text(t, text, 0x00);

    return 0;
}
