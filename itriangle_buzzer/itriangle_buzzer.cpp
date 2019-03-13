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

#include "suli2.h"
#include "itriangle_buzzer.h"

ItriangleBuzzer::ItriangleBuzzer(int pin)
{
    this->io = (IO_T *)malloc(sizeof(IO_T));
    this->timer = (TIMER_T *)malloc(sizeof(TIMER_T));
    
    suli_pin_init(io, pin, SULI_OUTPUT);
}

bool ItriangleBuzzer::write_onoff(int onoff)
{
    suli_pin_write(io, onoff);
    return true;
}

bool ItriangleBuzzer::read_onoff_status(int *onoff)
{
    *onoff = suli_pin_read(io);
    return true;
}

bool ItriangleBuzzer::write_soundon_time(int ms)
{
    suli_pin_write(io, 0);
    suli_pin_write(io, 1);
    suli_timer_install(timer, ms * 1000, itriangle_buzzer_timer_high_pulse_interrupt_handler, this, false);
    return true;
}


static void itriangle_buzzer_timer_high_pulse_interrupt_handler(void *para)
{
    ItriangleBuzzer *g = (ItriangleBuzzer *)para;
    suli_pin_write(g->io, 0);
}

