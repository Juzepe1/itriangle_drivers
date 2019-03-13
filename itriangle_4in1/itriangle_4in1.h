
#ifndef __ITRIANGLE_4IN1_H__
#define __ITRIANGLE_4IN1_H__

#include "suli2.h"

//GROVE_NAME        "4in1 sensor"
//SKU               180401020
//IF_TYPE           I2C
//IMAGE_URL         https://code.itriangle.cz/static/pictures/16.png
//DESCRIPTION       "Sensor measuring ambient pressure and temperature, acceleration and gyroscope coefficients in all three axis."
//WIKI_URL          http://wiki.itriangle.cz/books/itriangle-eng/page/4-in-1-sensor
//ADDED_AT          "2018-04-01"
//AUTHOR            "BOXED"
//BUYURL            https://portal.boxed.cz/shop/product/snimac-4-v-1-125?category=81
//LANG               [{"source": "4in1.Name", "en": "4in1 sensor", "cs": "Sensor 4v1"},{"source": "4in1.Description", "en": "Sensor measuring ambient pressure and temperature, acceleration and gyroscope coefficients in all three axis.", "cs": "Měří tlak vzduchu a teplotu okolního prostředí a hodnoty akcelerometru a gyroskopu ve všech třech osách."},{"source": "read_heading", "en": "get heading", "cs": "načti azimut"},{"source": "read_calibration", "en": "get calibration state", "cs": "zjisti stav kalibrace"},{"source": "read_accelx", "en": "get accel x", "cs": "načti akcelerometr x"},{"source": "read_accely", "en": "get accel y", "cs": "načti akcelerometr y"},{"source": "read_accelz", "en": "get accel z", "cs": "načti akcelerometr z"},{"source": "read_gyrox", "en": "get gyroscope x", "cs": "načti gyroskop x"},{"source": "read_gyroy", "en": "get gyroscope y", "cs": "načti gyroskop y"},{"source": "read_gyroz", "en": "get gyroscope z", "cs": "načti gyroskop z"},{"source": "read_magx", "en": "get magnetometer x", "cs": "načti magnetometr x"},{"source": "read_magy", "en": "get magnetometer y", "cs": "načti magnetometr y"},{"source": "read_magz", "en": "get magnetometer z", "cs": "načti magnetometr z"},{"source": "read_temperature", "en": "get baro temperature", "cs": "načti teplotu z barometru"},{"source": "read_temperature2", "en": "get accel temperature", "cs": "načti teplotu z akcelerometru"},{"source": "read_pressure", "en": "get absolute pressure", "cs": "načti hodnotu tlaku"},{"source": "read_altitude", "en": "get altitude", "cs": "spočti nadmořskou výšku"},{"source": "4in1.Wiki", "en": "http://wiki.itriangle.cz/books/itriangle-eng/page/4-in-1-sensor", "cs": "http://wiki.itriangle.cz/books/itriangle-cz/page/4-in-1-sensor"}]
//ITR_NAME          4in1.Name
//ITR_DESCRIPTION   4in1.Description
//ITR_WIKI			4in1.Wiki

//Magnetometer Registers
#define WHO_AM_I_AK8963  0x00 // should return 0x48
#define INFO             0x01
#define AK8963_ST1       0x02  // data ready status bit 0
#define AK8963_XOUT_L	 0x03  // data
#define AK8963_XOUT_H	 0x04
#define AK8963_YOUT_L	 0x05
#define AK8963_YOUT_H	 0x06
#define AK8963_ZOUT_L	 0x07
#define AK8963_ZOUT_H	 0x08
#define AK8963_ST2       0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL      0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_ASTC      0x0C  // Self test control
#define AK8963_I2CDIS    0x0F  // I2C disable
#define AK8963_ASAX      0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY      0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ      0x12  // Fuse ROM z-axis sensitivity adjustment value

