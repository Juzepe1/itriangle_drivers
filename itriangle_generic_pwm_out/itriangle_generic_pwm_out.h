


#ifndef __ITRIANGLE_GENERIC_PWM_OUT_H__
#define __ITRIANGLE_GENERIC_PWM_OUT_H__

#include "suli2.h"

//GROVE_NAME        "Generic PWM/Analog Output"
//SKU               63e25800-a2d2-11e5-bf7f-feff819cdc9f
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/21.png
//DESCRIPTION       "The Generic PWM can output a pwm signal whit specified frequency and duty. It also can be read for current state."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/generic-pwm-out
//ADDED_AT          "2015-12-01"
//AUTHOR            "BOXED"
//BUYURL            "http://itriangle.cz"
//LANG              [{"source": "PWM.Name","en": "Generic PWM/Analog Output","cs": "Obecný PWM výstup"},{"source": "PWM.Description","en": "The Generic PWM can output a pwm signal whit specified frequency and duty. It also can be read for current state.","cs": "Obecný PWM výstup umožňuje vygenerování signálu o různé frekvenci a střídě. Je možné zjistit i aktuální stav."},{"source": "write_pwm","en": "1kHz PWM duty","cs": "1kHz PWM signál střída"},{"source": "write_pwm_with_freq","en": "PWM signal freq/duty","cs": "PWM signál s frekv. a střídou"},{"source": "read_pwm","en": "get PWM duty","cs": "zjisti střídu"},{"source": "PWM.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/generic-pwm-out", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/obecn%C3%BD-pwm-out"}]
//ITR_NAME          PWM.Name
//ITR_DESCRIPTION   PWM.Description
//ITR_WIKI			PWM.Wiki


class ItriangleGenericPWMOut
{
public:
    ItriangleGenericPWMOut(int pin);

    /**
     * Output a PWM wave on specified IO. The default frequency is 1K Hz.
     *
     * @param duty_percent - 0.0~100.0, float number
     *
     * @return bool
     */
    bool write_pwm(float duty_percent);

    /**
     * Output a PWM wave on speicfied IO with specified frequency.
     *
     * @param duty_percent - 0.0~100.0, float number
     * @param freq - unit: Hz
     *
     * @return bool
     */
    bool write_pwm_with_freq(float duty_percent, uint32_t freq);

    /**
     * Read back the parameters of PWM.
     *
     * @param duty_percent - 0.0~100.0, float number
     * @param freq - unit: Hz
     *
     * @return bool
     */
    bool read_pwm(float *duty_percent, uint32_t *freq);


private:
    PWM_T *io;
    uint32_t _freq;
    float _percent;
};


#endif