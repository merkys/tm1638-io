#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <bcm2835.h>
#include <tm1638.h>

int main(int argc, char *argv[])
{

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

    if( argc == 1 ) {
        tm1638_set_8leds( t, 0, 0 );
        tm1638_free( &t );
        return 0;
    }

    char val = 0;
    int j = 0;
    while( argv[1][j] != '\0' && j < 8 ) {
        val = val << 1;
        val = val | (argv[1][j] - 48);
        j++;
    }
    tm1638_set_8leds( t, val, val );
    tm1638_free( &t );

    return 0;
}
