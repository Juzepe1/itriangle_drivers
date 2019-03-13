
#ifndef __ITRIANGLE_LEDSTRIPE_H__
#define __ITRIANGLE_LEDSTRIPE_H__

#include "suli2.h"

//GROVE_NAME        "Led Stripe"
//SKU               180401026
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/22.png
//DESCRIPTION       "Color of every RGB LED can be controlled individually."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/led-stripe
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/led-pasek-132?category=82
//LANG              [{"source": "Stripe.Name","en": "Led Stripe","cs": "LED pásek"},{"source": "Stripe.Description","en": "Color of every RGB LED can be controlled individually.","cs": "LED pásek s možností nastavení barvy jednotlivých LED."},{"source": "write_clear","en": "set hex color","cs": "nastav hex barvy"},{"source": "write_segment","en": "set hex segment","cs": "nastav hex segment"},{"source": "write_blue","en": "blue position","cs": "modrá pozice"},{"source": "write_red","en": "red position","cs": "červená pozice"},{"source": "write_green","en": "green position","cs": "zelená pozice"},{"source": "write_white","en": "white position","cs": "bílá pozice"},{"source": "write_yellow","en": "yellow position","cs": "žlutá pozice"},{"source": "write_orange","en": "orange position","cs": "oranžová pozice"},{"source": "write_pink","en": "pink position","cs": "růžová pozice"},{"source": "write_purple","en": "purple position","cs": "fialová pozice"},{"source": "write_none","en": "clear position","cs": "vypnout pozice"},{"source": "write_none_all","en": "clear all","cs": "vypnout všechny"},{"source": "write_start_rainbow_flow","en": "start rainbow","cs": "zapni duhu"},{"source": "write_stop_rainbow_flow","en": "stop rainbow","cs": "vypni duhu"},{"source": "Stripe.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/led-stripe", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/led-p%C3%A1sek"}]
//ITR_NAME          Stripe.Name
//ITR_DESCRIPTION   Stripe.Description
//ITR_WIKI			Stripe.Wiki


#define MAX_LED_CNT             60

struct rgb_s
{
    uint8_t g,r,b;
}__attribute__((__packed__));

union rgb_buffer_u
{
    uint8_t buff[MAX_LED_CNT*3];
    struct rgb_s pixels[MAX_LED_CNT];
};

class ItriangleLedStripe
{
public:
    ItriangleLedStripe(int pin);
    char *get_last_error() { return error_desc; };

    /**
     * Set or reset or clear the led strip with a specified color.
     *
     * @param total_led_cnt - the total count of this strip, max: 60(too many leds will cause the power unstable)
     * @param rgb_hex_string - a rgb value in hex format, e.g. AA55CC (without # or 0x)
     *
     * @return bool
     */
    bool write_clear(uint8_t total_led_cnt, char *rgb_hex_string);

    /**
     * Change the color of some piece of segment of the led strip.
     * We need to specify a list of rgb hex value concatinated into a string.
     * The segment will be defined with a start index and the length.
     * The length equals rgb_hex_string's length / 6.
     *
     * @param start - the start index of the segment(included)
     * @param rgb_hex_string - a list of rgb hex value, e.g. FFFFFFBBBBBBCCCCCC000000111111, max length: 240 or 40 rgb hex
     *
     * @return bool
     */
    bool write_segment(uint8_t start, char *rgb_hex_string);
    
    
    /**
     * Makes specified LED shine with a blue color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_blue(uint8_t position);
    
    /**
     * Makes specified LED shine with a red color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_red(uint8_t position);
    
    
    /**
     * Makes specified LED shine with a green color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_green(uint8_t position);
    
    
    /**
     * Makes specified LED shine with a white color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_white(uint8_t position);
    
     /**
     * Makes specified LED shine with an yellow color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_yellow(uint8_t position);
    
     /**
     * Makes specified LED shine with an orange color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_orange(uint8_t position);
    
     /**
     * Makes specified LED shine with a pink color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_pink(uint8_t position);
    
     /**
     * Makes specified LED shine with a purple color.
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_purple(uint8_t position);
    
        
    
    /**
     * Clears specified LED. 
     *
     * @param position - position of LED on the stripe
     *
     * @return bool
     */
    bool write_none(uint8_t position);
    
    /**
     * Clears whole LED stripe. 
     *
     * 
     *
     * @return bool
     */
    bool write_none_all();
    
    
    
    
    
    

    /**
     * Make the strip blink in a rainbow flow
     *
     * @param length - the length of the flow, the flow will always begin with index 0.
     * @param brightness - 0~100
     * @param speed - 1~10, 10 is the fastest.
     *
     * @return bool
     */
    bool write_start_rainbow_flow(uint8_t length, uint8_t brightness, uint8_t speed);

    /**
     * Stop the rainbow flow.
     *
     * @return bool
     */
    bool write_stop_rainbow_flow();

private:
    IO_T *io;
    TIMER_T *timer;

    union rgb_buffer_u rgb_buffer;
    uint8_t _color_towards[MAX_LED_CNT];
    bool _extract_rgb_from_string(int start, char *str);
    char *error_desc;
    uint8_t led_cnt;
    uint8_t _rainbow_flow_brightness;

public:
    void update_color();
};

static void timer_handler(void *para);


#endif