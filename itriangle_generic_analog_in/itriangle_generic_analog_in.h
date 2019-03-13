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


#ifndef __ITRIANGLE_GENERIC_ANALOG_IN_H__
#define __ITRIANGLE_GENERIC_ANALOG_IN_H__

#include "suli2.h"

//GROVE_NAME        "Generic Analog Input"
//SKU               180401006
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/18.png
//DESCRIPTION       "Generic Analog In can read raw analog value or voltage after ADC conversion."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/generic-analog-in
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            http://en.itriangle.cz/shop/180401006
//LANG              [{"source": "GAI.Name","en": "Generic Analog Input","cs": "Obecný analogový vstup"},{"source": "GAI.Description","en": "Generic Analog In can read raw analog value or voltage after ADC conversion.","cs": "Obecný analogový vstup umonuje přečíst hodnotu vstupního signálu ve formě napětí nebo jako hodnotu A/D převodníku."},{"source": "read_ganin_analog","en": "read ADC value","cs": "načti hodnotu ADC"},{"source": "read_ganin_voltage","en": "read ADC voltage","cs": "načti napětí na ADC"},{"source": "GAI.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/generic-analog-in", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/obecn%C3%BD-analogov%C3%BD-in"}]
//ITR_NAME          GAI.Name
//ITR_DESCRIPTION   GAI.Description
//ITR_WIKI			GAI.Wiki

class ItriangleGenericAIn
{
public:
    ItriangleGenericAIn(int pin);

    /**
     * Read the A/D converter measurement of a generic analog device. The full range is 0~1023.
     *
     * @param read_ADC_value - The measurement of A/D converter, 0~1023
     *
     * @return bool
     */
    bool read_ganin_analog(int *read_ADC_value);

    /**
     * Read the voltage after A/D conversion.
     *
     * @param read_ADC_voltage - unit: V
     *
     * @return bool
     */
    bool read_ganin_voltage(float *read_ADC_voltage);
private:
    ANALOG_T *io;
};


#endif
