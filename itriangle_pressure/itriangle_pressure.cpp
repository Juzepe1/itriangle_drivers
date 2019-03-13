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
#include "itriangle_pressure.h"

ItrianglePressure::ItrianglePressure(int pin)
{
    this->io = (ANALOG_T *)malloc(sizeof(ANALOG_T));

   suli_analog_init(io, pin);
}

bool ItrianglePressure::read_adc_pressure_voltage(float *voltage)
{
    *voltage = suli_analog_voltage(io);
    return true;
}

bool ItrianglePressure::read_adc_pressure_value(int *value)
{
    *value = suli_analog_read(io);
    return true;
}

bool ItrianglePressure::read_pressure(float *pressure)
{
    *pressure = ((suli_analog_read(io)-110)*12000.0f)/(810.0f);
       
    return true;
}

/*
bool ItrianglePressure::read_pressureslvl(float *pressureslvl, float altitude)
{
    *pressureslvl = ((suli_analog_read(io)-110)*12000.0f)/(810.0f)*pow((1-(0.0065*altitude)/(20+0.0065*altitude+273.15)),-5,257f);
    return true;
}   
*/