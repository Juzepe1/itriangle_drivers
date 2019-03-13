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


#ifndef __ITRIANGLE_TONEGEN_H__
#define __ITRIANGLE_TONEGEN_H__

#include "suli2.h"

//GROVE_NAME        "Tone generator"
//SKU               180401005
//IF_TYPE           GPIO
//IMAGE_URL         https://code.itriangle.cz/static/pictures/12.png
//DESCRIPTION       "Tone generator is based on buzzer. It can produce multiple tones. Set different BPM (default 80) and choose tone length (1-5) for creating your melody. You can use speaker from headphones for better results."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/tone-generator
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/generator-tonu-144?category=82
//LANG              [{"source": "Tone.Name","en": "Tone generator","cs": "Generátor tónů"},{"source": "Tone.Description","en": "Tone generator is based on buzzer. It can produce multiple tones. Set different BPM (default 80) and choose tone length (1-5) for creating your melody.","cs": "Generátor tónů využívá bzučák pro vytváření různých tónů. Pro vytvoření melodie lze nastavit hodnotu BPM (beats per minute - výchozí je 80) a zvolit se délku noty (čísla 1-5  odpovídají postupně 1/1, 1/2, 1/4, 1/8 a 1/16)."},{"source": "write_sound_ms","en": "sound freq/ms","cs": "frekvence [ms]"},{"source": "write_bpm","en": "set BPM","cs": "nastav tempo"},{"source": "write_demo","en": "demo","cs": "demo"},{"source": "write_c6","en": "c6","cs": "c6"},{"source": "write_d6","en": "d6","cs": "d6"},{"source": "write_e6","en": "e6","cs": "e6"},{"source": "write_f6","en": "f6","cs": "f6"},{"source": "write_g6","en": "g6","cs": "g6"},{"source": "write_a6","en": "a6","cs": "a6"},{"source": "write_b6","en": "b6","cs": "b6"},{"source": "write_c7","en": "c7","cs": "c7"},{"source": "write_d7","en": "d7","cs": "d7"},{"source": "write_e7","en": "e7","cs": "e7"},{"source": "write_f7","en": "f7","cs": "f7"},{"source": "write_g7","en": "g7","cs": "g7"},{"source": "write_a7","en": "a7","cs": "a7"},{"source": "write_b7","en": "b7","cs": "b7"},{"source": "write_silence_ms","en": "silence","cs": "pauza"},{"source": "write_sound_start","en": "sound freq start","cs": "frekvence hraj"},{"source": "write_sound_stop","en": "sound freq stop","cs": "frekvence stop"},{"source": "Tone.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/tone-generator", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/gener%C3%A1tor-t%C3%B3n%C5%AF"}]
//ITR_NAME          Tone.Name
//ITR_DESCRIPTION   Tone.Description
//ITR_WIKI			Tone.Wiki

class ItriangleToneGen
{
public:
    ItriangleToneGen(int pin);

    /**
     *
     *
     * @param Hertz - Hz
     * @param milliseconds - a duration of x microseconds during which the tone generator produces sound
     *
     * @return bool
     */
    bool write_sound_ms(int freq, int duration_ms);

     /**
     * Sets new tempo. The default tempo is 80bmp.
     *
     * @param BPM - Tempo beats per minute
     *
     * @return bool
     */    
    bool write_bpm(int bpm);

    
    
    
    /**
     * Play all tones
     *
     * @param duration(1-5) -  maps to (1/1 - 1/16 notes) 
     *
     * @return bool
     */    
     bool write_demo(int duration);


    /**
     * Plays c6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_c6(int duration);
    
     /**
     * Plays d6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_d6(int duration);
    
     /**
     * Plays e6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_e6(int duration);
    
     /**
     * Plays f6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_f6(int duration);
    
     /**
     * Plays g6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_g6(int duration);
    
     /**
     * Plays a6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_a6(int duration);
    
     /**
     * Plays b6 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_b6(int duration);
     
     /**
     * Plays c7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_c7(int duration);
    
     /**
     * Plays d7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_d7(int duration);
                      
    /**
     * Plays e7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_e7(int duration);        
    
     /**
     * Plays f7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_f7(int duration);
    
     /**
     * Plays g7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_g7(int duration);
    
    /**
     * Plays a7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_a7(int duration);
    
    /**
     * Plays b7 note 
     * @param duration(1-5) - maps to (1/1 - 1/16 notes) 
     * @return bool
     */
    bool write_b7(int duration);
    
      

     /**
     * Plays silence on default tempo of 80 bmp with desired note duration (1, 1/2 ... 1/16).
     * 
     * @param duration(1-5) - means (1/1, 1/2, 1/4, 1/8, 1/16)
     *
     * @return bool
     */
    bool write_silence_ms(int duration);



    /**
     * Start to produce sound with a specified frequency, and wont stop until you send the sound_stop command.
     *
     * @param Hertz - Hz
     *
     * @return bool
     */
    bool write_sound_start(int freq);
    
    
    /**
     * Stops producing the sound.
     *
     * @param none - without parameters
     *
     * @return bool
     */
    bool write_sound_stop();

    


private:
    PWM_T *io;
    uint8_t tempo=80; //default tempo          
    uint16_t nduration[5]={0,0,0,0,0};  //notes duration 
    uint16_t sduration[5]={0,0,0,0,0};  //silences duration
    uint16_t _freqs[14]={1058,1183,1325,1400,1600,1760,2000,2120,2360,2600,2800,3130,3520,3750};
    void setup_times(int _tempo);
    void _silence(int silence);
    void _sound(int freq, int duration);
};

    
#endif
