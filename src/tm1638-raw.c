#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <bcm2835.h>
#include <tm1638.h>

int main(int argc, char *argv[])
{
    if( argc < 1 ) {
        /* printf( "Text up to 8 characters must be given\n" );
        return -3; */
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

    tm1638_set_7seg_raw(t, 0,   1);
    tm1638_set_7seg_raw(t, 1,   2);
    tm1638_set_7seg_raw(t, 2,   4);
    tm1638_set_7seg_raw(t, 3,   8);
    tm1638_set_7seg_raw(t, 4,  16);
    tm1638_set_7seg_raw(t, 5,  32);
    tm1638_set_7seg_raw(t, 6,  64);
    tm1638_set_7seg_raw(t, 7, 128);

    return 0;
}
