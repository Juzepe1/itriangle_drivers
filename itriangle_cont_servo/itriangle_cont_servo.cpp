//For servo Tower Pro 9g, frequency of PWM set to 50Hz

#include "suli2.h"
#include "itriangle_cont_servo.h"


ItriangleContServo::ItriangleContServo(int pin)
{
    this->io = (PWM_T *)malloc(sizeof(PWM_T));
    this->timer = (TIMER_T *)malloc(sizeof(TIMER_T));

    suli_pwm_init(this->io, pin);
    suli_pwm_frequency(this->io, 50);
    suli_pin_write(this->io, SULI_LOW);
    
}



bool ItriangleContServo::write_clockwise()           
{
    
    suli_pwm_frequency(this->io, 50);
    temp_direction = 3;
    suli_pwm_output(this->io,temp_direction);
    return true;
}

bool ItriangleContServo::write_clockwise_for_seconds(int time)
{
    
    suli_pwm_frequency(this->io, 50);
    temp_direction =  3;
    suli_pwm_output(this->io, temp_direction);

    suli_timer_install(timer, time * 1000000, itriangle_cont_servo_timer_interrupt_handler, this, false);

    return true;
}


bool ItriangleContServo::write_counter_clockwise()       
{
    
    suli_pwm_frequency(this->io, 50);
    temp_direction = 1;
    suli_pwm_output(this->io, temp_direction);
    return true;
}

bool ItriangleContServo::write_counter_clockwise_for_seconds(int time)
{
    
    suli_pwm_frequency(this->io, 50);
    temp_direction = 1;
    suli_pwm_output(this->io, temp_direction); 

    suli_timer_install(timer, time * 1000000, itriangle_cont_servo_timer_interrupt_handler, this, false);

    return true;
}

bool ItriangleContServo::write_change_direction()
{
    
    
    suli_pwm_frequency(this->io, 50);
    if (temp_direction == 1){
       temp_direction = 3;    //hold position minus last progressive speed
    
    }else if (temp_direction == 3){
         temp_direction = 1;   //hold position plus last progressive speed
    }else {temp_direction = 50;}                        // else standing
    
    suli_pwm_output(this->io, temp_direction);      //progressive speed setting, nonlinear reaction from servo
    return true;
}




 bool ItriangleContServo::write_stop_hold()      //60 percent makes servo stop
{
    
    
    float percent = 50;
    suli_pwm_frequency(this->io, 50);
    suli_pwm_output(this->io, percent);         //holding position
    

    return true;
}


bool ItriangleContServo::write_stop()      //ř0 percent makes servo stop
{
    
    
    float percent = 50;
    suli_pwm_frequency(this->io, 50);
    suli_pwm_output(this->io, percent);
    suli_pwm_output(this->io,0);            //stop PWM output, servo is not holding position

    return true;
}







bool ItriangleContServo::write_test(float percent)
{
    suli_pwm_frequency(this->io, 50);
    suli_pwm_output(this->io, percent);
    return true;
}




static void itriangle_cont_servo_timer_interrupt_handler(void *para)
{
    ItriangleContServo *g = (ItriangleContServo *)para;
    suli_pwm_output(g->io, 0);
}

