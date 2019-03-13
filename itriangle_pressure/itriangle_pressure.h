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


#ifndef __ITRIANGLE_PRESSURE_H__
#define __ITRIANGLE_PRESSURE_H__

#include "suli2.h"
#include "math.h"

//GROVE_NAME        "High pressure sensor"
//SKU               180401003
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/5.png
//DESCRIPTION       "High pressure sensor with range from 0,15kPa to 1,2MPa."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/high-pressure
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/vysoky-tlak-137?category=81
//LANG              [{"source": "Press.Name","en": "High pressure sensor","cs": "Senzor vysokého tlaku"},{"source": "Press.Description","en": "High pressure sensor with range from 0,15kPa to 1,2MPa.","cs": "Senzor vysokého tlaku s rozsahem od 0,15kPa do 1,2MPa."},{"source": "read_adc_pressure_voltage","en": "get ADC voltage","cs": "načti napětí ADC"},{"source": "read_adc_pressure_value","en": "get ADC value","cs": "načti hodnotu ADC"},{"source": "read_pressure","en": "get pressure hPa","cs": "načti tlak v hPa"},{"source": "Press.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/high-pressure", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/vysok%C3%BD-tlak"}]
//ITR_NAME          Press.Name
//ITR_DESCRIPTION   Press.Description
//ITR_WIKI			Press.Wiki

class ItrianglePressure
{
public:
    ItrianglePressure(int pin);

    /**
     * Gets ADC input voltage. Pressure dependent.
     *
     * @param get_ADC_voltage - units: V
     *
     * @return bool
     */
    bool read_adc_pressure_voltage(float *get_ADC_voltage);
    
    /**
     * Gets ADC value from 0 to 1023. Pressure dependent.
     *
     * @param get_ADC_value - raw value 0-1023
     *
     * @return bool
     */
    bool read_adc_pressure_value(int *get_ADC_value);
    
    /**
     * Gets pressure value in hPa. No sea level correction.
     *
     * @param get_pressure - pressure in hPa
     *
     * @return bool
     */
    bool read_pressure(float *get_pressure);
    
    /**
     * Gets pressure value in hPa with sea level correction. Ambient temperature 20°C calculated.
     *
     * @param get_pressure_slvl - sea level pressure
     *      *
     * @param altitude - local altitude above sea level in metres
     *
     * @return bool
     */
    //bool read_pressureslvl(float *get_pressure_slvl, float altitude);
    

private:
    ANALOG_T *io;
};


#endif
