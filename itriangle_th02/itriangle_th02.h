


#ifndef __ITRIANGLE_TH02_H__
#define __ITRIANGLE_TH02_H__

#include "suli2.h"

//GROVE_NAME        "Temperature and humidity sensor I2C"
//SKU               180401043
//IF_TYPE           I2C
//IMAGE_URL         https://code.itriangle.cz/static/pictures/15.png
//DESCRIPTION       "Sensor measuring ambient relative humidity and temperature."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/high-accuracy-temperature-and-humidity
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/teplota-a-vlhkost-s-vysokou-presnosti-143?category=81
//LANG              [{"source": "TH02.Name","en": "Temperature and humidity sensor I2C","cs": "Senzor teploty a vlhkosti vzduchu na I2C"},{"source": "TH02.Description","en": "Sensor measuring ambient relative humidity and temperature.","cs": "Senzor měří teplotu vzduchu a jeho relativní vlhkost. Ke komunikaci je využívána sběrnice I2C."},{"source": "read_temperature","en": "get temperature","cs": "zjisti teplotu"},{"source": "read_humidity","en": "get humidity","cs": "zjisti vlhkost"},{"source": "TH02.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/high-accuracy-temperature-and-humidity", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/teplota-a-vlhkost-s-vysokou-p%C5%99esnost%C3%AD"}]
//ITR_NAME          TH02.Name
//ITR_DESCRIPTION   TH02.Description
//ITR_WIKI			TH02.Wiki



#define TH02_I2C_DEV_ID      0x40<<1
#define REG_STATUS           0x00 
#define REG_DATA_H           0x01
#define REG_DATA_L           0x02
#define REG_CONFIG           0x03
#define REG_ID               0x11

#define STATUS_RDY_MASK      0x01    //poll RDY,0 indicate the conversion is done

#define CMD_MEASURE_HUMI     0x01    //perform a humidity measurement
#define CMD_MEASURE_TEMP     0x11    //perform a temperature measurement

#define TH02_WR_REG_MODE     0xC0
#define TH02_RD_REG_MODE     0x80

                     
class ItriangleTh
{
public:
     ItriangleTh(int pinsda, int pinscl);
    
    
    
     /**  
     *  Gets measured temperature in °C
     *
     *  @param temperature -  °C
     *
     *
     */
         
    bool read_temperature(float *temperature);
    
    
    
  
    
    
    
    
     /**  
     *  Gets measured relative humidity.
     *
     *  @param humidity  -  %
     *
     *
     */
         
    bool read_humidity(float *humidity);
    
    
   
     /**  
     *  Gets ID
     *
     *  @param sensID
     *
     *
     */
         
 //   bool read_ID(uint8_t *sensID);
    
    /**  
     *  Gets ID
     *
     *  @param sensID
     *
     *
     */
         
//    bool read_config(uint8_t *config);
    
  
   

private:
    I2C_T *i2c;
    
    uint8_t cmdbuf[2];
    uint8_t databuf[3];
    uint16_t valuebuf[3];
     
	  bool start_temperature(void);
    bool start_humidity(void); 
    uint8_t state_ready(void);    
    
    uint8_t ItriangleThRead8(uint8_t reg);
    uint16_t ItriangleThRead16(uint8_t reg);
    uint16_t ItriangleThRead16LE(uint8_t reg);
    int16_t ItriangleThReadS16(uint8_t reg);
    int16_t ItriangleThReadS16LE(uint8_t reg);
    uint32_t ItriangleThRead24(uint8_t reg);
    void WriteRegister(uint8_t reg, uint8_t val);
    
    
     

};


#endif
