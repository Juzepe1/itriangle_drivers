
#include "suli2.h"
#include "itriangle_pir_motion.h"



ItrianglePIRMotion::ItrianglePIRMotion(int pin)
{
    this->io = (IO_T *)malloc(sizeof(IO_T));

    suli_pin_init(io, pin, SULI_INPUT);
    time = millis();
    
    suli_pin_attach_interrupt_handler(io, &pir_motion_interrupt_handler, SULI_RISE, this);
}

bool ItrianglePIRMotion::read_approach(uint8_t *approach)
{
    *approach = suli_pin_read(io);
    return true;
}


static void pir_motion_interrupt_handler(void *para)
{
    ItrianglePIRMotion *g = (ItrianglePIRMotion *)para;
    if (millis() - g->time < 10)
    {
        return;
    }
    g->time = millis();
    POST_EVENT_IN_INSTANCE(g, ir_moved, g->io);
}