//Accelerometer and gyroscope registers
#define MPU9250_SELF_TEST_X_GYRO 0x00                  
#define MPU9250_SELF_TEST_Y_GYRO 0x01                                                                          
#define MPU9250_SELF_TEST_Z_GYRO 0x02

#define MPU9250_SELF_TEST_X_ACCEL 0x0D
#define MPU9250_SELF_TEST_Y_ACCEL 0x0E    
#define MPU9250_SELF_TEST_Z_ACCEL 0x0F

#define MPU9250_SELF_TEST_A      0x10

#define MPU9250_XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define MPU9250_XG_OFFSET_L      0x14
#define MPU9250_YG_OFFSET_H      0x15
#define MPU9250_YG_OFFSET_L      0x16
#define MPU9250_ZG_OFFSET_H      0x17
#define MPU9250_ZG_OFFSET_L      0x18
#define MPU9250_SMPLRT_DIV       0x19
#define MPU9250_CONFIG           0x1A
#define MPU9250_GYRO_CONFIG      0x1B
#define MPU9250_ACCEL_CONFIG     0x1C
#define MPU9250_ACCEL_CONFIG2    0x1D
#define MPU9250_LP_ACCEL_ODR     0x1E   
#define MPU9250_WOM_THR          0x1F   

#define MPU9250_MOT_DUR          0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define MPU9250_ZMOT_THR         0x21  // Zero-motion detection threshold bits [7:0]
#define MPU9250_ZRMOT_DUR        0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

