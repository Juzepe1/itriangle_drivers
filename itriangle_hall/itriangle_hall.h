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


#ifndef __ITRIANGLE_HALL_H__
#define __ITRIANGLE_HALL_H__

#include "suli2.h"


//GROVE_NAME        "Hall sensor"
//SKU               1804010050
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/4.png
//DESCRIPTION       "Magnetic field sensor based on Hall effect. Hall sensor detects North pole (1) of magnetic field."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/hall
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/magneticke-pole-129?category=81
//LANG              [{"source": "Hall.Name","en": "Hall sensor","cs": "Hallův sensor"},{"source": "Hall.Description","en": "Magnetic field sensor based on Hall effect. Hall sensor detects North pole (1) of magnetic field.","cs": "Hallův sensor je detektor magnetického pole založený na Hallově jevu. Detekuje severní pól magnetu (1)."},{"source": "read_magnetic_field","en": "get value","cs": "načti hodnotu"},{"source": "hall_pressed","en": "if detected","cs": "když detekováno"},{"source": "Hall.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/hall", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/magnetick%C3%A9-pole"}]
//ITR_NAME          Hall.Name
//ITR_DESCRIPTION   Hall.Description
//ITR_WIKI			Hall.Wiki


class ItriangleHall
{
public:
    ItriangleHall(int pin);

    /**
     * Gets orientation of magnetic field.
     *
     * @param get_magnetic_field - 0: North, 1: South or week magnetic field
     *
     * @return bool
     */
    bool read_magnetic_field(uint8_t *get_magnetic_field);

    /**
     * Event, which is triggered in presence of North magnetic pole.
     * Event data is pin number of Hall sensor.
     * Maximum detectable frequency of changes is about 100Hz.
     */
    DEFINE_EVENT(hall_pressed, SULI_EDT_INT);
    IO_T *io;
    uint32_t time;
};

static void hall_interrupt_handler(void *para);

#endif
