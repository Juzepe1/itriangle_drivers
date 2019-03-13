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




#ifndef __ITRIANGLE_BUTTON_H__
#define __ITRIANGLE_BUTTON_H__

#include "suli2.h"

//GROVE_NAME        "Button"
//SKU               1804010001
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/9.png
//DESCRIPTION       "Momentary push button. Signal high (1) when pressed , otherwise low (0)."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/button
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/tlacitko-126?category=82
//LANG              [{"source": "Button.Name", "en": "Button", "cs": "Tlačítko"},{"source": "Button.Description", "en": "Momentary push button. Signal high (1) when pressed , otherwise low (0).", "cs": "Tlačítko - při zmáčknutí signál 1 (HIGH), jinak 0 (LOW)"},{"source": "read_pressed", "en": "get state", "cs": "zjisti stav"},{"source": "button_pressed", "en": "if pressed", "cs": "když zmáčknuto"},{"source": "Button.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/button", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/tla%C4%8D%C3%ADtko"}]
//ITR_NAME          Button.Name
//ITR_DESCRIPTION   Button.Description
//ITR_WIKI			Button.Wiki

class ItriangleButton
{
public:
    ItriangleButton(int pin);

    /**
     * Gets actual button state
     *
     * @param get_state - 1: pressed, 0: not pressed
     *
     * @return bool
     */
    bool read_pressed(uint8_t *get_state);

    /**
     * Event when the button gets pressed.
     * Event data is the pin number.
     */
    DEFINE_EVENT(button_pressed, SULI_EDT_INT);
    IO_T *io;
    uint32_t time;
};

static void button_interrupt_handler(void *para);

#endif
