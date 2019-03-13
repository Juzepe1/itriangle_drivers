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


#ifndef __ITRIANGLE_LIGHT_H__
#define __ITRIANGLE_LIGHT_H__

#include "suli2.h"

//GROVE_NAME        "Light sensor"
//SKU               180401028
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/28.png
//DESCRIPTION       "Light sensor measures intensity of ambient light."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/light
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/senzor-svetla-133?category=81
//LANG              [{"source": "Light.Name","en": "Light sensor","cs": "Senzor světla"},{"source": "Light.Description","en": "Light sensor measures intensity of ambient light. Output value is a number from 0-1023 or ADC voltage.","cs": "Senzor světla měří míru okolního světla. Naměřené hodnoty se nacházehí v rozsahu 0-1023."},{"source": "read_light_lux","en": "get lux","cs": "zjisti osvětlení"},{"source": "read_ADC_light_value","en": "get ADC value","cs": "zjisti hodnotu ADC"},{"source": "Light.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/light", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/senzor-sv%C4%9Btla"}]
//ITR_NAME          Light.Name
//ITR_DESCRIPTION   Light.Description
//ITR_WIKI			Light.Wiki

class ItriangleLight
{
public:
    ItriangleLight(int pin);

    /**
    * Gets value of ambient light.
    *
    * @param get_light - light value
    *
    * @return bool
    */
    bool read_light_lux(float *get_light);
    
    
    /**
    * Gets raw value of ADC (0-1023)
    *
    * @param get_ADC_value - raw ADC value (0-1023)
    *
    * @return bool
    */
    bool read_ADC_light_value(float *get_ADC_value);
    

private:
    float _multi_map(float val, float * _in, float * _out, uint8_t size);

    ANALOG_T *io;
};

#endif
