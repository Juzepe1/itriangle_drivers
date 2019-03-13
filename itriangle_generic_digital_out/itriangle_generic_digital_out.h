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


#ifndef __ITRIANGLE_GENERIC_DIGITAL_OUT_H__
#define __ITRIANGLE_GENERIC_DIGITAL_OUT_H__

#include "suli2.h"

//GROVE_NAME        "Generic Digital Output"
//SKU               180401008
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/20.png
//DESCRIPTION       "Generic Digital Out can output a digital signal to IO. It can control another device. It also can be read for digital IO state. Optionally it is possible to pulse in for desired time in milliseconds."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/generic-digital-out
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            http://en.itriangle.cz/shop/180401008
//LANG              [{"source": "GDO.Name","en": "Generic Digital Output","cs": "Obecný digitální výstup"},{"source": "GDO.Description","en": "Generic Digital Out can output a digital signal to IO. It can control another device. It also can be read for digital IO state. Optionally it is possible to pulse in for desired time in milliseconds.","cs": "Obecný digitální výstup umožňuje nastavení výstupu na hodnotu 0 nebo 1 (pro sepnutí nebo řízení dalšího obvodu), případně umožňuje vygenerovat puls o určité délce."},{"source": "write_gdout_onoff","en": "set on/off","cs": "zapnout/vypnout"},{"source": "read_gdout_onoff_status","en": "get actual state","cs": "zjisti stav"},{"source": "write_gdout_high_pulse","en": "pulse high ms","cs": "zapni na [ms]"},{"source": "write_gdout_low_pulse","en": "pulse low ms","cs": "vypni na [ms]"},{"source": "GDO.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/generic-digital-out", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/obecn%C3%BD-digit%C3%A1ln%C3%AD-out"}]
//ITR_NAME          GDO.Name
//ITR_DESCRIPTION   GDO.Description
//ITR_WIKI			GDO.Wiki

class ItriangleGenericDOut
{
public:
    ItriangleGenericDOut(int pin);

    /**
     * Control a generic digital output by writing 1 to pull it high and 0 to pull it low.
     *
     * @param set_state - 1: pull high, 0: pull low
     *
     * @return bool
     */
    bool write_gdout_onoff(int set_state);

    /**
     * Read back the status of this output pin
     *
     * @param read_state - 1: high, 0: low
     *
     * @return bool
     */
    bool read_gdout_onoff_status(int *read_state);

    /**
     * Output a high pulse in milliseconds
     *
     * @param pulse_high - milliseconds
     *
     * @return bool
     */
    bool write_gdout_high_pulse(int pulse_high);

    /**
     * Output a low pulse in milliseconds
     *
     * @param pulse_low - milliseconds
     *
     * @return bool
     */
    bool write_gdout_low_pulse(int pulse_low);

    IO_T *io;
    TIMER_T *timer;
};

static void itriangle_gdout_timer_high_pulse_interrupt_handler(void *para);
static void itriangle_gdout_timer_low_pulse_interrupt_handler(void *para);

#endif
