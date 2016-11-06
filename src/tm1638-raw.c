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

    int i;
    for( i = 0; i < 8; i++ ) {
        char val = 0;
        if( argc > i+1 ) {
            int j = 0;
            while( argv[i+1][j] != '\0' && j < 8 ) {
                val = val << 1;
                val = val | (argv[i+1][j] - 48);
                j++;
            }
        }
        tm1638_set_7seg_raw(t, i, val);
    }

    return 0;
}
