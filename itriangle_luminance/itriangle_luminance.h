/*
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


#ifndef __ITRIANGLE_LUMINANCE_H__
#define __ITRIANGLE_LUMINANCE_H__

#include "suli2.h"

//GROVE_NAME        "Luminance sensor"
//SKU               180401011
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/2.png
//DESCRIPTION       "Light sensor measures intensity of ambient light. Output values are mapped into Lux units."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/luminance
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/senzor-osvetleni-134?category=81
//LANG              [{"source": "Luminance.Name","en": "Luminance sensor","cs": "Senzor osvětlení"},{"source": "Luminance.Description","en": "Light sensor measures intensity of ambient light. Output values are mapped into Lux units.","cs": "Senzor osvětlení měří míru osvětlení okolního prostředí. Naměřené hodnoty jsou promítnuty do přibližných hodnot Lux."},{"source": "read_luminance","en": "get luminance value","cs": "zjisti hodnotu osvětlení"},{"source": "read_ADC_luminance_value","en": "get ADC value","cs": "zjisti hodnotu ADC"},{"source": "Luminance.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/luminance", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/senzor-osv%C4%9Btlen%C3%AD"}]
//ITR_NAME          Luminance.Name
//ITR_DESCRIPTION   Luminance.Description
//ITR_WIKI			Luminance.Wiki

class ItriangleLuminance
{
public:
    ItriangleLuminance(int pin);

    /**
    * Gets luminance of ambient light.
    *
    * @param get_luminance - luminance in Lux units
    *
    * @return bool
    */
    bool read_luminance(float *get_luminance);
    
    
    /**
    * Gets raw value of ADC (0-1023) - luminance dependent.
    *
    * @param get_ADC_value - raw ADC value (0-1023)
    *
    * @return bool
    */
    bool read_ADC_luminance_value(float *get_ADC_value);
    

private:
    float _multi_map(float val, float * _in, float * _out, uint8_t size);

    ANALOG_T *io;
};

#endif
