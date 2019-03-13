#ifndef __ITRIANGLE_PIR_MOTION_H__
#define __ITRIANGLE_PIR_MOTION_H__

#include "suli2.h"

//GROVE_NAME        "PIR Motion Sensor"
//SKU               1804010022
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/24.png
//DESCRIPTION       "The sensor outputs HIGH (1), when some IR object is detected."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/pir-motion
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/pir-pohybove-cidlo-136?category=81
//LANG              [{"source": "PIR.Name","en": "PIR Motion Sensor","cs": "Senzor pohybu"},{"source": "PIR.Description","en": "The sensor outputs HIGH (1), when some IR object is detected.","cs": "PIR senzor pohybu detekuje infračervené záření. Když je objekt v dosahu senzoru, tak je na senzoru signál 1 (HIGH)."},{"source": "read_approach","en": "get actual state","cs": "zjisti stav"},{"source": "ir_moved","en": "if detected","cs": "když detekováno"},{"source": "PIR.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/pir-motion", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/pir-pohybov%C3%A9-%C4%8Didlo"}]
//ITR_NAME          PIR.Name
//ITR_DESCRIPTION   PIR.Description
//ITR_WIKI			PIR.Wiki

class ItrianglePIRMotion
{
public:
    ItrianglePIRMotion(int pin);

    /**
     * Detect the motion/aproach of IR object
     *
     * @param approach - 1: IR object detected, 0: no IR object detected
     *
     * @return bool
     */
    bool read_approach(uint8_t *approach);

    /**
     * From "iTriangle - PIR Motion Sensor", triggered when IR object moved around.
     * Event data is the number of the PIN to which the grove is attached
     */
    DEFINE_EVENT(ir_moved, SULI_EDT_INT);
    IO_T *io;
    uint32_t time;
};

static void pir_motion_interrupt_handler(void *para);

#endif