/*
 * grove_moisture_class.cpp
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

#include "itriangle_moisture_class.h"

ItriangleMoisture::ItriangleMoisture(int pin)
{
    this->analog = (ANALOG_T *)malloc(sizeof(ANALOG_T));
    itriangle_moisture_init(this->analog, pin);
    _write_setup();
}

bool ItriangleMoisture::_write_setup(void)
{
    return itriangle_moisture_write_setup(this->analog);
}

bool ItriangleMoisture::read_moisture(uint16_t *moisture)
{
    return itriangle_moisture_readmoisture(analog, moisture);
}

static void moisture_interrupt_handler(void *para)
{
    ItriangleMoisture *g = (ItriangleMoisture *)para;
    if (millis() - g->time < 1000)
    {
        return;
    }
    g->time = millis();

    POST_EVENT_IN_INSTANCE(g, moisture_overlimit, g->io);
}