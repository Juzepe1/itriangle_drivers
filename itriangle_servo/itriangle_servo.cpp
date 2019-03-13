//For servo Tower Pro 9g, frequency of PWM set to 400Hz

#include "suli2.h"
#include "itriangle_servo.h"


ItriangleServo::ItriangleServo(int pin)
{
    this->io = (PWM_T *)malloc(sizeof(PWM_T));
    this->timer = (TIMER_T *)malloc(sizeof(TIMER_T));

    suli_pwm_init(this->io, pin);
    suli_pwm_frequency(this->io, 400);
    suli_pin_write(this->io, SULI_LOW);
    last_degree = 5;
}



bool ItriangleServo::write_angle(int angle)
{
    last_degree = angle;
    angle = constrain(angle, 5, 175);
    float percent = 100 * angle / 180 + 2.5;
    suli_pwm_frequency(this->io, 400);
    suli_pwm_output(this->io, percent);
    return true;
}

bool ItriangleServo::write_angle_for_seconds(int angle, int time)
{
    last_degree = angle;
    angle = constrain(angle, 5, 175);
    float percent = 100 * angle / 180 + 2.5;
    suli_pwm_frequency(this->io, 400);
    suli_pwm_output(this->io, percent);

    suli_timer_install(timer, time * 1000000, itriangle_servo_timer_interrupt_handler, this, false);

    return true;
}

bool ItriangleServo::read_angle(int *angle)
{
    *angle = last_degree;
    return true;
}


static void itriangle_servo_timer_interrupt_handler(void *para)
{
    ItriangleServo *g = (ItriangleServo *)para;
    suli_pwm_output(g->io, 0);
}

