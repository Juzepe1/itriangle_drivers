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


#ifndef __ITRIANGLE_ULTRASOUND_H__
#define __ITRIANGLE_ULTRASOUND_H__

#include "suli2.h"

//GROVE_NAME        "Ultrasonic distance sensor"
//SKU               180401018
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/8.png
//DESCRIPTION       "Ultrasonic sensor allows non-contact measuring of distance within range from 4cm to 400cm."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/ultrasonic
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/ultrazvukovy-senzor-vzdalenosti-145?category=81
//LANG              [{"source": "US.Name","en": "Ultrasonic distance sensor","cs": "Ultrazvukový senzor vzdálenosti"},{"source": "US.Description","en": "Ultrasonic sensor allows non-contact measuring of distance within range from 4cm to 400cm.","cs": "Ultrazvukový senzor vzdálenosti umožňuje bezkontaktní měření vzdálenosti v rozsahu cca 4cm - 400cm."},{"source": "read_distance_in_cm","en": "get distance in cm","cs": "zjisti vzdálenost v cm"},{"source": "read_distance_in_inch","en": "get distance in inch","cs": "zjisti vzdálenost v palcích"},{"source": "US.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/ultrasonic", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/ultrazvukov%C3%BD-senzor-vzd%C3%A1lenosti"}]
//ITR_NAME          US.Name
//ITR_DESCRIPTION   US.Description
//ITR_WIKI			US.Wiki

class ItriangleUltraRanger
{
public:
    ItriangleUltraRanger(int pin);

    /**
     * Get distance to measured object in centimetres.
     *
     * @param get_distance_cm - distance in [cm]
     *
     * @return bool
     */
    bool read_distance_in_cm(float *get_distance_cm);

    /**
     * Get distance to measured object in inches.
     *
     * @param get_distance_in - [inch]
     *
     * @return bool
     */
    bool read_distance_in_inch(float *get_distance_in);
    IO_T *io;

private:
    uint32_t _get_pulse_width();
};

#endif
