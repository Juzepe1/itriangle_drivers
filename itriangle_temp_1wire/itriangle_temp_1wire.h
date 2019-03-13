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


#ifndef __ITRIANGLE_TEMP_1WIRE_H__
#define __ITRIANGLE_TEMP_1WIRE_H__

#include "suli2.h"

//GROVE_NAME        "Waterproof temperature sensor"
//SKU               180401016
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/6.png
//DESCRIPTION       "Waterproof temperature sensor with measurement range from -55 to +110 °C. Only for short time measurements with temperatures above 90 °C."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/one-wire-temperature
//ADDED_AT          "2018-01-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/vodeodolny-teplomer-141?category=81
//LANG              [{"source": "DS.Name","en": "Waterproof temperature sensor","cs": "Vodotěsný teplotní senzor"},{"source": "DS.Description","en": "Waterproof temperature sensor with measurement range from -55 to +110 °C. Only for short time measurements with temperatures above 90 °C.","cs": "Vodotěsný teplotní senzor pro měření teplot v rozsahu -55°C - +110°C. Jen pro krátkodobá měření při teplotách nad 90°C."},{"source": "read_temp","en": "get temperature","cs": "zjisti teplotu"},{"source": "DS.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/one-wire-temperature", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/vod%C4%9Bodoln%C3%BD-teplom%C4%9Br"}]
//ITR_NAME          DS.Name
//ITR_DESCRIPTION   DS.Description
//ITR_WIKI			DS.Wiki


class ItriangleTemp1Wire
{
public:
	ItriangleTemp1Wire(int pin);

    /**
     * Get temperature from sensor in °C.
     *
     * @param get_temperature - units °C with accuracy of +-0.5°C .
     *
     * @return bool
     */
    bool read_temp(float *get_temperature);

private:
	IO_T *io;

	void pin_write(int value)
	{
		if (value) {
			suli_pin_dir(io, SULI_INPUT);
		}
		else {
			suli_pin_dir(io, SULI_OUTPUT);
			suli_pin_write(io, SULI_LOW);
		}
	}

	int pin_read()
	{
		return suli_pin_read(io) != SULI_LOW ? 1 : 0;
	}

	bool onewire_reset();
	bool onewire_skip_rom();
	bool onewire_write_scratchpad(uint8_t th, uint8_t tl, uint8_t config);
	int onewire_read_scratchpad(uint8_t* data, int dataSize);
	bool onewire_convert_t();

	bool internal_write_byte(uint8_t data);
	bool internal_read_byte(uint8_t* data);

};

#endif