#define MPU9250_FIFO_EN          0x23
#define MPU9250_I2C_MST_CTRL     0x24   
#define MPU9250_I2C_SLV0_ADDR    0x25
#define MPU9250_I2C_SLV0_REG     0x26
#define MPU9250_I2C_SLV0_CTRL    0x27
#define MPU9250_I2C_SLV1_ADDR    0x28
#define MPU9250_I2C_SLV1_REG     0x29
#define MPU9250_I2C_SLV1_CTRL    0x2A
#define MPU9250_I2C_SLV2_ADDR    0x2B
#define MPU9250_I2C_SLV2_REG     0x2C
#define MPU9250_I2C_SLV2_CTRL    0x2D
#define MPU9250_I2C_SLV3_ADDR    0x2E
#define MPU9250_I2C_SLV3_REG     0x2F
#define MPU9250_I2C_SLV3_CTRL    0x30
#define MPU9250_I2C_SLV4_ADDR    0x31
#define MPU9250_I2C_SLV4_REG     0x32
#define MPU9250_I2C_SLV4_DO      0x33
#define MPU9250_I2C_SLV4_CTRL    0x34
#define MPU9250_I2C_SLV4_DI      0x35
#define MPU9250_I2C_MST_STATUS   0x36
#define MPU9250_INT_PIN_CFG      0x37
#define MPU9250_INT_ENABLE       0x38
#define MPU9250_DMP_INT_STATUS   0x39  // Check DMP interrupt
#define MPU9250_INT_STATUS       0x3A
#define MPU9250_ACCEL_XOUT_H     0x3B
#define MPU9250_ACCEL_XOUT_L     0x3C
#define MPU9250_ACCEL_YOUT_H     0x3D
#define MPU9250_ACCEL_YOUT_L     0x3E
#define MPU9250_ACCEL_ZOUT_H     0x3F
#define MPU9250_ACCEL_ZOUT_L     0x40
#define MPU9250_TEMP_OUT_H       0x41
#define MPU9250_TEMP_OUT_L       0x42
#define MPU9250_GYRO_XOUT_H      0x43
#define MPU9250_GYRO_XOUT_L      0x44
#define MPU9250_GYRO_YOUT_H      0x45
#define MPU9250_GYRO_YOUT_L      0x46
#define MPU9250_GYRO_ZOUT_H      0x47
#define MPU9250_GYRO_ZOUT_L      0x48
#define MPU9250_EXT_SENS_DATA_00 0x49
#define MPU9250_EXT_SENS_DATA_01 0x4A
#define MPU9250_EXT_SENS_DATA_02 0x4B
#define MPU9250_EXT_SENS_DATA_03 0x4C
#define MPU9250_EXT_SENS_DATA_04 0x4D
#define MPU9250_EXT_SENS_DATA_05 0x4E
#define MPU9250_EXT_SENS_DATA_06 0x4F
#define MPU9250_EXT_SENS_DATA_07 0x50
#define MPU9250_EXT_SENS_DATA_08 0x51
#define MPU9250_EXT_SENS_DATA_09 0x52
#define MPU9250_EXT_SENS_DATA_10 0x53
#define MPU9250_EXT_SENS_DATA_11 0x54
#define MPU9250_EXT_SENS_DATA_12 0x55
#define MPU9250_EXT_SENS_DATA_13 0x56
#define MPU9250_EXT_SENS_DATA_14 0x57
#define MPU9250_EXT_SENS_DATA_15 0x58
#define MPU9250_EXT_SENS_DATA_16 0x59
#define MPU9250_EXT_SENS_DATA_17 0x5A
#define MPU9250_EXT_SENS_DATA_18 0x5B
#define MPU9250_EXT_SENS_DATA_19 0x5C
#define MPU9250_EXT_SENS_DATA_20 0x5D
#define MPU9250_EXT_SENS_DATA_21 0x5E
#define MPU9250_EXT_SENS_DATA_22 0x5F
#define MPU9250_EXT_SENS_DATA_23 0x60
#define MPU9250_MOT_DETECT_STATUS 0x61
#define MPU9250_I2C_SLV0_DO      0x63
#define MPU9250_I2C_SLV1_DO      0x64
#define MPU9250_I2C_SLV2_DO      0x65
#define MPU9250_I2C_SLV3_DO      0x66
#define MPU9250_I2C_MST_DELAY_CTRL 0x67
#define MPU9250_SIGNAL_PATH_RESET  0x68
#define MPU9250_MOT_DETECT_CTRL  0x69
#define MPU9250_USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define MPU9250_PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define MPU9250_PWR_MGMT_2       0x6C
#define MPU9250_DMP_BANK         0x6D  // Activates a specific bank in the DMP
#define MPU9250_DMP_RW_PNT       0x6E  // Set read/write pointer to a specific start address in specified DMP bank
#define MPU9250_DMP_REG          0x6F  // Register in DMP from which to read or to which to write
#define MPU9250_DMP_REG_1        0x70
#define MPU9250_DMP_REG_2        0x71 
#define MPU9250_FIFO_COUNTH      0x72
#define MPU9250_FIFO_COUNTL      0x73
#define MPU9250_FIFO_R_W         0x74
#define MPU9250_WHO_AM_I         0x75 // Should return 0x71
#define MPU9250_XA_OFFSET_H      0x77
#define MPU9250_XA_OFFSET_L      0x78
#define MPU9250_YA_OFFSET_H      0x7A
#define MPU9250_YA_OFFSET_L      0x7B
#define MPU9250_ZA_OFFSET_H      0x7D
#define MPU9250_ZA_OFFSET_L      0x7E
                     
#define TH02_I2C_DEV_ID       0x40
#define MPU9250_ADDRESS       0x68       // MPU9250 address when ADO = 1
#define AK8963_ADDRESS        0x0C        // Address of AK8963 (MPU9250) magnetometer
#define BMP280_ADDRESS        0x77      // Address of BMP280



// BMP280 registers
#define BMP280_TEMP_XLSB  0xFC
#define BMP280_TEMP_LSB   0xFB
#define BMP280_TEMP_MSB   0xFA
#define BMP280_PRESS_XLSB 0xF9
#define BMP280_PRESS_LSB  0xF8
#define BMP280_PRESS_MSB  0xF7
#define BMP280_CONFIG     0xF5
#define BMP280_CTRL_MEAS  0xF4
#define BMP280_STATUS     0xF3
#define BMP280_RESET      0xE0
#define BMP280_ID         0xD0  // should be 0x58
#define BMP280_CALIB00    0x88



