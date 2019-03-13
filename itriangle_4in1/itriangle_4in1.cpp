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
#include "itriangle_4in1.h"



Itriangle4in1::Itriangle4in1(int pinsda, int pinscl)
{
    this->i2c = (I2C_T *)malloc(sizeof(I2C_T));
    suli_i2c_init(i2c, pinsda, pinscl); // Inicializace Wire
    initMPU9250();  //inicializace vsech sensoru - dostupnost I2C slave
    BMP280Init();  // inicializace tlaku, teploty
    MPU9250getAres();
  	MPU9250getGres();
	  MPU9250getMres();
    initAK8963(magCalibration);  
    
    
    
}                                

 bool Itriangle4in1::whoami(uint8_t *whoami)
{
    
    
     *whoami = ReadByte(MPU9250_ADDRESS, MPU9250_WHO_AM_I);
     Wire.endTransmission();
    
     
     return true;
}

bool Itriangle4in1::read_calibration(bool *finished)
{
 float _MPU9250magBias[3] = { 0, 0, 0 };
 
 _MPU9250magBias[0] = MPU9250magBias[0]; 
 
 magcalMPU9250(MPU9250magBias); 
 
 if ((MPU9250magBias[0] != 0) && (MPU9250magBias[0] != _MPU9250magBias[0])){
 
    *finished = true;
 }else{
    *finished = false;
 
 } 
 
 return true;       
}







bool Itriangle4in1::read_heading(float *heading)
{
  
  for (int i=0;i<20;i++){
  while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
	  
    
    
    MPU9250readAccelData(accelCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		ax = (float)accelCount[0] * MPU9250aRes - MPU9250accelBias[0];  // get actual g value, this depends on scale being set
  	ay = (float)accelCount[1] * MPU9250aRes - MPU9250accelBias[1];
		az = (float)accelCount[2] * MPU9250aRes - MPU9250accelBias[2];	
		
    MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values
		gx = (float)gyroCount[0] * MPU9250gRes;  // get actual gyro value, this depends on scale being set
  	gy = (float)gyroCount[1] * MPU9250gRes;
		gz = (float)gyroCount[2] * MPU9250gRes;
    
    MPU9250readMagData(magCount);  // Read the x/y/z adc values

					 // Calculate the magnetometer values in milliGauss
					// Include factory calibration per data sheet and user environmental corrections
    mx = (float)magCount[0] * MPU9250mRes*magCalibration[0] - MPU9250magBias[0];  // get actual magnetometer value, this depends on scale being set
    my = (float)magCount[1] * MPU9250mRes*magCalibration[1] - MPU9250magBias[1];
    mz = (float)magCount[2] * MPU9250mRes*magCalibration[2] - MPU9250magBias[2];

    Now = micros();
  	deltat = ((Now - lastUpdate) / 1000000.0f); // set integration time by time elapsed since last filter update
  	lastUpdate = Now;

    MadgwickQuaternionUpdate(-ax, ay, az, gx*pi / 180.0f, -gy*pi / 180.0f, -gz*pi / 180.0f, my, -mx, mz);
    //MahonyQuaternionUpdate(-ax, ay, az, gx*pi/180.0f, -gy*pi/180.0f, -gz*pi/180.0f,  my,  -mx, mz);
  } 
    
    a12 = 2.0f * (q[1] * q[2] + q[0] * q[3]);
    a22 = q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3];
  	a31 = 2.0f * (q[0] * q[1] + q[2] * q[3]);
		a32 = 2.0f * (q[1] * q[3] - q[0] * q[2]);
		a33 = q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3];
  	pitch = -asinf(a32);
  	roll = atan2f(a31, a33);
  	yaw = atan2f(a12, a22);
  	pitch *= 180.0f / PI;
  	yaw *= 180.0f / PI;
  	yaw += 6.8f; // Declination at Danville, California is 13 degrees 48 minutes and 47 seconds on 2014-04-04
		if (yaw < 0) yaw += 360.0f; // Ensure yaw stays between 0 and 360
  	roll *= 180.0f / PI;
		lin_ax = ax + a31;
		lin_ay = ay + a32;
  	lin_az = az - a33;
    
    
    /*
    yaw   = atan2f(2.0f * (q[1] * q[2] + q[0] * q[3]), q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3]);   
    pitch = -asinf(2.0f * (q[1] * q[3] - q[0] * q[2]));
    roll  = atan2f(2.0f * (q[0] * q[1] + q[2] * q[3]), q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3]);
    pitch *= 180.0f / PI;
    yaw   *= 180.0f / PI; 
    yaw   += 6.8f; // Declination at Danville, California is 13 degrees 48 minutes and 47 seconds on 2014-04-04
    if(yaw < 0) yaw   += 360.0f; // Ensure yaw stays between 0 and 360
    roll  *= 180.0f / PI;
    */   
    
    
    *heading = yaw;
    
     Wire.endTransmission();
    return true;
    
}









bool Itriangle4in1::read_temperature2(float *temp2)
{

tempCount = MPU9250readTempData();  // Read the gyro adc values
*temp2 = ((float)tempCount) / 333.87 + 21.0;

return true;
}



bool Itriangle4in1::whoami_mag(uint8_t *whoami)
{
      
     *whoami = ReadByte(AK8963_ADDRESS, WHO_AM_I_AK8963);
     Wire.endTransmission();
    
     
     return true;
}


bool Itriangle4in1::whoami_bmp(uint8_t *whoami)
{
    
     *whoami = ReadByte(BMP280_ADDRESS, BMP280_ID);
     Wire.endTransmission();
    
     
     return true;
}

                  

 
 
