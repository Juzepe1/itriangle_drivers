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


#ifndef __ITRIANGLE_SOUND_H__
#define __ITRIANGLE_SOUND_H__

#include "suli2.h"

//GROVE_NAME        "Sound sensor"
//SKU               180401013
//IF_TYPE           ANALOG
//IMAGE_URL         https://code.itriangle.cz/static/pictures/3.png
//DESCRIPTION       "Loudness sensor measures the level of ambient sound. Sensitivity to loudness is adjustable with a potentionmeter located on the sensor."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/sound
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/zvuk-140?category=81
//LANG              [{"source": "Sound.Name","en": "Loudness sensor","cs": "Senzor hlasitosti"},{"source": "Sound.Description","en": "Loudness sensor measures the level of ambient sound. Sensitivity to loudness is adjustable with a potentionmeter located on the sensor.","cs": "Senzor hlasitosti měří hodnotu okolního hluku. Naměřená hodnota je relativní a vyjádřena jako aktuální hodnota na A/D převodníku. Citlivost na okolní hluk je možné  nastavit pomocí potenciometru přímo na senzoru."},{"source": "read_sound_level","en": "get sound level","cs": "zjisti hlasitost"},{"source": "read_sound_value","en": "get ADC value","cs": "načti hodnotu ADC"},{"source": "Sound.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/sound", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/zvuk"}]
//ITR_NAME          Sound.Name
//ITR_DESCRIPTION   Sound.Description
//ITR_WIKI			Sound.Wiki



class ItriangleSound
{
public:
    ItriangleSound(int pin);

    /**
    * Gets relative loudness of ambient sound. Sensitivity can be set by potentiometer.
    *
    * @param get_loudness - relative loudness of ambient sound (0-100% of sensor sensitivity range)
    *
    * @return bool
    */
    bool read_sound_level(int *get_loudness);
    
    
    /**
    * Gets raw ADC value of ambient sound. Sensitivity can be set by potentiometer.
    *
    * @param get_ADC_value - raw value 0-1023
    *
    * @return bool
    */
    bool read_sound_value(int *get_ADC_value);
    
    

private:
    ANALOG_T *io;
};

#endif
