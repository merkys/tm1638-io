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
        return 1;
    }

    t = tm1638_alloc( 17, 27, 22 ); /* Used GPIO pins */

    if( !t ) {
        printf( "Unable to allocate TM1638\n" );
        return 2;
    }

    int i = 0;
    int j;
    char val = 0;
    while( !feof(stdin) ) {
        char s = getchar();
        switch( s ) {
            case '\n':
                if( i < 8 && val > 0 ) {
                    tm1638_set_7seg_raw( t, i, val );
                    /* printf( "[%u] ", val ); */
                    i++;
                }
                for( j = i; j < 8; j++ ) {
                    tm1638_set_7seg_raw( t, j, 0 );
                    /* printf( "[0] " ); */
                }
                val = 0;
                i = 0;
                /* printf( "\n" ); */
                break;
            case '0':
            case '1':
                if( i < 8 ) {
                    val = val << 1;
                    val = val | ( s - 48 );
                }
                break;
            case ' ':
                if( i < 8 ) {
                    tm1638_set_7seg_raw( t, i, val );
                    /* printf( "[%u] ", val ); */
                    val = 0;
                    i++;
                }
                break;
        }
    }

    return 0;
}