bool Itriangle4in1::read_accelx(float *accelx)
{
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
		
    MPU9250readAccelData(accelCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		ax = (float)accelCount[0] * MPU9250aRes - MPU9250accelBias[0];  // get actual g value, this depends on scale being set
  	ay = (float)accelCount[1] * MPU9250aRes - MPU9250accelBias[1];
		az = (float)accelCount[2] * MPU9250aRes - MPU9250accelBias[2];
    
     *accelx = ax;
     Wire.endTransmission();
    
     
     return true;
}


bool Itriangle4in1::read_accely(float *accely)
{
    
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
    
    MPU9250readAccelData(accelCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		ax = (float)accelCount[0] * MPU9250aRes - MPU9250accelBias[0];  // get actual g value, this depends on scale being set
  	ay = (float)accelCount[1] * MPU9250aRes - MPU9250accelBias[1];
		az = (float)accelCount[2] * MPU9250aRes - MPU9250accelBias[2];
    
     *accely =ay;
      
      Wire.endTransmission();
      
     return true;
}

bool Itriangle4in1::read_accelz(float *accelz)
{
    
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
     
     
     
    MPU9250readAccelData(accelCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		ax = (float)accelCount[0] * MPU9250aRes - MPU9250accelBias[0];  // get actual g value, this depends on scale being set
  	ay = (float)accelCount[1] * MPU9250aRes - MPU9250accelBias[1];
		az = (float)accelCount[2] * MPU9250aRes - MPU9250accelBias[2];
    
     *accelz =az;
      Wire.endTransmission();
      
     return true;
}




bool Itriangle4in1::read_gyrox(float *gyrox)
{
    
   while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
		
    MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values
		gx = (float)gyroCount[0] * MPU9250gRes;  // get actual gyro value, this depends on scale being set
  	gy = (float)gyroCount[1] * MPU9250gRes;
		gz = (float)gyroCount[2] * MPU9250gRes;
    
    *gyrox = gx;
    Wire.endTransmission();
      
     return true;
}


bool Itriangle4in1::read_gyroy(float *gyroy)
{
    
     while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
		
    MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values
		gx = (float)gyroCount[0] * MPU9250gRes;  // get actual gyro value, this depends on scale being set
  	gy = (float)gyroCount[1] * MPU9250gRes;
		gz = (float)gyroCount[2] * MPU9250gRes;
    
    *gyroy = gy;
    Wire.endTransmission();
      
     return true;
}


bool Itriangle4in1::read_gyroz(float *gyroz)
{
    
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
		
    MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values

									   // Now we'll calculate the accleration value into actual g's
		MPU9250readGyroData(gyroCount);  // Read the x/y/z adc values
		gx = (float)gyroCount[0] * MPU9250gRes;  // get actual gyro value, this depends on scale being set
  	gy = (float)gyroCount[1] * MPU9250gRes;
		gz = (float)gyroCount[2] * MPU9250gRes;
    
    *gyroz = gz;
    Wire.endTransmission();
      
     return true;
}

bool Itriangle4in1::read_magx(float *magx)
{
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
		
    MPU9250readMagData(magCount);  // Read the x/y/z adc values

					 // Calculate the magnetometer values in milliGauss
					// Include factory calibration per data sheet and user environmental corrections
    mx = (float)magCount[0] * MPU9250mRes*magCalibration[0] - MPU9250magBias[0];  // get actual magnetometer value, this depends on scale being set
    my = (float)magCount[1] * MPU9250mRes*magCalibration[1] - MPU9250magBias[1];
    mz = (float)magCount[2] * MPU9250mRes*magCalibration[2] - MPU9250magBias[2];
     
    *magx = mx;
    Wire.endTransmission();
    
     
     return true;
}


bool Itriangle4in1::read_magy(float *magy)
{
    
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
    
    MPU9250readMagData(magCount);  // Read the x/y/z adc values

					 // Calculate the magnetometer values in milliGauss
					// Include factory calibration per data sheet and user environmental corrections
    mx = (float)magCount[0] * MPU9250mRes*magCalibration[0] - MPU9250magBias[0];  // get actual magnetometer value, this depends on scale being set
    my = (float)magCount[1] * MPU9250mRes*magCalibration[1] - MPU9250magBias[1];
    mz = (float)magCount[2] * MPU9250mRes*magCalibration[2] - MPU9250magBias[2];
     
    *magy = my;
      
    Wire.endTransmission();
      
     return true;
}

bool Itriangle4in1::read_magz(float *magz)
{
    
    while (!(ReadByte(MPU9250_ADDRESS, MPU9250_INT_STATUS) & 0x01)) {  // check if data ready interrupt
		 
     suli_delay_ms(1);
     }
     
   MPU9250readMagData(magCount);  // Read the x/y/z adc values

					 // Calculate the magnetometer values in milliGauss
					// Include factory calibration per data sheet and user environmental corrections
    mx = (float)magCount[0] * MPU9250mRes*magCalibration[0] - MPU9250magBias[0];  // get actual magnetometer value, this depends on scale being set
    my = (float)magCount[1] * MPU9250mRes*magCalibration[1] - MPU9250magBias[1];
    mz = (float)magCount[2] * MPU9250mRes*magCalibration[2] - MPU9250magBias[2];
     
    *magz = mz;
    Wire.endTransmission();
      
     return true;
}






int16_t Itriangle4in1::MPU9250readTempData()
{
	uint8_t rawData[2];  
	ReadBytes(MPU9250_ADDRESS, MPU9250_TEMP_OUT_H, 2, &rawData[0]);  // Read the two raw data registers sequentially into data array 
	return ((int16_t)rawData[0] << 8) | rawData[1];  // Turn the MSB and LSB into a 16-bit value
} 




bool Itriangle4in1::read_pressure(float *press)
{
      rawTemp = readBMP280Temperature();
      temper = (float)bmp280_compensate_T(rawTemp) / 100.0f;
      
      rawPress = readBMP280Pressure();
      BMP280Pressure = (float)bmp280_compensate_P(rawPress) / 25600.; // Pressure in mbar - the same as hPa
     *press = BMP280Pressure;
      Wire.endTransmission();
      
     return true;
}


bool Itriangle4in1::read_altitude(float *altit)
{
      readBMP280Temperature();
      bmp280_compensate_T(rawTemp);
      rawPress = readBMP280Pressure();
      BMP280Pressure = (float)bmp280_compensate_P(rawPress) / 25600.0f; // Pressure in mbar - the same as hPa
    	*altit = 145366.45f/2.0f*(1.0f - pow((BMP280Pressure / 1013.25f), 0.190284f));
      Wire.endTransmission();
      
     return true;
}
    
    bool Itriangle4in1::read_temperature(float *temper)
{
   
   rawTemp = readBMP280Temperature();
   *temper = (float)bmp280_compensate_T(rawTemp) / 100.0f;
   return true;

}





void Itriangle4in1::BMP280Init()
{
	// Configure the BMP280
	// Set T and P oversampling rates and sensor mode
	writeByte(BMP280_ADDRESS, BMP280_CTRL_MEAS, BMP280Tosr << 5 | BMP280Posr << 2 | BMP280Mode);
  //writeByte(BMP280_ADDRESS, BMP280_CTRL_MEAS, 0x3F);
	// Set standby time interval in normal mode and bandwidth
	writeByte(BMP280_ADDRESS, BMP280_CONFIG, BMP280SBy << 5 | BMP280IIRFilter << 2);
  //writeByte(BMP280_ADDRESS, BMP280_CONFIG, 0x60);
	// Read and store calibration data
	uint8_t calib[24];
	ReadBytes(BMP280_ADDRESS, BMP280_CALIB00, 24, &calib[0]);
	dig_T1 = (uint16_t)(((uint16_t)calib[1] << 8) | calib[0]);
	dig_T2 = (int16_t)(((int16_t)calib[3] << 8) | calib[2]);
	dig_T3 = (int16_t)(((int16_t)calib[5] << 8) | calib[4]);
	dig_P1 = (uint16_t)(((uint16_t)calib[7] << 8) | calib[6]);
	dig_P2 = (int16_t)(((int16_t)calib[9] << 8) | calib[8]);
	dig_P3 = (int16_t)(((int16_t)calib[11] << 8) | calib[10]);
	dig_P4 = (int16_t)(((int16_t)calib[13] << 8) | calib[12]);
	dig_P5 = (int16_t)(((int16_t)calib[15] << 8) | calib[14]);
	dig_P6 = (int16_t)(((int16_t)calib[17] << 8) | calib[16]);
	dig_P7 = (int16_t)(((int16_t)calib[19] << 8) | calib[18]);
	dig_P8 = (int16_t)(((int16_t)calib[21] << 8) | calib[20]);
	dig_P9 = (int16_t)(((int16_t)calib[23] << 8) | calib[22]);
}


int32_t Itriangle4in1::readBMP280Temperature()
{
	uint8_t rawData[3];  // 20-bit pressure register data stored here
	ReadBytes(BMP280_ADDRESS, BMP280_TEMP_MSB, 3, &rawData[0]);
	return (int32_t)(((int32_t)rawData[0] << 16 | (int32_t)rawData[1] << 8 | rawData[2]) >> 4);
}

int32_t Itriangle4in1::bmp280_compensate_T(int32_t adc_T)
{
	int32_t var1, var2, T;
	var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
	var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
	t_fine = var1 + var2;
	T = (t_fine * 5 + 128) >> 8;
	return T;
}

int32_t Itriangle4in1::readBMP280Pressure()
{
	uint8_t rawData[3];  // 20-bit pressure register data stored here
	ReadBytes(BMP280_ADDRESS, BMP280_PRESS_MSB, 3, &rawData[0]);
	return (int32_t)(((int32_t)rawData[0] << 16 | (int32_t)rawData[1] << 8 | rawData[2]) >> 4);
}

uint32_t Itriangle4in1::bmp280_compensate_P(int32_t adc_P)
{
	long long var1, var2, p;
	var1 = ((long long)t_fine) - 128000;
	var2 = var1 * var1 * (long long)dig_P6;
	var2 = var2 + ((var1*(long long)dig_P5) << 17);
	var2 = var2 + (((long long)dig_P4) << 35);
	var1 = ((var1 * var1 * (long long)dig_P3) >> 8) + ((var1 * (long long)dig_P2) << 12);
	var1 = (((((long long)1) << 47) + var1))*((long long)dig_P1) >> 33;
	if (var1 == 0)
	{
		return 0;
		// avoid exception caused by division by zero
	}
	p = 1048576 - adc_P;
	p = (((p << 31) - var2) * 3125) / var1;
	var1 = (((long long)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
	var2 = (((long long)dig_P8) * p) >> 19;
	p = ((p + var1 + var2) >> 8) + (((long long)dig_P7) << 4);
	return (uint32_t)p;
}


uint8_t Itriangle4in1::bmp280Read8(uint8_t reg)
{
    suli_i2c_read_reg(i2c, BMP280_ADDRESS, reg, databuf, 1);
    return databuf[0];

}

uint16_t Itriangle4in1::bmp280Read16(uint8_t reg)
{
    suli_i2c_read_reg(i2c, BMP280_ADDRESS, reg, databuf, 2);
    return (databuf[0] << 8) | databuf[1];

}

uint16_t Itriangle4in1::bmp280Read16LE(uint8_t reg)
{
    suli_i2c_read_reg(i2c, BMP280_ADDRESS, reg, databuf, 2);
    return (databuf[1] << 8) | databuf[0];
}

int16_t Itriangle4in1::bmp280ReadS16(uint8_t reg)
{
    suli_i2c_read_reg(i2c, BMP280_ADDRESS, reg, databuf, 2);
    return (int16_t)((databuf[0] << 8) | databuf[1]);
}

int16_t Itriangle4in1::bmp280ReadS16LE(uint8_t reg)
{
    suli_i2c_read_reg(i2c, BMP280_ADDRESS, reg, databuf, 2);
    return (int16_t)((databuf[1] << 8) | databuf[0]);
}

uint32_t Itriangle4in1::bmp280Read24(uint8_t reg)
{
    uint32_t data;

    suli_i2c_read_reg(i2c, BMP280_ADDRESS, reg, databuf, 3);

    data = databuf[0];
    data <<= 8;
    data |= databuf[1];
    data <<= 8;
    data |= databuf[2];

    return data;
}










uint8_t Itriangle4in1::Itriangle4in1Read8(uint8_t reg)
{
    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 1);
    return databuf[0];
}

uint16_t Itriangle4in1::Itriangle4in1Read16(uint8_t reg)
{
    uint16_t data=0;
    
    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 3);
    data = (uint16_t)databuf[1];
    data <<= 8;
    data |= (uint16_t)databuf[2];
    return (data);
}

uint16_t Itriangle4in1::Itriangle4in1Read16LE(uint8_t reg)
{
    
    suli_i2c_read_reg(i2c, TH02_I2C_DEV_ID, reg, databuf, 2);
    return (databuf[1] << 8) | databuf[0];
}

int16_t Itriangle4in1::Itriangle4in1ReadS16(uint8_t reg)
{
    return (int16_t)Itriangle4in1Read16(reg);
}

int16_t Itriangle4in1::Itriangle4in1ReadS16LE(uint8_t reg)
{
    return (int16_t)Itriangle4in1Read16LE(reg);
}

uint32_t Itriangle4in1::Itriangle4in1Read24(uint8_t reg)
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

void Itriangle4in1::WriteRegister(uint8_t reg, uint8_t val)
{
    cmdbuf[0] = reg;
    cmdbuf[1] = val;
    suli_i2c_write(i2c, TH02_I2C_DEV_ID, cmdbuf, 2);
}

uint8_t Itriangle4in1::ReadByte(uint8_t address, uint8_t subAddress)
{
	uint8_t data; // `data` will store the register data	 
	Wire.beginTransmission(address);         // Initialize the Tx buffer
	Wire.write(subAddress);	                 // Put slave register address in Tx buffer
	Wire.endTransmission();        // Send the Tx buffer, but send a restart to keep connection alive
											 //	Wire.endTransmission(false);             // Send the Tx buffer, but send a restart to keep connection alive
											 //	Wire.requestFrom(address, 1);  // Read one byte from slave register address 
	Wire.requestFrom(address, (size_t)1);   // Read one byte from slave register address 
	data = Wire.read();                      // Fill Rx buffer with result
	return data;                             // Return data read from slave register
}

void Itriangle4in1::ReadBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest)
{
	Wire.beginTransmission(address);   // Initialize the Tx buffer
	Wire.write(subAddress);            // Put slave register address in Tx buffer
	Wire.endTransmission();  // Send the Tx buffer, but send a restart to keep connection alive
									   //	Wire.endTransmission(false);       // Send the Tx buffer, but send a restart to keep connection alive
	uint8_t i = 0;
	//        Wire.requestFrom(address, count);  // Read bytes from slave register address 
	Wire.requestFrom(address, (size_t)count);  // Read bytes from slave register address 
	while (Wire.available()) {
		dest[i++] = Wire.read();
	}         // Put read results in the Rx buffer
}


void Itriangle4in1::writeByte(uint8_t address, uint8_t subAddress, uint8_t data)
{
	Wire.beginTransmission(address);  // Initialize the Tx buffer
	Wire.write(subAddress);           // Put slave register address in Tx buffer
	Wire.write(data);                 // Put data in Tx buffer
	Wire.endTransmission();           // Send the Tx buffer
}






void Itriangle4in1::MPU9250getAres() {
	switch (MPU9250Ascale)
	{
		// Possible accelerometer scales (and their register bit settings) are:
		// 2 Gs (00), 4 Gs (01), 8 Gs (10), and 16 Gs  (11). 
		// Here's a bit of an algorith to calculate DPS/(ADC tick) based on that 2-bit value:
	case AFS_2G:
		MPU9250aRes = 2.0 / 32768.0;
		break;
	case AFS_4G:
		MPU9250aRes = 4.0 / 32768.0;
		break;
	case AFS_8G:
		MPU9250aRes = 8.0 / 32768.0;
		break;
	case AFS_16G:
		MPU9250aRes = 16.0 / 32768.0;
		break;
	}
}


void Itriangle4in1::MPU9250getGres() {
	switch (MPU9250Gscale)
	{
		// Possible gyro scales (and their register bit settings) are:
		// 250 DPS (00), 500 DPS (01), 1000 DPS (10), and 2000 DPS  (11). 
		// Here's a bit of an algorithm to calculate DPS/(ADC tick) based on that 2-bit value:
	case GFS_250DPS:
		MPU9250gRes = 250.0 / 32768.0;
		break;
	case GFS_500DPS:
		MPU9250gRes = 500.0 / 32768.0;
		break;
	case GFS_1000DPS:
		MPU9250gRes = 1000.0 / 32768.0;
		break;
	case GFS_2000DPS:
		MPU9250gRes = 2000.0 / 32768.0;
		break;
	}
}


void Itriangle4in1::MPU9250getMres() {
	switch (MPU9250Mscale)
	{
		// Possible magnetometer scales (and their register bit settings) are:
		// 14 bit resolution (0) and 16 bit resolution (1)
	case MFS_14BITS:
		MPU9250mRes = 10.*4912. / 8190.; // Proper scale to return milliGauss
		break;
	case MFS_16BITS:
		MPU9250mRes = 10.*4912. / 32760.0; // Proper scale to return milliGauss
		break;
	}
}

void Itriangle4in1::initMPU9250()           //inicializace vsech sensoru
{
	// wake up device
	writeByte(MPU9250_ADDRESS, MPU9250_PWR_MGMT_1, 0x00); // Clear sleep mode bit (6), enable all sensors 
	delay(100); // Wait for all registers to reset 

				// get stable time source
	writeByte(MPU9250_ADDRESS, MPU9250_PWR_MGMT_1, 0x01);  // Auto select clock source to be PLL gyroscope reference if ready else
	delay(200);

	// Configure Gyro and Thermometer
	// Disable FSYNC and set thermometer and gyro bandwidth to 41 and 42 Hz, respectively; 
	// minimum delay time for this setting is 5.9 ms, which means sensor fusion update rates cannot
	// be higher than 1 / 0.0059 = 170 Hz
	// DLPF_CFG = bits 2:0 = 011; this limits the sample rate to 1000 Hz for both
	// With the MPU9250, it is possible to get gyro sample rates of 32 kHz (!), 8 kHz, or 1 kHz
	writeByte(MPU9250_ADDRESS, MPU9250_CONFIG, 0x03);

	// Set sample rate = gyroscope output rate/(1 + SMPLRT_DIV)
	writeByte(MPU9250_ADDRESS, MPU9250_SMPLRT_DIV, 0x04);  // Use a 200 Hz rate; a rate consistent with the filter update rate 
														   // determined inset in CONFIG above

														   // Set gyroscope full scale range
														   // Range selects FS_SEL and AFS_SEL are 0 - 3, so 2-bit values are left-shifted into positions 4:3
	uint8_t c = ReadByte(MPU9250_ADDRESS, MPU9250_GYRO_CONFIG);
	//  writeRegister(GYRO_CONFIG, c & ~0xE0); // Clear self-test bits [7:5] 
	writeByte(MPU9250_ADDRESS, MPU9250_GYRO_CONFIG, c & ~0x02); // Clear Fchoice bits [1:0] 
	writeByte(MPU9250_ADDRESS, MPU9250_GYRO_CONFIG, c & ~0x18); // Clear AFS bits [4:3]
	writeByte(MPU9250_ADDRESS, MPU9250_GYRO_CONFIG, c | MPU9250Gscale << 3); // Set full scale range for the gyro
																			 // writeRegister(GYRO_CONFIG, c | 0x00); // Set Fchoice for the gyro to 11 by writing its inverse to bits 1:0 of GYRO_CONFIG

																			 // Set accelerometer full-scale range configuration
	c = ReadByte(MPU9250_ADDRESS, MPU9250_ACCEL_CONFIG);
	//  writeRegister(ACCEL_CONFIG, c & ~0xE0); // Clear self-test bits [7:5] 
	writeByte(MPU9250_ADDRESS, MPU9250_ACCEL_CONFIG, c & ~0x18); // Clear AFS bits [4:3]
	writeByte(MPU9250_ADDRESS, MPU9250_ACCEL_CONFIG, c | MPU9250Ascale << 3); // Set full scale range for the accelerometer 

																			  // Set accelerometer sample rate configuration
																			  // It is possible to get a 4 kHz sample rate from the accelerometer by choosing 1 for
																			  // accel_fchoice_b bit [3]; in this case the bandwidth is 1.13 kHz
	c = ReadByte(MPU9250_ADDRESS, MPU9250_ACCEL_CONFIG2);
	writeByte(MPU9250_ADDRESS, MPU9250_ACCEL_CONFIG2, c & ~0x0F); // Clear accel_fchoice_b (bit 3) and A_DLPFG (bits [2:0])  
	writeByte(MPU9250_ADDRESS, MPU9250_ACCEL_CONFIG2, c | 0x03); // Set accelerometer rate to 1 kHz and bandwidth to 41 Hz

																 // The accelerometer, gyro, and thermometer are set to 1 kHz sample rates, 
																 // but all these rates are further reduced by a factor of 5 to 200 Hz because of the SMPLRT_DIV setting

																 // Configure Interrupts and Bypass Enable
																 // Set interrupt pin active high, push-pull, hold interrupt pin level HIGH until interrupt cleared,
																 // clear on read of INT_STATUS, and enable I2C_BYPASS_EN so additional chips 
																 // can join the I2C bus and all can be controlled by the Arduino as master
	writeByte(MPU9250_ADDRESS, MPU9250_INT_PIN_CFG, 0x22);
	writeByte(MPU9250_ADDRESS, MPU9250_INT_ENABLE, 0x01);  // Enable data ready (bit 0) interrupt
	delay(100);
}


void Itriangle4in1::initAK8963(float * destination)
{
	// First extract the factory calibration for each magnetometer axis
	uint8_t rawData[3];  // x/y/z gyro calibration data stored here
	writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x00); // Power down magnetometer  
	delay(10);
	writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x0F); // Enter Fuse ROM access mode
	delay(10);
	ReadBytes(AK8963_ADDRESS, AK8963_ASAX, 3, &rawData[0]);  // Read the x-, y-, and z-axis calibration values
	destination[0] = (float)(rawData[0] - 128) / 256. + 1.;   // Return x-axis sensitivity adjustment values, etc.
	destination[1] = (float)(rawData[1] - 128) / 256. + 1.;
	destination[2] = (float)(rawData[2] - 128) / 256. + 1.;
	writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x00); // Power down magnetometer  
	delay(10);
	// Configure the magnetometer for continuous read and highest resolution
	// set Mscale bit 4 to 1 (0) to enable 16 (14) bit resolution in CNTL register,
	// and enable continuous mode data acquisition Mmode (bits [3:0]), 0010 for 8 Hz and 0110 for 100 Hz sample rates
	writeByte(AK8963_ADDRESS, AK8963_CNTL, MPU9250Mscale << 4 | MPU9250Mmode); // Set magnetometer data resolution and sample ODR
	delay(10);
}


