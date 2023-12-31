/*

  demoClock.ino with ESP32
  
  
*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


U8G2_ST7539_192X64_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 23, /* cs=*/ 19, /* dc=*/ 5, /* reset=*/22);

u8g2_uint_t offset;      // current offset for the scrolling text
u8g2_uint_t width;      // pixel width of the scrolling text (must be lesser than 128 unless U8G2_16BIT is defined
const char *text = "eddy Electronics";
void setup(void) {

   u8g2.begin();  
   u8g2.setFlipMode(1);
   //u8g2.setContrast(50);
   u8g2.setDisplayRotation(U8G2_MIRROR);

}

uint8_t m = 24;

void loop(void) {
  char m_str[3];
  strcpy(m_str, u8x8_u8toa(m, 2));    /* convert m to a string with two digits */
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_crox4tb_tf);       //see https://github.com/olikraus/u8g2/wiki/fntlist99
    u8g2.drawStr(0,63,"9");
    u8g2.drawStr(33,63,":");
    u8g2.drawStr(50,63,m_str);
  } while ( u8g2.nextPage() );
  delay(1000);
  m++;
  if ( m == 59 )
    m = 0;
}