//#define SerialDebug false  // set to true to get Serial output for debugging




class Itriangle4in1
{
public:
     Itriangle4in1(int pinsda, int pinscl);
    
    
    
    /**  
     *  Gets heading to magnetic North  (azimuth)
     *
     *  @param heading -  degrees
     *
     *
     */
         
    bool read_heading(float *heading);
    
    
    /**  
     *  Waits for sensor calibration for magnetic measurements
     *
     *  @param done -  finished - true - 1, not finished - false - 0
     *
     *
     */
         
    bool read_calibration(bool *finished);
    
    
    
    
    
    /**  
     *  Gets acceleration coefficient iz x-axis
     *
     *  @param accelx -  m/s2
     *
     *
     */
         
            
         
    bool read_accelx(float *accelx);
    
    
   /**  
     *  Gets acceleration coefficient iz y-axis
     *
     *  @param accely -  m/s2
     *
     *
     */
         
    bool read_accely(float *accely);
    
    
    
    
    /**  
     *  Gets acceleration coefficient iz z-axis
     *
     *  @param accelz -  m/s2
     *
     *
     */
         
    bool read_accelz(float *accelz);
    
    
    /**  
     *  Gets gyroscope coefficient iz x-axis
     *
     *  @param gyrox -  m/s2
     *
     *
     */
         
    bool read_gyrox(float *gyrox);
  
  
  /**  
     *  Gets gyroscope coefficient iz y-axis
     *
     *  @param gyroy -  m/s2
     *
     *
     */
         
    bool read_gyroy(float *gyroy);
    
    /**  
     *  Gets gyroscope coefficient iz z-axis
     *
     *  @param gyroz -  m/s2
     *
     *
     */
         
    bool read_gyroz(float *gyroz);
    
    
    /**  
     *  Gets magnetometer coefficient iz x-axis
     *
     *  @param magx -  mG
     *
     */
         
    bool read_magx(float *magx);
  
  
  /**  
     *  Gets magnetometer coefficient iz y-axis
     *
     *  @param magy -  mG
     *
     *
     */
         
    bool read_magy(float *magy);
    
    /**  
     *  Gets magnetometer coefficient iz z-axis
     *
     *  @param magz -  mG
     *
     *
     */
         
    bool read_magz(float *magz);
    
    
    
    
    
   
    
    
   /**  
     *  Gets temperature from barometric sensor
     *
     *  @param temper -  °C
     *
     *
     */
    
     bool read_temperature(float *temper);
    
    
    /**  
     *  Gets temperature from accelerometer
     *
     *  @param temper2 -  °C
     *
     *
     */
    
     bool read_temperature2(float *temper2);
    
    
    
    /**  
     *  Gets absolute pressure in hPa.
     *
     *  @param pressure -  hPa
     *
     *
     */
    
     bool read_pressure(float *press);
     
     /**  
     *  Gets calculated sea level pressure in hPa.
     *
     *@param alti -  local altitude in m
     *@param sea_pressure -  hPa
     *
     *
     */     
    

    
     bool read_altitude(float *altit);  
    
    
    /**  
     *  Connects to sensor MPU9250 if available
     *
     *  @param whoami -  answer 0x71 or 113 DEC
     *
     *
     */
    
     bool whoami(uint8_t *whoami);  
    
     /**  
     *  Connects to sensor AK8963 if available
     *
     *  @param whoami -  answer 0x48 or 72 DEC
     *
     *
     */
    
     bool whoami_mag(uint8_t *whoami);  
     
      /**  
     *  Connects to sensor BMP280 if available
     *
     *  @param whoami -  answer 0x58 or 88 DEC
     *
     *
     */
    