void Itriangle4in1::MPU9250readAccelData(int16_t * destination)
{
	uint8_t rawData[6];  // x/y/z accel register data stored here
	ReadBytes(MPU9250_ADDRESS, MPU9250_ACCEL_XOUT_H, 6, &rawData[0]);  // Read the six raw data registers into data array
	destination[0] = ((int16_t)rawData[0] << 8) | rawData[1];  // Turn the MSB and LSB into a signed 16-bit value
	destination[1] = ((int16_t)rawData[2] << 8) | rawData[3];
	destination[2] = ((int16_t)rawData[4] << 8) | rawData[5];
}


void Itriangle4in1::MPU9250readGyroData(int16_t * destination)
{
	uint8_t rawData[6];  // x/y/z gyro register data stored here
	ReadBytes(MPU9250_ADDRESS, MPU9250_GYRO_XOUT_H, 6, &rawData[0]);  // Read the six raw data registers sequentially into data array
	destination[0] = ((int16_t)rawData[0] << 8) | rawData[1];  // Turn the MSB and LSB into a signed 16-bit value
	destination[1] = ((int16_t)rawData[2] << 8) | rawData[3];
	destination[2] = ((int16_t)rawData[4] << 8) | rawData[5];
}

void Itriangle4in1::MPU9250readMagData(int16_t * destination)
{
	uint8_t rawData[7];  // x/y/z gyro register data, ST2 register stored here, must read ST2 at end of data acquisition
	if (ReadByte(AK8963_ADDRESS, AK8963_ST1) & 0x01) { // wait for magnetometer data ready bit to be set
		ReadBytes(AK8963_ADDRESS, AK8963_XOUT_L, 7, &rawData[0]);  // Read the six raw data and ST2 registers sequentially into data array
		uint8_t c = rawData[6]; // End data read by reading ST2 register
		if (!(c & 0x08)) { // Check if magnetic sensor overflow set, if not then report data
			destination[0] = ((int16_t)rawData[1] << 8) | rawData[0];  // Turn the MSB and LSB into a signed 16-bit value
			destination[1] = ((int16_t)rawData[3] << 8) | rawData[2];  // Data stored as little Endian
			destination[2] = ((int16_t)rawData[5] << 8) | rawData[4];
		}
	}
}

