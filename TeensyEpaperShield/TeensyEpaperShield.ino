#include "epaper.h"

#define NMSG 9

// avoid the protect plastic tab until I take it off
#define VERT_OFFSET 36
#define VERT_MAX 150
#define LINE_HEIGHT 24
#define INIT_DELAY 2000
#define LOOP_DELAY 2000

Epaper epaper;

String banner[NMSG] = { "OSH Park  welcomes you to Portland Mini Maker Faire 2016" ,
                        "Teensy E-Paper Adapter Board by Jarek Lupinski: hackaday.io/Jarek",
                        "'The Simplest Way To Start Playing With A Fascinating New Low-Power Screen!' -Jarek",
                        "OSH Park: Perfect, Purple, Prompt PCBs. Made in the USA!",
                        "[oshpark.com] Upload EAGLE, KiCad or Gerbers",
                        " twitter: @oshpark       blog.oshpark.com       docs.oshpark.com  ",
                        "2 layer boards are $5 per square inch (with 3 copies of your board included in that price) and ship in under 12 calendar days from ordering",
                        "4 layer boards are $10 per square inch (also including 3 copies of your board), go to the fab once a week, and have a 2 week turn time from the fab.",
                        "2 Layer Medium Run Service: $1 per square inch, 150 square inch minimum. You can have as many different designs as you want, as long as each design is ordered in a multiple of 10 boards."
                      };


void setup() {
  epaper.initScreen();
  delay( INIT_DELAY );
}

void loop() {
  for ( int i = 0; i < NMSG; i++ ) {
    epaper.clearScreen();
    // display messages successivly lower on the display for visual "flare"
    int y = (i * LINE_HEIGHT) + VERT_OFFSET;
    epaper.placeStringAt(  (String)(banner[i]), 0, (y < VERT_MAX ? y : VERT_OFFSET ) );
    epaper.updateScreen();
    delay( LOOP_DELAY );
  }
}
