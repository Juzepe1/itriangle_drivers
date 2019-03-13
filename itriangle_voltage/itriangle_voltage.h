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


#ifndef __ITRIANGLE_VOLTAGE_H__
#define __ITRIANGLE_VOLTAGE_H__

#include "suli2.h"

//GROVE_NAME        "DC Voltage sensor"
//SKU               180401012
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/1.png
//DESCRIPTION       "The voltage sensor provides an interface for measuring extern DC voltage. The voltage gain can be selected by dial switch."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/voltage
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/napeti-146?category=81
//LANG              [{"source": "Voltage2.Name","en": "DC Voltage sensor","cs": "Senzor stejnosměrného napětí"},{"source": "Voltage2.Description","en": "The voltage sensor provides an interface for measuring extern DC voltage. The voltage gain can be selected by dial switch.","cs": "Senzor napětí umoňuje měřit stejnosměrné napětí na vstupu. Přímo na senzoru je přepínač zisku/děliče v rozsazích 3 a 10."},{"source": "read_voltage_x3","en": "get voltage gain 3","cs": "zjisti napětí s děličem 3"},{"source": "read_voltage_x10","en": "get voltage gain 10","cs": "zjisti napětí s děličem 10"},{"source": "read_adc_value","en": "get ADC value","cs": "zjisti hodnotu ADC"},{"source": "Voltage2.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/voltage", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/nap%C4%9Bt%C3%AD"}]
//ITR_NAME          Voltage2.Name
//ITR_DESCRIPTION   Voltage2.Description
//ITR_WIKI			Voltage2.Wiki

class ItriangleVoltage
{
public:
    ItriangleVoltage(int pin);

    /**
     * Get voltage with gain of 3.
     *
     * @param get_voltage_x3 - units: V
     *
     * @return bool
     */
    bool read_voltage_x3(float *get_voltage_x3);

    /**
     * Get voltage with gain of 10 .
     *
     * @param get_voltage_x10 - units: V
     *
     * @return bool
     */
    bool read_voltage_x10(float *get_voltage_x10);
    
    /**
     * Get raw value from ADC 0-1023.
     *
     * @param get_adc_value - raw adc value 0-1023
     *
     * @return bool
     */
    bool read_adc_value(int *get_adc_value);
    
    
    
    
    

private:
    ANALOG_T *io;
};


#endif