void Itriangle4in1::MadgwickQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz)
{
	float q1 = q[0], q2 = q[1], q3 = q[2], q4 = q[3];   // short name local variable for readability
	float norm;
	float hx, hy, _2bx, _2bz;
	float s1, s2, s3, s4;
	float qDot1, qDot2, qDot3, qDot4;
	//            float gerrx, gerry, gerrz, gbiasx, gbiasy, gbiasz;        // gyro bias error

	// Auxiliary variables to avoid repeated arithmetic
	float _2q1mx;
	float _2q1my;
	float _2q1mz;
	float _2q2mx;
	float _4bx;
	float _4bz;
	float _2q1 = 2.0f * q1;
	float _2q2 = 2.0f * q2;
	float _2q3 = 2.0f * q3;
	float _2q4 = 2.0f * q4;
	float _2q1q3 = 2.0f * q1 * q3;
	float _2q3q4 = 2.0f * q3 * q4;
	float q1q1 = q1 * q1;
	float q1q2 = q1 * q2;
	float q1q3 = q1 * q3;
	float q1q4 = q1 * q4;
	float q2q2 = q2 * q2;
	float q2q3 = q2 * q3;
	float q2q4 = q2 * q4;
	float q3q3 = q3 * q3;
	float q3q4 = q3 * q4;
	float q4q4 = q4 * q4;

	// Normalise accelerometer measurement
	norm = sqrt(ax * ax + ay * ay + az * az);
	if (norm == 0.0f) return; // handle NaN
	norm = 1.0f / norm;
	ax *= norm;
	ay *= norm;
	az *= norm;

	// Normalise magnetometer measurement
	norm = sqrt(mx * mx + my * my + mz * mz);
	if (norm == 0.0f) return; // handle NaN
	norm = 1.0f / norm;
	mx *= norm;
	my *= norm;
	mz *= norm;

	// Reference direction of Earth's magnetic field
	_2q1mx = 2.0f * q1 * mx;
	_2q1my = 2.0f * q1 * my;
	_2q1mz = 2.0f * q1 * mz;
	_2q2mx = 2.0f * q2 * mx;
	hx = mx * q1q1 - _2q1my * q4 + _2q1mz * q3 + mx * q2q2 + _2q2 * my * q3 + _2q2 * mz * q4 - mx * q3q3 - mx * q4q4;
	hy = _2q1mx * q4 + my * q1q1 - _2q1mz * q2 + _2q2mx * q3 - my * q2q2 + my * q3q3 + _2q3 * mz * q4 - my * q4q4;
	_2bx = sqrt(hx * hx + hy * hy);
	_2bz = -_2q1mx * q3 + _2q1my * q2 + mz * q1q1 + _2q2mx * q4 - mz * q2q2 + _2q3 * my * q4 - mz * q3q3 + mz * q4q4;
	_4bx = 2.0f * _2bx;
	_4bz = 2.0f * _2bz;

	// Gradient decent algorithm corrective step
	s1 = -_2q3 * (2.0f * q2q4 - _2q1q3 - ax) + _2q2 * (2.0f * q1q2 + _2q3q4 - ay) - _2bz * q3 * (_2bx * (0.5f - q3q3 - q4q4) + _2bz * (q2q4 - q1q3) - mx) + (-_2bx * q4 + _2bz * q2) * (_2bx * (q2q3 - q1q4) + _2bz * (q1q2 + q3q4) - my) + _2bx * q3 * (_2bx * (q1q3 + q2q4) + _2bz * (0.5f - q2q2 - q3q3) - mz);
	s2 = _2q4 * (2.0f * q2q4 - _2q1q3 - ax) + _2q1 * (2.0f * q1q2 + _2q3q4 - ay) - 4.0f * q2 * (1.0f - 2.0f * q2q2 - 2.0f * q3q3 - az) + _2bz * q4 * (_2bx * (0.5f - q3q3 - q4q4) + _2bz * (q2q4 - q1q3) - mx) + (_2bx * q3 + _2bz * q1) * (_2bx * (q2q3 - q1q4) + _2bz * (q1q2 + q3q4) - my) + (_2bx * q4 - _4bz * q2) * (_2bx * (q1q3 + q2q4) + _2bz * (0.5f - q2q2 - q3q3) - mz);
	s3 = -_2q1 * (2.0f * q2q4 - _2q1q3 - ax) + _2q4 * (2.0f * q1q2 + _2q3q4 - ay) - 4.0f * q3 * (1.0f - 2.0f * q2q2 - 2.0f * q3q3 - az) + (-_4bx * q3 - _2bz * q1) * (_2bx * (0.5f - q3q3 - q4q4) + _2bz * (q2q4 - q1q3) - mx) + (_2bx * q2 + _2bz * q4) * (_2bx * (q2q3 - q1q4) + _2bz * (q1q2 + q3q4) - my) + (_2bx * q1 - _4bz * q3) * (_2bx * (q1q3 + q2q4) + _2bz * (0.5f - q2q2 - q3q3) - mz);
	s4 = _2q2 * (2.0f * q2q4 - _2q1q3 - ax) + _2q3 * (2.0f * q1q2 + _2q3q4 - ay) + (-_4bx * q4 + _2bz * q2) * (_2bx * (0.5f - q3q3 - q4q4) + _2bz * (q2q4 - q1q3) - mx) + (-_2bx * q1 + _2bz * q3) * (_2bx * (q2q3 - q1q4) + _2bz * (q1q2 + q3q4) - my) + _2bx * q2 * (_2bx * (q1q3 + q2q4) + _2bz * (0.5f - q2q2 - q3q3) - mz);
	norm = sqrt(s1 * s1 + s2 * s2 + s3 * s3 + s4 * s4);    // normalise step magnitude
	norm = 1.0f / norm;
	s1 *= norm;
	s2 *= norm;
	s3 *= norm;
	s4 *= norm;

	/*            // Compute estimated gyroscope biases
	gerrx = _2q1 * s2 - _2q2 * s1 - _2q3 * s4 + _2q4 * s3;
	gerry = _2q1 * s3 + _2q2 * s4 - _2q3 * s1 - _2q4 * s2;
	gerrz = _2q1 * s4 - _2q2 * s3 + _2q3 * s2 - _2q4 * s1;

	// Compute and remove gyroscope biases
	gbiasx += gerrx * deltat * zeta;
	gbiasy += gerry * deltat * zeta;
	gbiasz += gerrz * deltat * zeta;
	gx -= gbiasx;
	gy -= gbiasy;
	gz -= gbiasz;
	*/
	// Compute rate of change of quaternion
	qDot1 = 0.5f * (-q2 * gx - q3 * gy - q4 * gz) - beta * s1;
	qDot2 = 0.5f * (q1 * gx + q3 * gz - q4 * gy) - beta * s2;
	qDot3 = 0.5f * (q1 * gy - q2 * gz + q4 * gx) - beta * s3;
	qDot4 = 0.5f * (q1 * gz + q2 * gy - q3 * gx) - beta * s4;

	// Integrate to yield quaternion
	q1 += qDot1 * deltat;
	q2 += qDot2 * deltat;
	q3 += qDot3 * deltat;
	q4 += qDot4 * deltat;
	norm = sqrt(q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4);    // normalise quaternion
	norm = 1.0f / norm;
	q[0] = q1 * norm;
	q[1] = q2 * norm;
	q[2] = q3 * norm;
	q[3] = q4 * norm;

}



