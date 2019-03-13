
#ifndef __ITRIANGLE_WATERPUMP_H__
#define __ITRIANGLE_WATERPUMP_H__

#include "suli2.h"
#include "itriangle_waterpump.h"

//GROVE_NAME        "Water pump"
//SKU               180401021
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/25.png
//DESCRIPTION       "When a signal high (1) is applied, the water pump is able to push up water to 30cm height."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/waterpump
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/vodni-pumpa-147?search=Vodn%C3%AD+pumpa
//LANG              [{"source": "Water.Name","en": "Water pump","cs": "Vodní čerpadlo"},{"source": "Water.Description","en": "When a signal high (1) is applied, the water pump is able to push up water to 30cm height.","cs": "Vodní čerpadlo je ovládáno zapsáním 1 (zapnuto) nebo 0 (vypnuto). Výkon čerpadla stačí na vytlačení vody do výšky cca 30cm."},{"source": "write_onoff","en": "set on(1) / off(0)","cs": "zapni(1) / vypni(0)"},{"source": "write_ontime","en": "set on for [s]","cs": "zapni na [s]"},{"source": "write_inverted","en": "invert actual state","cs": "přepni stav"},{"source": "read_onoff_status","en": "get actual state","cs": "zjisti stav"},{"source": "Water.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/waterpump", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/vodn%C3%AD-pumpa"}]
//ITR_NAME          Water.Name
//ITR_DESCRIPTION   Water.Description
//ITR_WIKI			Water.Wiki

class ItriangleWaterPump
{
public:
    ItriangleWaterPump(int pin);

    /**
     *
     *
     * @param set_onoff - 1: switch on, 0: switch off
     *
     * @return bool
     */
    bool write_onoff(int set_onoff);
    
    /**
     *
     *
     * @param time - time in seconds for ON state (1-60)
     *
     * @return bool
     */
    bool write_ontime(int time);
    
    /**
     *
     *
     * @paramater no parameter - just inverts actual state
     *
     * @return bool
     */
    bool write_inverted();  
    

    /**
     * Gets actual waterpump state
     *
     * @param get_onoff - 1: ON/HIGH, 0: OFF/LOW
     *
     * @return bool
     */
    bool read_onoff_status(int *get_onoff);

    IO_T *io;
    TIMER_T *timer;
};

static void itriangle_waterpump_timer_high_pulse_interrupt_handler(void *para);

#endif
