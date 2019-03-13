/*
Software License Agreement (BSD License)

Copyright (c) 2012 Adafruit Industries.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef __ITRIANGLE_LEDPANEL8x8_H__
#define __ITRIANGLE_LEDPANEL8x8_H__

#include "suli2.h"
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"


//GROVE_NAME        "LED Matrix 8x8"
//SKU               180401143
//IF_TYPE           I2C
//IMAGE_URL         https://code.itriangle.cz/static/pictures/26.png
//DESCRIPTION       "8x8 LED matrix with possibility of addressing each pixel"
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/led-matrix-8x8
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/led-matice-8x8-131?category=82
//LANG              [{"source": "LEDPanel.Name","en": "LED Matrix 8x8","cs": "LED panel 8x8"},{"source": "LEDPanel.Description","en": "8x8 LED panel with ability of addressing each pixel","cs": "LED panel v uspořádání 8x8 s možností zápisu na každý pixel samostatně"},{"source": "write_text","en": "scroll text","cs": "ukaž text"},{"source": "write_character","en": "show character","cs": "ukaž znak"},{"source": "write_clearall","en": "clear matrix","cs": "zhasni panel"},{"source": "write_pixelon","en": "pixel ON","cs": "rozsviť bod"},{"source": "write_pixeloff","en": "pixel OFF","cs": "zhasni bod"},{"source": "write_pixeloff","en": "pixel OFF","cs": "zhasni bod"},{"source": "write_rotation","en": "set rotation","cs": "nastav směr"},{"source": "read_rotation","en": "get rotation","cs": "zjisti směr"},{"source": "write_frown","en": "frown","cs": "zamračený"},{"source": "write_neutral","en": "neutral","cs": "neutrální"},{"source": "write_smile","en": "smile","cs": "úsměv"},{"source": "write_lightall","en": "light matrix","cs": "rozsviť panel"},{"source": "write_brightness","en": "set brightness","cs": "nastav jas"},{"source": "write_blinkrate","en": "set blink rate","cs": "nastav mód blikaní"},{"source": "LEDPanel.Wiki", "en": "ttp://wiki.itriangle.cz/books/itriangle-eng/page/led-matrix-8x8", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/led-matice-8x8"}]
//ITR_NAME          LEDPanel.Name
//ITR_DESCRIPTION   LEDPanel.Description
//ITR_WIKI			LEDPanel.Wiki
                     
class ItriangleLedPanel8x8
{
public:
     ItriangleLedPanel8x8(int pinsda, int pinscl);
    
    
    
     /**  
     *  Writes a scrolling text to the LED matrix. Maximum text length is 256 characters, spaces included.
     *
     *  @param text -  simple text to write, maximum length of 265 characters
     *
     *
     */
         
    bool write_text(char *text);
    
     
    
    
    
     /**  
     *  Writes a single static character to the LED matrix
     *
     *  @param character  -  single character
     *
     *
     */
         
    bool write_character(char *character);
    
    
     
     /**  
     *  Clears the matrix
     *
     *
     *
     */
    
         
    bool write_clearall();
    
     
     /**  
     *  Lights all matrix LEDs
     *
     *
     *
     */
    
         
    bool write_lightall();
    
    
    /**  
     *  Sets brightness
     *
     * @param brightness -  0-100%
     *
     */
     bool write_brightness(uint8_t brightness);
    
    
  
     /**  
     *  Sets blink rate, 0-none 1- 2- 3-
     *
     * @param blink mode -  values 0,1,2,3
     *
     */
     bool write_blinkrate(uint8_t blinkmode);
    
    
    
    /**  
     *  Sets single pixel on. Coordinates x and y. 
     *
     *  @param x - x coordinate 1-8
     *  @param y - y coordinate 1-8
     *
     *
     */
    
    
         
    bool write_pixelon(uint8_t x, uint8_t y);
    
     /**  
     *  Sets single pixel off. Coordinates x and y. 
     *
     *  @param x - x coordinate 1-8
     *  @param y - y coordinate 1-8
     *
     *
     */
         
    bool write_pixeloff(uint8_t x, uint8_t y);
    
    
     /**  
     *  Sets rotation of matrix. It has influence of text text ang grapic orientation. 
     *
     *  @param rotation - number 1-4  
     
     *
     *
     */
         
    bool write_rotation(uint8_t rotation);
    
    
    /**  
     *  Gets actual rotation value.     
     *
     *
     */
         
    bool read_rotation(uint8_t *act_rotation);
    
   
    /**  
     *  Shows smiling face.
     *
     *
     *
     */
         
    bool write_smile();
    
    
    /**  
     *  Shows neutral face.
     *
     *
     *
     */
         
    bool write_neutral();
    
    
    /**  
     *  Shows frown face.
     *
     *
     *
     */
         
    bool write_frown();
    
    
    
 
    
    
    
    
    //static const uint8_t PROGMEM smile_bmp[8], neutral_bmp[8], frown_bmp[8];

private:
    I2C_T *i2c;
    Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
    
        

    
     

};



#endif
