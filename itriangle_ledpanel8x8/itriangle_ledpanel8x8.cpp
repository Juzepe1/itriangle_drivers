/*
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "suli2.h"
#include "itriangle_ledpanel8x8.h"
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"



ItriangleLedPanel8x8::ItriangleLedPanel8x8(int pinsda, int pinscl)
{
    this->i2c = (I2C_T *)malloc(sizeof(I2C_T));
    suli_i2c_init(i2c, pinsda, pinscl);
    matrix.begin(0x70);  //inicializace displeje
    matrix.setTextSize(1);
    matrix.setTextWrap(false);  
    matrix.setTextColor(LED_ON);
}                                

 
bool ItriangleLedPanel8x8::write_smile()
{
     uint8_t smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 };
     
     matrix.clear();
     matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
     matrix.writeDisplay();
     
     return true;
}

bool ItriangleLedPanel8x8::write_neutral()
{
     
    uint8_t neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 };
     
     matrix.clear();
     matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
     matrix.writeDisplay();
     
     return true;
}

bool ItriangleLedPanel8x8::write_frown()
{
    uint8_t frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

     matrix.clear();
     matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
     matrix.writeDisplay();
     
     return true;
}


bool ItriangleLedPanel8x8::write_text(char *text)
{
    
    uint8_t length = strlen(text);
    
     if (text[0]='\''){
      text[0]=' ';
      text[length-1]= ' ';
    } 
    
    
    
    for (int16_t x=0; x >=-(length*6); x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print(text);
      matrix.writeDisplay();
      delay(100);
    }
     
     return true;
}




bool ItriangleLedPanel8x8::write_character(char *character)
{
    
    
    matrix.clear();
    matrix.setCursor(1,1);
    
    if (character[0]='\'') {
      matrix.print(character[1]);
    }   //if it comes as string
    else {
      int number = character[0]-'0';
      matrix.print(number);
    } //if it comes as number then ascii table !!!
       
    matrix.writeDisplay();
      
     
     return true;
 }

bool ItriangleLedPanel8x8::write_clearall()
{
     matrix.clear();
     matrix.writeDisplay();
     
     return true;
}


bool ItriangleLedPanel8x8::write_lightall()
{
     matrix.fillScreen(LED_ON);
     matrix.writeDisplay();
     
     return true;
}


bool ItriangleLedPanel8x8::write_brightness(uint8_t brightness)
{
     brightness = map(brightness,0,100,0,15);
     matrix.setBrightness(brightness);
     return true;
}

bool ItriangleLedPanel8x8::write_blinkrate(uint8_t blinkmode)
{
     if (blinkmode>3){blinkmode = 0;}
     
     matrix.blinkRate(blinkmode);
     return true;
}



bool ItriangleLedPanel8x8::write_pixelon(uint8_t x, uint8_t y)
{
     
     x = constrain(x,1,8);
     y = constrain(y,1,8);
     
     matrix.drawPixel(x-1, y-1, LED_ON);  
     matrix.writeDisplay();
     
     return true;
}


bool ItriangleLedPanel8x8::write_pixeloff(uint8_t x, uint8_t y)
{
    
     x = constrain(x,1,8);
     y = constrain(y,1,8);
     matrix.drawPixel(x-1, y-1, LED_OFF);  
     matrix.writeDisplay();
     
     return true;
}

bool ItriangleLedPanel8x8::write_rotation(uint8_t rotation)
{
     
     matrix.setRotation(rotation);
     
     return true;
}

bool ItriangleLedPanel8x8::read_rotation(uint8_t *act_rotation)
{
     
     *act_rotation = matrix.getRotation();
     
     return true;
}
