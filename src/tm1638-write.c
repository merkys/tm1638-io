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

    char text[9];
    int i = 0;
    while( !feof(stdin) ) {
        char s = getchar();
        if( s != '\n' ) {
            if( i < 8 ) {
                text[i] = s;
            }
            i++;
        } else {
            if( i < 9 ) {
                text[i] = '\0';
            } else {
                text[8] = '\0';
            }
            tm1638_set_7seg_text(t, text, 0x00);
            /* printf( "[%s]\n", text ); */
            i = 0;
        }
    }

    return 0;
}