void Itriangle4in1::MahonyQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz)
{
	float q1 = q[0], q2 = q[1], q3 = q[2], q4 = q[3];   // short name local variable for readability
	float norm;
	float hx, hy, bx, bz;
	float vx, vy, vz, wx, wy, wz;
	float ex, ey, ez;
	float pa, pb, pc;

	// Auxiliary variables to avoid repeated arithmetic
	float q1q1 = q1 * q1;
	float q1q2 = q1 * q2;
	float q1q3 = q1 * q3;
	float q1q4 = q1 * q4;
	float q2q2 = q2 * q2;
	float q2q3 = q2 * q3;
	float q2q4 = q2 * q4;
	float q3q3 = q3 * q3;
	float q3q4 = q3 * q4;
	float q4q4 = q4 * q4;

	// Normalise accelerometer measurement
	norm = sqrt(ax * ax + ay * ay + az * az);
	if (norm == 0.0f) return; // handle NaN
	norm = 1.0f / norm;        // use reciprocal for division
	ax *= norm;
	ay *= norm;
	az *= norm;

	// Normalise magnetometer measurement
	norm = sqrt(mx * mx + my * my + mz * mz);
	if (norm == 0.0f) return; // handle NaN
	norm = 1.0f / norm;        // use reciprocal for division
	mx *= norm;
	my *= norm;
	mz *= norm;

	// Reference direction of Earth's magnetic field
	hx = 2.0f * mx * (0.5f - q3q3 - q4q4) + 2.0f * my * (q2q3 - q1q4) + 2.0f * mz * (q2q4 + q1q3);
	hy = 2.0f * mx * (q2q3 + q1q4) + 2.0f * my * (0.5f - q2q2 - q4q4) + 2.0f * mz * (q3q4 - q1q2);
	bx = sqrt((hx * hx) + (hy * hy));
	bz = 2.0f * mx * (q2q4 - q1q3) + 2.0f * my * (q3q4 + q1q2) + 2.0f * mz * (0.5f - q2q2 - q3q3);

	// Estimated direction of gravity and magnetic field
	vx = 2.0f * (q2q4 - q1q3);
	vy = 2.0f * (q1q2 + q3q4);
	vz = q1q1 - q2q2 - q3q3 + q4q4;
	wx = 2.0f * bx * (0.5f - q3q3 - q4q4) + 2.0f * bz * (q2q4 - q1q3);
	wy = 2.0f * bx * (q2q3 - q1q4) + 2.0f * bz * (q1q2 + q3q4);
	wz = 2.0f * bx * (q1q3 + q2q4) + 2.0f * bz * (0.5f - q2q2 - q3q3);

	// Error is cross product between estimated direction and measured direction of gravity
	ex = (ay * vz - az * vy) + (my * wz - mz * wy);
	ey = (az * vx - ax * vz) + (mz * wx - mx * wz);
	ez = (ax * vy - ay * vx) + (mx * wy - my * wx);
	if (Ki > 0.0f)
	{
		eInt[0] += ex;      // accumulate integral error
		eInt[1] += ey;
		eInt[2] += ez;
	}
	else
	{
		eInt[0] = 0.0f;     // prevent integral wind up
		eInt[1] = 0.0f;
		eInt[2] = 0.0f;
	}

	// Apply feedback terms
	gx = gx + Kp * ex + Ki * eInt[0];
	gy = gy + Kp * ey + Ki * eInt[1];
	gz = gz + Kp * ez + Ki * eInt[2];

	// Integrate rate of change of quaternion
	pa = q2;
	pb = q3;
	pc = q4;
	q1 = q1 + (-q2 * gx - q3 * gy - q4 * gz) * (0.5f * deltat);
	q2 = pa + (q1 * gx + pb * gz - pc * gy) * (0.5f * deltat);
	q3 = pb + (q1 * gy - pa * gz + pc * gx) * (0.5f * deltat);
	q4 = pc + (q1 * gz + pa * gy - pb * gx) * (0.5f * deltat);

	// Normalise quaternion
	norm = sqrt(q1 * q1 + q2 * q2 + q3 * q3 + q4 * q4);
	norm = 1.0f / norm;
	q[0] = q1 * norm;
	q[1] = q2 * norm;
	q[2] = q3 * norm;
	q[3] = q4 * norm;

}


