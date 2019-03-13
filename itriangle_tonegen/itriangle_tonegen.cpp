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
#include "itriangle_tonegen.h"


ItriangleToneGen::ItriangleToneGen(int pin)
{
    this->io = (PWM_T *)malloc(sizeof(PWM_T));

    suli_pwm_init(this->io, pin);
    suli_pin_write(this->io, SULI_LOW);
    setup_times(tempo); //set times for silence and note sounds
}



bool ItriangleToneGen::write_demo(int duration)     //freq ok
{
    
   
    duration = constrain(duration, 1,5); 
    for (int i=0; i < (sizeof(_freqs)/sizeof(_freqs[0]));i++){
      _sound(_freqs[i],nduration[duration-1]);
      _silence(sduration[duration-1]);
    }
    return true;  
}


bool ItriangleToneGen::write_c6(int duration)     //freq ok
{
     duration = constrain(duration, 1,5); 
    _sound(1058,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_d6(int duration)    //   freq ok
{
     duration = constrain(duration, 1,5); 
    _sound(1183,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_e6(int duration)       //   freq ok
{
     duration = constrain(duration, 1,5); 
    _sound(1325,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_f6(int duration)     //   freq ok
{
    duration = constrain(duration, 1,5);  
    _sound(1480,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_g6(int duration)     //   freq ok
{
    duration = constrain(duration, 1,5);  
    _sound(1600,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_a6(int duration)    //   freq ok
{
     duration = constrain(duration, 1,5); 
    _sound(1760,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_b6(int duration)
{
    duration = constrain(duration, 1,5);  
    _sound(2000,nduration[duration-1]);        //   freq ok
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_c7(int duration)    //   freq ok
{
     duration = constrain(duration, 1,5); 
    _sound(2120,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_d7(int duration)     //   freq ok
{
     
    duration = constrain(duration, 1,5); 
    _sound(2360,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_e7(int duration)       //freq ok
{
    duration = constrain(duration, 1,5);  
    _sound(2600,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_f7(int duration)       //   freq ok
{
    duration = constrain(duration, 1,5);  
    _sound(2800,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_g7(int duration)        //   freq ok
{
    duration = constrain(duration, 1,5);  
    _sound(3130,nduration[duration-1]);
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_a7(int duration)
{
    duration = constrain(duration, 1,5);  
    _sound(3520,nduration[duration-1]);          //   freq ok
    _silence(sduration[duration-1]);
}

bool ItriangleToneGen::write_b7(int duration)
{
    duration = constrain(duration, 1,5);  
    _sound(3750,nduration[duration-1]);
    _silence(sduration[duration-1]);
}






void ItriangleToneGen::_sound(int freq, int duration)
{
    suli_pwm_frequency(this->io, freq);
    suli_pwm_output(this->io, 50);
    for (int i=0;i < duration;i++){
      suli_delay_ms(1); //waiting for sound end
    }
    suli_pwm_output(this->io,0);
}

bool ItriangleToneGen::write_silence_ms(int duration_ms)
{
   _silence(duration_ms); // calling internal function for silence
    return true;
}

void ItriangleToneGen::_silence(int silence)
{
   suli_pwm_output(this->io,0);
   for (int i = 0; i < silence;i++){ 
     suli_delay_ms(1); // waiting for silence end       
   } 
}





//duration: the time sounds, unit: ms
//freq: the frequency of speaker, unit: Hz
bool ItriangleToneGen::write_sound_ms(int freq, int duration_ms)
{
    if(freq == 0 || duration_ms == 0) return false;

	uint32_t interval = (uint32_t)1000000 / freq;//convert the unit to us

    if (interval > 10000)
    {
        interval = 10000;
    } else if (interval < 5)
    {
        interval = 5;
    }

    uint32_t times = (uint32_t)duration_ms * 1000 / interval; //calcuate how many times the loop takes
    uint32_t times_5ms = 5000 / interval;

    if (interval > 2000)
    {
        for (int i = 0; i < times; i++)
     	{
    		suli_pin_write(this->io, SULI_HIGH);
    		suli_delay_ms(interval/2000);
    		suli_pin_write(this->io, SULI_LOW);
    		suli_delay_ms(interval/2000);
        }
    } else
    {
        for (int i = 0; i < times; i++)
     	{
    		suli_pin_write(this->io, SULI_HIGH);
    		suli_delay_us(interval/2);
    		suli_pin_write(this->io, SULI_LOW);
    		suli_delay_us(interval/2);
            if (i % times_5ms == (times_5ms-1))
            {
                suli_delay_ms(0); //yield the cpu
            }
        }
    }

    return true;
}

bool ItriangleToneGen::write_sound_start(int freq)
{
    suli_pwm_frequency(this->io, freq);
    suli_pwm_output(this->io, 50);
    return true;
}


bool ItriangleToneGen::write_sound_stop()
{
    suli_pwm_output(this->io, 0);
    return true;
}

bool ItriangleToneGen::write_bpm(int bpm )
{
    setup_times(bpm);
    return true;
}



void ItriangleToneGen::setup_times(int bpm)             //   1:9 ratio of of silence:sound
{
    tempo = constrain(bpm,10,240);
    sduration[0] = 60000/tempo/10;        //calculate length of note silence to be able to dostinquish following notes
    nduration[0] = 9*(sduration[0]);      //calculate note duration of full note 1/1
    sduration[1] = sduration[0] /2;       //calculate durations of shorter notes and silences
    nduration[1] = nduration[0] /2;
    sduration[2] = sduration[0] /4;
    nduration[2] = nduration[0] /4;
    sduration[3] = sduration[0] /8;
    nduration[3] = nduration[0] /8;
    sduration[4] = sduration[0] /16;
    nduration[4] = nduration[0] /16;
    
    
    
    
}