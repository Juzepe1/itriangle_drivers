/*
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


#ifndef __ITRIANGLE_RELAY_H__
#define __ITRIANGLE_RELAY_H__

#include "suli2.h"
#include "itriangle_relay.h"

//GROVE_NAME        "Relay"
//SKU               180401002
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/10.png
//DESCRIPTION       "Relay acts as a switch, which is off in normal state. When a signal high (1) is applied, the relay acts as a switch in ON state. Maximum voltage and current ratings are 230V/5A."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/relay
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/rele-138?category=82
//LANG              [{"source": "Relay.Name","en": "Relay","cs": "Relé"},{"source": "Relay.Description","en": "Relay acts as a switch, which is off in normal state. When a signal high (1) is applied, the relay acts as a switch in ON state. Maximum voltage and current ratings are 230V/5A.","cs": "Relé funguje jako vypínač v obvodu ovládaný řídícím signálem. Když je přiveden signál 1 (HIGH) -  relé sepne, v opačném případě zůstává rozepnuté. Maximální hodnoty napětí a proudu jsou 230V/5A."},{"source": "write_onoff","en": "set on(1) / off(0)","cs": "zapni(1) / vypni(0)"},{"source": "read_onoff_status","en": "get actual state","cs": "zjisti stav"},{"source": "write_ontime","en": "set on [s]","cs": "zapni na [s]"},{"source": "write_offtime","en": "set off [s]","cs": "vypni na [s]"},{"source": "write_inverted","en": "invert actual state","cs": "přepni stav"},{"source": "Relay.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/relay", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/rel%C3%A9"}]
//ITR_NAME          Relay.Name
//ITR_DESCRIPTION   Relay.Description
//ITR_WIKI			Relay.Wiki

class ItriangleRelay
{
public:
    ItriangleRelay(int pin);

    /**
     *
     *
     * @param set_onoff - 1: switch on, 0: switch off
     *
     * @return bool
     */
    bool write_onoff(int set_onoff);

    /**
     * Gets actual relay state
     *
     * @param get_onoff - 1: ON/HIGH, 0: OFF/LOW
     *
     * @return bool
     */
    bool read_onoff_status(int *get_onoff);

    /**
     *
     *
     * @param ontime - time in seconds (1-60) in ON state
     *
     * @return bool
     */
    bool write_ontime(int ontime);
    
    /**
     *
     *
     * @param offtime - time in seconds (1-60) in OFF state
     *
     * @return bool
     */
    bool write_offtime(int offtime);

    /**
     *
     *
     * @param no parameters, just inverts actual state
     *
     * @return bool
     */
    bool write_inverted();


    TIMER_T *timer;
    IO_T *io;
};

static void itriangle_relay_timer_high_pulse_interrupt_handler(void *para);
static void itriangle_relay_timer_low_pulse_interrupt_handler(void *para);

#endif
