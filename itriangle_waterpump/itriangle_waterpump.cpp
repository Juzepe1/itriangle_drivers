#include "suli2.h"
#include "itriangle_waterpump.h"

ItriangleWaterPump::ItriangleWaterPump(int pin)
{
    this->io = (IO_T *)malloc(sizeof(IO_T));
    this->timer = (TIMER_T *)malloc(sizeof(TIMER_T));
    
    suli_pin_init(io, pin, SULI_OUTPUT);
}

bool ItriangleWaterPump::write_onoff(int onoff)
{
    if (onoff>1 || onoff <0){return false;}
    onoff = constrain(onoff,0,1);
    suli_pin_write(io, onoff);
    return true;
}

bool ItriangleWaterPump::read_onoff_status(int *onoff)
{
    *onoff = suli_pin_read(io);
    return true;
}



bool ItriangleWaterPump::write_ontime(int time)
{
    time = constrain(time,1,60);
    suli_pin_write(io, 1); 
    suli_timer_install(timer, time * 1000000, itriangle_waterpump_timer_high_pulse_interrupt_handler, this, false);
    return true;
}

bool ItriangleWaterPump::write_inverted()
{
    suli_pin_write(io, !(suli_pin_read(io)));
    return true;
}


static void itriangle_waterpump_timer_high_pulse_interrupt_handler(void *para)
{
    ItriangleWaterPump *g = (ItriangleWaterPump *)para;
    suli_pin_write(g->io, 0);
}
