#include "epaper.h"

Epaper epaper;

void setup() {
  epaper.initScreen();
  delay( 5000 );
}

void loop() {
  for ( int i = 0; i < 2; i++ ) {
    epaper.clearScreen();
    epaper.placeStringAt( "Hello World", 0, 0 );
    epaper.placeStringAt(  String( i ), 0, 15 );
    epaper.updateScreen();
    delay( 2000 );
  }
  epaper.initScreen();
  delay( 5000 );
}
