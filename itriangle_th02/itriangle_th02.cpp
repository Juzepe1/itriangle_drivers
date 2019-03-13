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


#include "suli2.h"
#include "itriangle_th02.h"
#include "TH02_dev.h"


ItriangleTh::ItriangleTh(int pinsda, int pinscl)
{
    this->i2c = (I2C_T *)malloc(sizeof(I2C_T));
    suli_i2c_init(i2c, pinsda, pinscl);
    TH02.begin();
    
}                                

 
bool ItriangleTh::read_temperature(float *temperature)
{
    
    /*int16_t value_temp = 0;
    uint8_t time_out =0;
    
    start_temperature();
    
    
    while (state_ready() && time_out <= 100){
        ++time_out;
        suli_delay_ms(1);
        }       //cekame na dokonceni prevodu cca 50ms, 0 znamena hotovo       
     
      suli_delay_ms(1000);
     
      //value_temp = ItriangleThReadS16(REG_DATA_H);
      if (30 < time_out <=100 ) {
        suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, REG_DATA_H, databuf, 1);
        value_temp = databuf[0];
        value_temp <<= 8;
        suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, REG_DATA_L, databuf, 1);
        value_temp |= databuf[0];
      
    
        value_temp = (value_temp >> 2) ; // rozliseni teploty jen 14 bitu, tak posun bitu smerem dolu
        *temperature = (float)(value_temp/32.0)-50.0;
     } else { 
      *temperature = time_out;
     } */
     //TH02.begin();
     *temperature = TH02.ReadTemperature();
     Wire.endTransmission();
    
     
     return true;
}


bool ItriangleTh::read_humidity(float *humidity)
{
    
    /*uint16_t value_humi = 0;
    uint8_t time_out = 0;
    start_humidity();
       
    while (state_ready() && time_out <= 100){
        ++time_out;
        suli_delay_ms(1);
        }       //cekame na dokonceni prevodu cca 50ms, 0 znamena hotovo 
        suli_delay_ms(100);
    
    //value_humi = ItriangleThRead16(REG_DATA_H);
    value_humi = ItriangleThRead16(REG_DATA_H); 
    
    
   
     value_humi = (value_humi >> 4); // rozliseni humidity jen 12 bitu, tak posun bitu smerem dolu
     *humidity = (value_humi)/16.0 - 24.0;
     //*humidity = value_humi;
     //WriteRegister(REG_CONFIG,0);
      */
       
       //TH02.begin();
      *humidity = TH02.ReadHumidity();
      Wire.endTransmission();
      
     return true;
}








uint8_t ItriangleTh::state_ready(void)    // kontrola, jestli jsou data k dispozici
{
    uint8_t pripraveno =  ItriangleThRead8(REG_STATUS);
    pripraveno = REG_STATUS & pripraveno;   // vymaskovat posledni bit
       
    return(pripraveno);              // kdyz je pripraveno, tak dava 0, jinak drzi v 1
    
    
}

/*
bool ItriangleTh::read_ID(uint8_t *th02id)    // precte id sensoru
{

    
    *th02id =  ItriangleThRead8(REG_ID);
     Wire.endTransmission();
       
    return true;
}


bool ItriangleTh::read_config(uint8_t *config)    // precte konfiguracni refgistr
{

    
    *config =  ItriangleThRead8(REG_CONFIG);
    Wire.endTransmission();
       
    return true;
}

*/


bool ItriangleTh::start_temperature(void)
{
    
      
    WriteRegister(REG_CONFIG,CMD_MEASURE_TEMP); //zapise do konfigu senzoru mereni teploty

    return true; 
}

bool ItriangleTh::start_humidity(void)
{
    WriteRegister(REG_CONFIG,CMD_MEASURE_HUMI); //zapise do konfigu senzoru mereni humidity

    return true; 
}



uint8_t ItriangleTh::ItriangleThRead8(uint8_t reg)
{
    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 1);
    return databuf[0];
}

uint16_t ItriangleTh::ItriangleThRead16(uint8_t reg)
{
    uint16_t data=0;
    
    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 3);
    data = (uint16_t)databuf[1];
    data <<= 8;
    data |= (uint16_t)databuf[2];
    return (data);
}

uint16_t ItriangleTh::ItriangleThRead16LE(uint8_t reg)
{
    
    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 2);
    return (databuf[1] << 8) | databuf[0];
}

int16_t ItriangleTh::ItriangleThReadS16(uint8_t reg)
{
    return (int16_t)ItriangleThRead16(reg);
}

int16_t ItriangleTh::ItriangleThReadS16LE(uint8_t reg)
{
    return (int16_t)ItriangleThRead16LE(reg);
}

uint32_t ItriangleTh::ItriangleThRead24(uint8_t reg)
{
    uint32_t data;

    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 3);

    data = databuf[0];
    data <<= 8;
    data |= databuf[1];
    data <<= 8;
    data |= databuf[2];

    return data;
}

void ItriangleTh::WriteRegister(uint8_t reg, uint8_t val)
{
    cmdbuf[0] = reg;
    cmdbuf[1] = val;
    suli_i2c_write(i2c, TH02_I2C_DEV_ID, cmdbuf, 2);
}