void Itriangle4in1::magcalMPU9250(float * dest1)
{
	uint16_t ii = 0, sample_count = 0;
	int32_t mag_bias[3] = { 0, 0, 0 };
	int16_t mag_max[3] = { -32767, -32767, -32767 }, mag_min[3] = { 32767, 32767, 32767 }, mag_temp[3] = { 0, 0, 0 };

	//suli_delay_ms(4000);

	sample_count = 64;
	for (ii = 0; ii < sample_count; ii++) {
		MPU9250readMagData(mag_temp);  // Read the mag data   
		for (int jj = 0; jj < 3; jj++) {
			if (mag_temp[jj] > mag_max[jj]) mag_max[jj] = mag_temp[jj];
			if (mag_temp[jj] < mag_min[jj]) mag_min[jj] = mag_temp[jj];
		}
		delay(135);  // at 8 Hz ODR, new mag data is available every 125 ms
	}

	mag_bias[0] = (mag_max[0] + mag_min[0]) / 2;  // get average x mag bias in counts
	mag_bias[1] = (mag_max[1] + mag_min[1]) / 2;  // get average y mag bias in counts
	mag_bias[2] = (mag_max[2] + mag_min[2]) / 2;  // get average z mag bias in counts

	dest1[0] = (float)mag_bias[0] * MPU9250mRes*magCalibration[0];  // save mag biases in G for main program
	dest1[1] = (float)mag_bias[1] * MPU9250mRes*magCalibration[1];
	dest1[2] = (float)mag_bias[2] * MPU9250mRes*magCalibration[2];


}