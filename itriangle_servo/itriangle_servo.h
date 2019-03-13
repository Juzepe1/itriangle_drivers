
#ifndef __ITRIANGLE_SERVO_H__
#define __ITRIANGLE_SERVO_H__

#include "suli2.h"

//GROVE_NAME        "Servo"
//SKU               180401015
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/11.png
//DESCRIPTION       "Servo is a DC motor with precise positioning of the shaft. The shaft can be rotated between 5°-175°."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/servo-180-dg
//ADDED_AT          "2018-01-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/servo-180-st-139?category=82
//LANG              [{"source": "Servo.Name","en": "Servo","cs": "Servo"},{"source": "Servo.Description","en": "Servo is a DC motor with precise positioning of the shaft. The shaft can be rotated between 5°-175°.","cs": "Servo je stejnosměrný motorek s možností nastavení hřídele do určitého úhlu. Hřídelka může být nastavena na úhel cca 5° - 175°."},{"source": "write_angle","en": "set angle","cs": "nastav úhel"},{"source": "write_angle_for_seconds","en": "set angle for [s]","cs": "nastav úhel na [s]"},{"source": "read_angle","en": "get angle value","cs": "načti úhel"},{"source": "Servo.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/servo-180-dg", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/servo-180-st"}]
//ITR_NAME          Servo.Name
//ITR_DESCRIPTION   Servo.Description
//ITR_WIKI			Servo.Wiki

class ItriangleServo
{
public:
    ItriangleServo(int pin);

    /**
     * Set desired angle and holds position - forced positioning . <br>
     *
     * @param set_angle - angle in degrees (5°-175°)
     *
     * @return bool
     */
    bool write_angle(int set_angle);

    /**
     * Set desired angle. Hold position for required time in seconds. <br>
     * Mostly stays in the same position, but may lose position - not forced. <br>
     *
     * @param set_angle - angle in degrees (5°-175°)
     * @param set_time - time in seconds
     *
     * @return bool
     */
    bool write_angle_for_seconds(int set_angle, int set_time);

    /**
     * Read actual rotation angle.
     *
     * @param get_angle - angle in degrees (5°-175°)
     *
     * @return bool
     */
    bool read_angle(int *get_angle);


    PWM_T *io;
    TIMER_T *timer;
    int last_degree;

};

static void itriangle_servo_timer_interrupt_handler(void *para);



#endif
