

#include "suli2.h"
#include "itriangle_generic_pwm_out.h"

ItriangleGenericPWMOut::ItriangleGenericPWMOut(int pin)
{
    this->io = (PWM_T *)malloc(sizeof(PWM_T));

    suli_pwm_init(this->io, pin);
    
    _freq = 1000;
    _percent = 0.0;
}

bool ItriangleGenericPWMOut::write_pwm(float duty_percent)
{
    _percent = duty_percent;
    
    suli_pwm_output(io, duty_percent);
    
    return true;
}
bool ItriangleGenericPWMOut::write_pwm_with_freq(float duty_percent, uint32_t freq)
{
    _freq = freq;
    _percent = duty_percent;
    
    suli_pwm_frequency(io, freq);
    suli_pwm_output(io, duty_percent);
    
    return true;
    
}
bool ItriangleGenericPWMOut::read_pwm(float *duty_percent, uint32_t *freq)
{
    *duty_percent = _percent;
    *freq = _freq;
    
    return true;
}
