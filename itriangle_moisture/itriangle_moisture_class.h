/*
 * grove_moisture_class.h
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Jacky Zhang
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


#ifndef __ITRIANGLE_MOISTURE_CLASS_H__
#define __ITRIANGLE_MOISTURE_CLASS_H__

#include "itriangle_moisture.h"

//GROVE_NAME        "Moisture sensor2"
//SKU               180401024
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/23.png
//DESCRIPTION       "Moisture sensor based on DC current measurement between two electrodes. Current is converted to analog voltage from 0-3.3V and then read with built in ADC."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/moisture                                                            
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/pudni-vlhkost-135?category=81
//LANG              [{"source": "Moisture.Name","en": "Moisture sensor","cs": "Senzor vlhkosti"},{"source": "Moisture.Description","en": "Moisture sensor based on DC current measurement between two electrodes. Current is converted to analog voltage from 0-3.3V and then read with built in ADC.","cs": "Senzor vlhkosti je založený na měření stejnosměrného proudu mezi dvěma elektrodami. Naměřená hodnota je následně bezrozměrně převedena na hodnotu A/D převodníku."},{"source": "read_moisture2","en": "get ADC value","cs": "zjisti hodnotu ADC"},{"source": "moisture2_overlimit","en": "if overlimit","cs": "když přes limit"},{"source": "Moisture.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/moisture", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/p%C5%AFdn%C3%AD-vlhkost"}]
//ITR_NAME          Moisture.Name
//ITR_DESCRIPTION   Moisture.Description
//ITR_WIKI			Moisture.Wiki

class ItriangleMoisture
{
public:
    ItriangleMoisture(int pin);

    /**
     *
     *
     * @param moisture - analog value, range: 0~1023
     *
     * @return bool
     */
    bool read_moisture(uint16_t *moisture);
	DEFINE_EVENT(moisture_overlimit, SULI_EDT_INT);
    IO_T *io;
    uint32_t time;
private:
    ANALOG_T *analog;
    bool _write_setup(void);
};
static void moisture_interrupt_handler(void *para);
#endif
