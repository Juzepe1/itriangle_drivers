/*
 * itriangle_oled_12864.h
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Jack Shao
 *
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


#ifndef __OLED_128x64_SULI_H__
#define __OLED_128x64_SULI_H__

#include "suli2.h"

//GROVE_NAME        "iTriangle - OLED Display 0.96''"
//SKU               104030008
//IF_TYPE           I2C
//IMAGE_URL         https://raw.githubusercontent.com/Seeed-Studio/Grove_Drivers_for_Wio/static/images/grove-oled_12864.jpg
//DESCRIPTION       "iTriangle - OLED Display 0.96'' is an OLED monochrome 128×64dot matrix display module with iTriangle 4pin I2C Interface. The characteristics of this display module are high brightness, self-emission, high contrast ratio, slim outline, wide viewing angle, wide temperature range, and low power consumption. It has a bigger screen and uses all the columns from the SSD1308 chip so that it can display more contents than the OLED 96×96."
//WIKI_URL          http://wiki.seeedstudio.com/Grove-OLED_Display_0.96inch/
//ADDED_AT          "2015-10-01"
//AUTHOR            "BOXED"
//LANG               [{"source": "oled96.Name", "en": "oled96 display", "cs": "Displej oled96"},{"source": "oled96.Description", "en": "I2C display OLED with 128*64 resolution", "cs": "I2C displej s rozlišením 128*64 bodů"},{"source": "write_cleardisp", "en": "clear Display", "cs": "smaž displej"},{"source": "write_brightness", "en": "set brightness", "cs": "nastav jas"},{"source": "write_integer", "en": "print number", "cs": "vytiskni číslo"},{"source": "write_float", "en": "print float number", "cs": "vytiskni desetinné číslo"},{"source": "write_string", "en": "print string", "cs": "vytiskni znak"},{"source": "write_tasksetup", "en": "write_tasksetup", "cs": "write_tasksetup"},{"source": "write_taskvalues", "en": "print task values", "cs": "vytiskni hodnoty úlohy"},{"source": "write_taskvalues2", "en": "print task values 2", "cs": "vytiskni hodnoty úlohy 2"},{"source": "write_base64_string", "en": "print base64 string", "cs": "vytiskni base64 znak"},{"source": "write_scroll_left", "en": "scroll left", "cs": "scrolluj vlevo"},{"source": "write_scroll_right", "en": "scroll right", "cs": "scroluj vpravo"},{"source": "write_stop_scroll", "en": "stop scroll", "cs": "zastav scrolování"},{"source": "write_inverse_display", "en": "set inverse display", "cs": "nastav inverzi displeje"},{"source": "write_rotate_display", "en": "set display rotation", "cs": "nastav rotaci displeje"},{"source": "write_oledunit1", "en": "write 1st unit", "cs": "zadej 1. jednotku"},{"source": "write_oledunit2", "en": "write 2nd unit", "cs": "zadej 2. jednotku"},{"source": "write_oledunit3", "en": "write 3rd unit", "cs": "zadej 3. jednotku"},{"source": "write_oledunit4", "en": "write 4th unit", "cs": "zadej 4. jednotku"},{"source": "write_oledvariable1", "en": "write 1st variable", "cs": "zadej 1. veličinu"},{"source": "write_oledvariable2", "en": "write 2nd variable", "cs": "zadej 2. veličinu"},{"source": "write_oledvariable3", "en": "write 3rd variable", "cs": "zadej 3. veličinu"},{"source": "write_taskval1", "en": "write 1st value", "cs": "zadej 1. hodnotu"},{"source": "write_taskval2", "en": "write 2ndt value", "cs": "zadej 2. hodnotu"},{"source": "write_taskval3", "en": "write 3rd value", "cs": "zadej 3. hodnotu"},{"source": "write_taskval4", "en": "write 4th value", "cs": "zadej 4. hodnotu"},{"source": "write_taskval5", "en": "write 5th value", "cs": "zadej 5. hodnotu"},{"source": "write_oledvariable4", "en": "write 4th variable", "cs": "zadej 4. veličinu"},{"source": "4in1.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/4-in-1-sensor", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/4-in-1-sensor"}]
//ITR_NAME          oled96.Name
//ITR_DESCRIPTION   oled96.Description
//ITR_WIKI			oled96.Wiki

#define SeeedOLED_Max_X 		        127	//128 Pixels
#define SeeedOLED_Max_Y 		        63	//64  Pixels

#define PAGE_MODE			            01
#define HORIZONTAL_MODE			        02

#define SeeedOLED_Address		        0x78
#define SeeedOLED_Command_Mode		    0x80
#define SeeedOLED_Data_Mode		        0x40
#define SeeedOLED_Display_Off_Cmd	    0xAE
#define SeeedOLED_Display_On_Cmd	    0xAF
#define SeeedOLED_Normal_Display_Cmd	0xA6
#define SeeedOLED_Inverse_Display_Cmd	0xA7
#define SeeedOLED_Activate_Scroll_Cmd	0x2F
#define SeeedOLED_Dectivate_Scroll_Cmd	0x2E
#define SeeedOLED_Set_Brightness_Cmd	0x81

#define Scroll_Left			            0x00
#define Scroll_Right			        0x01

#define Scroll_2Frames			        0x7
#define Scroll_3Frames			        0x4
#define Scroll_4Frames			        0x5
#define Scroll_5Frames			        0x0
#define Scroll_25Frames			        0x6
#define Scroll_64Frames			        0x1
#define Scroll_128Frames		        0x2
#define Scroll_256Frames		        0x3


#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A



class ItriangleOLED12864
{
public:
    ItriangleOLED12864(int pinsda, int pinscl);

    /**
     * Clear the whole screen
     *
     * @return bool
     */
    bool write_cleardisp();

    /**
     * Set the brightness for the screen
     *
     * @param brightness - 0~255
     *
     * @return bool
     */
    bool write_brightness(uint8_t brightness);

    /**
     * Print a integer
     *
     * @param row - 0~7
     * @param col - 0~15
     * @param i - the integer to display
     *
     * @return bool
     */
    bool write_integer(uint8_t row, uint8_t col, int32_t i);

    /**
     * Print a float number
     *
     * @param row - 0~7
     * @param col - 0~15
     * @param f - float number
     * @param decimal - the decimal bits
     *
     * @return bool
     */
    bool write_float(uint8_t row, uint8_t col, float f, uint8_t decimal);

    /**
     * Print a string in one line.
     * Note that the char must be letter or number, special chars may be ignored.
     * To display multilines and special chars, please use base64_string API.
     *
     * @param row - 0~7
     * @param col - 0~15
     * @param str - the string to display
     *
     * @return bool
     */
    bool write_string(uint8_t row, uint8_t col, char *str);

    /**
     * Print a multiline string encoded in base64.
     * Special chars is supported.
     *
     * @param row - 0~7
     * @param col - 0~15
     * @param task - the string to display
     *
     * @return bool
     */
    bool write_taskname(char *taskname);
    bool write_tasksetup();
    bool write_taskval1(float taskval1);
    bool write_taskval2(float taskval2);
    bool write_taskval3(float taskval3);
    bool write_taskval4(float taskval4);
    bool write_taskval5(float taskval5);
    bool write_taskvalues2(float tsk2val1, float tsk2val2, float tsk2val3, float tsk2val4);      
    
    bool write_oledunit1(char *oledunit1);
    bool write_oledunit2(char *oledunit2);
    bool write_oledunit3(char *oledunit3);
    bool write_oledunit4(char *oledunit4);
    
    
    bool write_oledvariable1(char *oledvar1);
    bool write_oledvariable2(char *oledvar2);
    bool write_oledvariable3(char *oledvar3);
    bool write_oledvariable4(char *oledvar4);
    
    /**
     * Print a multiline string encoded in base64.
     * Special chars is supported.
     *
     * @param task - base64 encoded string, the max length is 256
     * @param col - 0~15
     * @param b64_str - base64 encoded string, the max length is 256
     *
     * @return bool
     */
	 
    bool write_base64_string(uint8_t row, uint8_t col, char *b64_str);

    /**
     * Let the specified rows to scroll left horizontally
     *
     * @param start_row - upper row index, 0~7
     * @param end_row - lower row index (closed range), 0~7, must be greater or equal start_row.
     * @param speed - 0~255
     *
     * @return bool
     */
    bool write_scroll_left(uint8_t start_row, uint8_t end_row, uint8_t speed);

    /**
     * Let the specified rows to scroll right horizontally
     *
     * @param start_row - upper row index, 0~7
     * @param end_row - lower row index (closed range), 0~7, must be greater or equal start_row.
     * @param speed - 0~255
     *
     * @return bool
     */
    bool write_scroll_right(uint8_t start_row, uint8_t end_row, uint8_t speed);

    /**
     * Stop all scrolling rows.
     *
     * @return bool
     */
    bool write_stop_scroll();

    /**
     * Set the screen to display in inverse mode.
     *
     * @param inverse_or_not - 1: inverse(white background), 0: normal(black background)
     *
     * @return bool
     */
    bool write_inverse_display(uint8_t inverse_or_not);

    /**
    * Set the screen to display in inverse mode.
    *
    * @param rotate_or_not - 1: inverse(white background), 0: normal(black background)
    *
    * @return bool
    */
    bool write_rotate_display(uint8_t rotate_or_not);

    char *get_last_error() { return error_desc; };


private:
    I2C_T *i2c;

    uint8 addressingMode = PAGE_MODE;
    char *error_desc;
    int last_row;

    // send command
    void oled_128x64_cmd(uint8_t command);
    // send data
    void oled_128x64_dta(uint8_t data);
    // horizontal mode
    void oled_128x64_hmode();
    // page mode
    void oled_128x64_pagemode();

    void oled_128x64_XY(uint8_t row, uint8_t column);

    void oled_128x64_char(uint8_t c);

    uint8_t oled_128x64_num(int32_t long_num);

    void oled_128x64_string(const char *str);

    void oled_128x64_hsp(bool direction, uint8_t startPage, uint8_t endPage, uint8_t scrollSpeed);

    void oled_128x64_active_scroll();

    void oled_128x64_deactive_scroll();

    void oled_128x64_normal_display();

    void oled_128x64_inversel_display();
};

#endif
