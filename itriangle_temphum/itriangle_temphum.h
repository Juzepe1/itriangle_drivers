/*
 * grove_temp_hum.h
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



#ifndef __ITRIANGLE_TEMPHUM_CLASS_H__
#define __ITRIANGLE_TEMPHUM_CLASS_H__

#include "suli2.h"

//GROVE_NAME        "Temperature and humidity sensor"
//SKU               180401027
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/27.png
//DESCRIPTION       "This is a multifunctional sensor that gives you temperature and relative humidity information at the same time. It utilizes a DHT11 sensor that can meet measurement needs of general purposes. It provides reliable readings when environment humidity condition in between 20% RH and 90% RH, and temperature condition in between 0°C and 50°C, covering needs in most home and daily applications that don't contain extreme conditions."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/temperature-and-humidity
//ADDED_AT          "2018-06-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/teplota-a-vlhkost-142?category=81
//LANG              [{"source": "Temphum.Name","en": "Temperature and humidity sensor","cs": "Senzor teploty a vlhkosti"},{"source": "Temphum.Description","en": "This is a multifunctional sensor that gives you temperature and relative humidity information at the same time. It utilizes a DHT11 sensor that can meet measurement needs of general purposes. It provides reliable readings when environment humidity condition in between 20% RH and 90% RH, and temperature condition in between 0°C and 50°C, covering needs in most home and daily applications that don't contain extreme conditions.","cs": "Senzor teploty a vlhkosi je určený pro měření relativní vlhkosti vzduchu v rozsahu 20-90%."},{"source": "read_thtemperature","en": "get temperature °C","cs": "zjisti teplotu °C"},{"source": "read_thtemperature_f","en": "get temperature °F","cs": "zjisti teplotu °F"},{"source": "read_thhumidity","en": "get humidity","cs": "zjisti relativní vlhkost"},{"source": "Temphum.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/temperature-and-humidity", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/teplota-a-vlhkost"}]
//ITR_NAME          Temphum.Name
//ITR_DESCRIPTION   Temphum.Description
//ITR_WIKI			Temphum.Wiki

#define MAXTIMINGS 85
#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

#ifdef ESP8266
#define PULSE_COUNTER              20
#elif defined(__MBED__)
#define PULSE_COUNTER              20
#else
#define PULSE_COUNTER              6
#endif


class ItriangleTemphum
{
public:
    ItriangleTemphum(int pin);

    /**
     * The basic temperature and humidity sensor will update the reading every 2 seconds.
     *
     * @param celsius_degree - unit: Celsius degree
     *
     * @return bool
     */
    bool read_thtemperature(float *celsius_degree);

    /**
     * The basic temperature and humidity sensor will update the reading every 2 seconds.
     *
     * @param fahrenheit_degree - Fahrenheit degree
     *
     * @return bool
     */
    bool read_thtemperature_f(float *fahrenheit_degree);

    /**
     * The basic temperature and humidity sensor will update the reading every 2 seconds.
     *
     * @param humidity - 0~100(%)
     *
     * @return bool
     */
    bool read_thhumidity(float *humidity);

private:
    IO_T *io;
    bool _read(IO_T *io);
    float _convertCtoF(float c);
    uint8_t _type;
    uint8_t _count;
    bool firstreading;
    unsigned long _lastreadtime;
    uint8_t data[6];

};

#endif
