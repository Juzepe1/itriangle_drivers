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


#ifndef __ITRIANGLE_BUZZER_H__
#define __ITRIANGLE_BUZZER_H__

#include "suli2.h"

//GROVE_NAME        "Buzzer"
//SKU               180401004
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/12.png
//DESCRIPTION       "Buzzer is used to provide audio feedback to user."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/buzzer
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/bzucak-127?category=82
//LANG             [{"source": "Buzzer.Name","en": "Buzzer","cs": "Bzučák"},{"source": "Buzzer.Description","en": "Buzzer is used to provide audio feedback to user.","cs": "Bzučák poskytuje jednoduchý zvukový výstup."},{"source": "write_onoff","en": "set on(1)/ off(0)","cs": "zapni (1)/ vypni(0)"},{"source": "read_onoff_status","en": "get actual state","cs": "zjisti stav"},{"source": "write_soundon_time","en": "set on for [ms]","cs": "zapni na [ms] "},{"source": "Buzzer.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/buzzer", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/bzu%C4%8D%C3%A1k"}]
//ITR_NAME          Buzzer.Name
//ITR_DESCRIPTION   Buzzer.Description
//ITR_WIKI			Buzzer.Wiki



class ItriangleBuzzer
{
public:
    ItriangleBuzzer(int pin);

    /**
     * Control a generic digital output by writing 1 to pull it high and 0 to pull it low.
     *
     * @param set_onoff - 1: enable sound output, 0: disable sound output
     *
     * @return bool
     */
    bool write_onoff(int set_onoff);

    /**
     * Read back the status of buzzer output
     *
     * @param get_onoff - 1: sound on, 0: sound off
     *
     * @return bool
     */
    bool read_onoff_status(int *get_onoff);

    /**
     * Output a sound for desired time in milliseconds
     *
     * @param set_sound_ms - milliseconds
     *
     * @return bool
     */
    bool write_soundon_time(int set_sound_ms);

    IO_T *io;
    TIMER_T *timer;
};

static void itriangle_buzzer_timer_high_pulse_interrupt_handler(void *para);
//static void grove_relay_timer_low_pulse_interrupt_handler(void *para);

#endif
