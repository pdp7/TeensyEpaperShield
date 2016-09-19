#ifndef _epaper_H_
#define _epaper_H_

#include <SPI.h>

class Epaper {
  public:
    void initScreen();
    void updateScreen();
    void clearScreen();
    void drawPixel( int x, int y, int color );
    void placeStringAt( String s, int x, int y );
  private:
    byte _d0;
    byte _d1;
    byte _cs;
    byte _dc;
    byte _rs;
    byte _bs;
    byte _rotation = 0;
    byte _cursorX;
    byte _cursorY;
    void _placeChar( char c, int neededSpace );
    void _sendIndexData( byte index, byte *data, int len );
    byte _bitReverse( byte x );
};

#endif /* _epaper_H_ */