     bool whoami_bmp(uint8_t *whoami);  
   

private:
    I2C_T *i2c;
    
    uint8_t cmdbuf[2];
    uint8_t databuf[3];
    uint16_t valuebuf[3];   
    
    uint8_t Itriangle4in1Read8(uint8_t reg);
    uint16_t Itriangle4in1Read16(uint8_t reg);
    uint16_t Itriangle4in1Read16LE(uint8_t reg);
    int16_t Itriangle4in1ReadS16(uint8_t reg);
    int16_t Itriangle4in1ReadS16LE(uint8_t reg);
    uint32_t Itriangle4in1Read24(uint8_t reg);
    void WriteRegister(uint8_t reg, uint8_t val);
    
    int32_t readBMP280Temperature();
    void BMP280Init();
    int32_t bmp280_compensate_T(int32_t adc_T);
    int32_t readBMP280Pressure();
    uint32_t bmp280_compensate_P(int32_t adc_P);
    
    uint8_t bmp280Read8(uint8_t reg);
    uint16_t bmp280Read16(uint8_t reg);
    uint16_t bmp280Read16LE(uint8_t reg);
    int16_t bmp280ReadS16(uint8_t reg);
    int16_t bmp280ReadS16LE(uint8_t reg);
    uint32_t bmp280Read24(uint8_t reg);
    
    
    
    uint8_t ReadByte(uint8_t address, uint8_t subAddress);
    void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
    void ReadBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t * dest);
    void MPU9250getAres();
		void MPU9250getGres();
		void MPU9250getMres();                
    void initMPU9250();
    void initAK8963(float *destination);
    int16_t MPU9250readTempData();
    void MPU9250readAccelData(int16_t *destination);
    void MPU9250readMagData(int16_t *destination);
    void MPU9250readGyroData(int16_t *destination);
    void MadgwickQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
    void MahonyQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
    void magcalMPU9250(float * dest1);
    

uint16_t dig_T1, dig_P1;
int16_t  dig_T2, dig_T3, dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;

// 
float MPU9250aRes, MPU9250gRes, MPU9250mRes; 
uint8_t MPU9250Gscale = GFS_250DPS;
uint8_t MPU9250Ascale = AFS_16G;
uint8_t MPU9250Mscale = MFS_16BITS; // Choose either 14-bit or 16-bit magnetometer resolution
uint8_t MPU9250Mmode = 0x06;        // 2 for 8 Hz, 6 for 100 Hz continuous magnetometer data read
int32_t rawPress, rawTemp;   // pressure and temperature raw count output for BMP280
int16_t accelCount[3];  // Stores the 16-bit signed accelerometer sensor output
int16_t gyroCount[3];   // Stores the 16-bit signed gyro sensor output
int16_t magCount[3];    // Stores the 16-bit signed magnetometer sensor output
float magCalibration[3] = { 0, 0, 0 };  // Factory mag calibration and mag bias
float MPU9250gyroBias[3] = { 0, 0, 0 }, MPU9250accelBias[3] = { 0, 0, 0 }, MPU9250magBias[3] = { 0, 0, 0 };      // Bias corrections for gyro and accelerometer
int16_t tempCount;            // temperature raw count output
float   temperature, altitude, temper;          // Stores the MPU9250 gyro internal chip temperature in degrees Celsius
double BMP280Temperature, BMP280Pressure; // stores MS5637 pressures sensor pressure and temperature
float SelfTest[6];            // holds results of gyro and accelerometer self test

							  // global constants for 9 DoF fusion and AHRS (Attitude and Heading Reference System)
