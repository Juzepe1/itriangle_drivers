
//servo timings http://www.gwsus.com/english/product/servo/servo.htm    SERVO GWS35


#ifndef __ITRIANGLE_CONT_SERVO_H__
#define __ITRIANGLE_CONT_SERVO_H__

#include "suli2.h"

//GROVE_NAME        "Continuous rotation servo"
//SKU               180401031
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/17.png
//DESCRIPTION       "Continuous servo can rotate clockwise or counter-clockwise with possible speed regulation."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/continuous-servo-360-dg
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/kontinualni-servo-360-dg-128?category=82
//LANG              [{"source": "CRS.Name","en": "Continuous rotation servo","cs": "Průběžné servo"},{"source": "CRS.Description","en": "Continuous servo can rotate clockwise or counter-clockwise with possible speed regulation.","cs": "Průběžné servo umožňuje rotaci osy po i proti směru hodinových ručiček s řízením rychlosti."},{"source": "write_clockwise","en": "rotate clockwise","cs": "toč vpravo"},{"source": "write_clockwise_for_seconds","en": "rotate clockwise [s]","cs": "toč vpravo [s]"},{"source": "write_stop","en": "stop rotation","cs": "zastav"},{"source": "write_stop_hold","en": "stop rotation and hold","cs": "zastav a drž"},{"source": "write_change_direction","en": "change direction","cs": "změň směr"},{"source": "write_counter_clockwise","en": "rotate counterclockwise","cs": "toč vlevo"},{"source": "write_counter_clockwise_for_seconds","en": "rotate counterclockwise [s]","cs": "toč vlevo [s]"},{"source": "write_test","en": "servo testing","cs": "testování serva"},{"source": "CRS.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/continuous-servo-360-dg", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/kontinu%C3%A1ln%C3%AD-servo-360-dg"}]
//ITR_NAME          CRS.Name
//ITR_DESCRIPTION   CRS.Description
//ITR_WIKI			CRS.Wiki


class ItriangleContServo
{
public:
    ItriangleContServo(int pin);

    /**
     * Starts to rotate clockwise with desired speed
     *
     * @param speed - speed from 1-10 (slowest to full speed)
     *
     * @return bool
     */
    bool write_clockwise();

    /**
     * Rotates clockwise with desired speed and time in seconds.
     *
     * @param speed - speed from 1-10 (slowest to full speed)
     * @param time - time in seconds
     *
     * @return bool
     */
    bool write_clockwise_for_seconds(int time);
    
     /**
     * Stops the rotation
     *
     * @param no parameter available
     *
     * @return bool
     */
    bool write_stop();
    
    
        
    
    /**
     * Stops the rotation and holds the last position
     *
     * @param no parameter available
     *
     * @return bool
     */
    bool write_stop_hold();
    
    /**
     * Changes to opposite direction at the same speed
     *
     * @param no parameter available
     *
     * @return bool
     */
    bool write_change_direction();
    
    
    
     /**
     * Starts to rotate counter clockwise with desired speed
     *
     * @param speed - speed from 1-10 (slowest to full speed)
     *
     * @return bool
     */
    bool write_counter_clockwise();



    /**
     * Rotates counter clockwise with desired speed and time in seconds.
     *
     * @param speed - speed from 1-10 (slowest to full speed)
     * @param time - time in seconds
     *
     * @return bool
     */
    bool write_counter_clockwise_for_seconds(int time);
    
   /**
     * Testing values in percent to find a still position.
     *
     * @param percent - 0-100
     * 
     * @return bool
     */
       
    bool write_test(float percent);  
 
    
    


    float temp_direction; 
    PWM_T *io;
    TIMER_T *timer;
    
    
    
};

static void itriangle_cont_servo_timer_interrupt_handler(void *para);



#endif
