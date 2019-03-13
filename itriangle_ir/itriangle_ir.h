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


#ifndef __ITRIANGLE_IR_H__
#define __ITRIANGLE_IR_H__

#include "suli2.h"

//GROVE_NAME        "Infrared interrupter"
//SKU               180401041
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/7.png
//DESCRIPTION       "Infrared sensor for small distance obstacle detection."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/ir
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/infracerveny-senzor-detekce-objektu-v2-0-130?category=81
//LANG              [{"source": "IR.Name","en": "Infrared interrupter","cs": "Infračervený senzor"},{"source": "IR.Description","en": "Infrared sensor for small distance obstacle detection.","cs": "Infračervený senzor pro detekci překážek v malých vzdálenostech."},{"source": "read_status","en": "get state","cs": "zjisti stav"},{"source": "obstacle_detected","en": "if detected","cs": "když detekováno"},{"source": "IR.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/ir", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/infra%C4%8Derven%C3%BD-senzor-detekce-objektu"}]
//ITR_NAME          IR.Name
//ITR_DESCRIPTION   IR.Description
//ITR_WIKI			IR.Wiki

class ItriangleIR
{
public:
    ItriangleIR(int pin);

    /**
     * Get a state of presence of near distance obstacle.
     *
     * @param get_status - 1: obstacle detected 0: obstacle not detected
     *
     * @return bool
     */
    bool read_status(uint8_t *get_status);

    /**
     * Event wheh some obstacle is detected.
     */
    DEFINE_EVENT(obstacle_detected, SULI_EDT_INT);
    IO_T *io;
    uint32_t time;
};

static void approach_interrupt_handler(void *para);


#endif