float pi = 3.14159f;
float GyroMeasError = pi * (40.0f / 180.0f);   // gyroscope measurement error in rads/s (start at 40 deg/s)
float GyroMeasDrift = pi * (0.0f / 180.0f);   // gyroscope measurement drift in rad/s/s (start at 0.0 deg/s/s)
											  // There is a tradeoff in the beta parameter between accuracy and response speed.
											  // In the original Madgwick study, beta of 0.041 (corresponding to GyroMeasError of 2.7 degrees/s) was found to give optimal accuracy.
											  // However, with this value, the LSM9SD0 response time is about 10 seconds to a stable initial quaternion.
											  // Subsequent changes also require a longish lag time to a stable output, not fast enough for a quadcopter or robot car!
											  // By increasing beta (GyroMeasError) by about a factor of fifteen, the response time constant is reduced to ~2 sec
											  // I haven't noticed any reduction in solution accuracy. This is essentially the I coefficient in a PID control sense; 
											  // the bigger the feedback coefficient, the faster the solution converges, usually at the expense of accuracy. 
											  // In any case, this is the free parameter in the Madgwick filtering and fusion scheme.
float beta = sqrt(3.0f / 4.0f) * GyroMeasError;   // compute beta
float zeta = sqrt(3.0f / 4.0f) * GyroMeasDrift;   // compute zeta, the other free parameter in the Madgwick scheme usually set to a small or zero value
#define Kp 2.0f * 5.0f // these are the free parameters in the Mahony filter and fusion scheme, Kp for proportional feedback, Ki for integral
#define Ki 0.0f

uint32_t delt_t = 0, count = 0, sumCount = 0;  // used to control display output rate
float pitch, yaw, roll;
float a12, a22, a31, a32, a33;            // rotation matrix coefficients for Euler angles and gravity components
float deltat = 0.0f, sum = 0.0f;          // integration interval for both filter schemes
uint32_t lastUpdate = 0, firstUpdate = 0; // used to calculate integration interval
uint32_t Now = 0;                         // used to calculate integration interval

float ax, ay, az, gx, gy, gz, mx, my, mz; // variables to hold latest MPU9250 sensor data values 
float lin_ax, lin_ay, lin_az;             // linear acceleration (acceleration with gravity component subtracted)
float q[4] = { 1.0f, 0.0f, 0.0f, 0.0f };    // vector to hold quaternion
float eInt[3] = { 0.0f, 0.0f, 0.0f };       // vector to hold integral error for Mahony method

int32_t t_fine;
uint8_t BMP280Posr = P_OSR_16, BMP280Tosr = T_OSR_02, BMP280Mode = normal, BMP280IIRFilter = BW0_042ODR, BMP280SBy = t_62_5ms;     // set pressure amd temperature output data rate
																																   // t_fine carries fine temperature as global value for BMP280



    
// Set initial input parameters
enum MPU9250Ascale {
	AFS_2G = 0,
	AFS_4G,
	AFS_8G,
	AFS_16G
};

enum MPU9250Gscale {
	GFS_250DPS = 0,
	GFS_500DPS,
	GFS_1000DPS,
	GFS_2000DPS
};

enum MPU9250Mscale {
	MFS_14BITS = 0, // 0.6 mG per LSB
	MFS_16BITS      // 0.15 mG per LSB
};

enum BMP280Posr {
	P_OSR_00 = 0,  // no op
	P_OSR_01,
	P_OSR_02,
	P_OSR_04,
	P_OSR_08,
	P_OSR_16
};

enum BMP280Tosr {
	T_OSR_00 = 0,  // no op
	T_OSR_01,
	T_OSR_02,
	T_OSR_04,
	T_OSR_08,
	T_OSR_16
};

enum BMP280IIRFilter {
	full = 0,  // bandwidth at full sample rate
	BW0_223ODR,
	BW0_092ODR,
	BW0_042ODR,
	BW0_021ODR // bandwidth at 0.021 x sample rate
};

enum BMP280Mode {
	Sleep = 0,
	forced,
	forced2,
	normal
};

enum BMP280SBy {
	t_00_5ms = 0,
	t_62_5ms,
	t_125ms,
	t_250ms,
	t_500ms,
	t_1000ms,
	t_2000ms,
	t_4000ms,
};    
     

};


#endif
