tm1638-io – basic command line IO for TM1638 displays & buttons
===============================================================

Dependencies
------------

* [bcm2835](http://www.airspayce.com/mikem/bcm2835/) – C library for
    Broadcom BCM 2835 as used in Raspberry Pi
* [pi-tm1638](http://www.mjoldfield.com/atelier/2012/08/pi-tm1638.html) –
    TM1638 library for Raspberry Pi

Installation
------------

Just ``make`` and adjust the permissions. Usually, GPIO can be accessed
by users from group ``gpio``, so one either needs to be in that group or
make scripts in ``bin/`` setgid.
