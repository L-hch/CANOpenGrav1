#include "mpu6050.h"
#include <p18cxxx.h>       //processor header file


MPU6050_dataStruct MPU6050_device1Data;
MPU6050_dataStruct MPU6050_device2Data;




void MPU6050_reset(void)
{
  // first reset i2c device ( Try to reset i2c hang device by pulsing slc 9 times with sla  tri-state);
   //i2c_Reset();  
    // Invalidate Accelerometers
   MPU6050_device1Data.Valid=0;
   MPU6050_device2Data.Valid=0;
   setDevice1LED(0);
   setDevice2LED(0);

    
}




unsigned char MPU6050_isFound(unsigned char I2CAdd)
{
    unsigned char Data = 0x00;
    LDByteReadI2C(I2CAdd, MPU6050_RA_WHO_AM_I, &Data, 1);
 
    if(Data == (I2CAdd & 0x7e))
      return(1);   
    return(0);
}


void MPU6050_setup(unsigned char I2CAdd, MPU6050_controlUnion _control)
{
   int loop;
   unsigned char TheReg;
  
// I need code space. Just create a table with register to clear
const unsigned char MPU6050RegTable[]= {
    MPU6050_RA_FF_THR,    		//Freefall threshold of |0mg|  LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FF_THR, 0x00);
    MPU6050_RA_FF_DUR,    		//Freefall duration limit of 0   LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FF_DUR, 0x00);
    MPU6050_RA_MOT_THR,		//Motion threshold of 0mg     LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_MOT_THR, 0x00);
    MPU6050_RA_MOT_DUR,    		//Motion duration of 0s    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_MOT_DUR, 0x00);
    MPU6050_RA_ZRMOT_THR,    	//Zero motion threshold    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_ZRMOT_THR, 0x00);
    MPU6050_RA_ZRMOT_DUR,    	//Zero motion duration threshold    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_ZRMOT_DUR, 0x00);
    MPU6050_RA_FIFO_EN,    		//Disable sensor output to FIFO buffer    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FIFO_EN, 0x00);
    MPU6050_RA_I2C_MST_CTRL,    //AUX I2C setup    //Sets AUX I2C to single master control, plus other config    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_MST_CTRL, 0x00);
    MPU6050_RA_I2C_SLV0_ADDR,  //Setup AUX I2C slaves    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_ADDR, 0x00);
    MPU6050_RA_I2C_SLV0_REG,   	//    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_REG, 0x00);
    MPU6050_RA_I2C_SLV0_CTRL,  	//    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_CTRL, 0x00);
    MPU6050_RA_I2C_SLV1_ADDR, // LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_ADDR, 0x00);
    MPU6050_RA_I2C_SLV1_REG,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_REG, 0x00);
    MPU6050_RA_I2C_SLV1_CTRL,  //LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_CTRL, 0x00);
    MPU6050_RA_I2C_SLV2_ADDR,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_ADDR, 0x00);
    MPU6050_RA_I2C_SLV2_REG,    //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_REG, 0x00);
    MPU6050_RA_I2C_SLV2_CTRL,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_CTRL, 0x00);
    MPU6050_RA_I2C_SLV3_ADDR,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_ADDR, 0x00);
    MPU6050_RA_I2C_SLV3_REG,    //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_REG, 0x00);
    MPU6050_RA_I2C_SLV3_CTRL,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_CTRL, 0x00);
    MPU6050_RA_I2C_SLV4_ADDR,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_ADDR, 0x00);
    MPU6050_RA_I2C_SLV4_REG,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_REG, 0x00);
    MPU6050_RA_I2C_SLV4_DO,     //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_DO, 0x00);
    MPU6050_RA_I2C_SLV4_CTRL,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_CTRL, 0x00);
    MPU6050_RA_I2C_SLV4_DI,      //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_DI, 0x00);
    MPU6050_RA_INT_PIN_CFG,     //MPU6050_RA_I2C_MST_STATUS //Read-only    //Setup INT pin and AUX I2C pass through    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_INT_PIN_CFG, 0x00);
    MPU6050_RA_INT_ENABLE,    //Enable data ready interrupt      LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_INT_ENABLE, 0x00);
    MPU6050_RA_I2C_SLV0_DO,  //Slave out, dont care    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_DO, 0x00);
    MPU6050_RA_I2C_SLV1_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_DO, 0x00);
    MPU6050_RA_I2C_SLV2_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_DO, 0x00);
    MPU6050_RA_I2C_SLV3_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_DO, 0x00);
    MPU6050_RA_I2C_MST_DELAY_CTRL, //More slave config      LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_MST_DELAY_CTRL, 0x00);
    MPU6050_RA_SIGNAL_PATH_RESET,  //Reset sensor signal paths    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_SIGNAL_PATH_RESET, 0x00);
    MPU6050_RA_MOT_DETECT_CTRL,     //Motion detection control    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_MOT_DETECT_CTRL, 0x00);
    MPU6050_RA_USER_CTRL,                 //Disables FIFO, AUX I2C, FIFO and I2C reset bits to 0    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_USER_CTRL, 0x00);
    MPU6050_RA_CONFIG,                       //Disable FSync, 256Hz DLPF    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_CONFIG, 0x00);
    MPU6050_RA_FF_THR,				   //Freefall threshold of |0mg|    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FF_THR, 0x00);
    MPU6050_RA_FF_DUR,			       //Freefall duration limit of 0    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FF_DUR, 0x00);
    MPU6050_RA_MOT_THR,                 //Motion threshold of 0mg    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_MOT_THR, 0x00);
    MPU6050_RA_MOT_DUR,			    //Motion duration of 0s    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_MOT_DUR, 0x00);
    MPU6050_RA_ZRMOT_THR,	    //Zero motion threshold    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_ZRMOT_THR, 0x00);
    MPU6050_RA_ZRMOT_DUR,      //Zero motion duration threshold    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_ZRMOT_DUR, 0x00);
    MPU6050_RA_FIFO_EN,		    //Disable sensor output to FIFO buffer    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FIFO_EN, 0x00);
    MPU6050_RA_I2C_MST_CTRL,      //AUX I2C setup    //Sets AUX I2C to single master control, plus other config    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_MST_CTRL, 0x00);
    MPU6050_RA_I2C_SLV0_ADDR,    //Setup AUX I2C slaves    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_ADDR, 0x00);
    MPU6050_RA_I2C_SLV0_REG,    //LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_REG, 0x00);
    MPU6050_RA_I2C_SLV0_CTRL,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_CTRL, 0x00);
    MPU6050_RA_I2C_SLV1_ADDR,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_ADDR, 0x00);
    MPU6050_RA_I2C_SLV1_REG,    //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_REG, 0x00);
    MPU6050_RA_I2C_SLV1_CTRL,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_CTRL, 0x00);
    MPU6050_RA_I2C_SLV2_ADDR,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_ADDR, 0x00);
    MPU6050_RA_I2C_SLV2_REG,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_REG, 0x00);
    MPU6050_RA_I2C_SLV2_CTRL,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_CTRL, 0x00);
    MPU6050_RA_I2C_SLV3_ADDR,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_ADDR, 0x00);
    MPU6050_RA_I2C_SLV3_REG,   //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_REG, 0x00);
    MPU6050_RA_I2C_SLV3_CTRL, //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_CTRL, 0x00);
    MPU6050_RA_I2C_SLV4_ADDR, //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_ADDR, 0x00);
    MPU6050_RA_I2C_SLV4_REG,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_REG, 0x00);
    MPU6050_RA_I2C_SLV4_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_DO, 0x00);
    MPU6050_RA_I2C_SLV4_CTRL, //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_CTRL, 0x00);
    MPU6050_RA_I2C_SLV4_DI,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV4_DI, 0x00);
    MPU6050_RA_I2C_SLV0_DO,  //    //Slave out, dont care    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV0_DO, 0x00);
    MPU6050_RA_I2C_SLV1_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV1_DO, 0x00);
    MPU6050_RA_I2C_SLV2_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV2_DO, 0x00);
    MPU6050_RA_I2C_SLV3_DO,  //    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_SLV3_DO, 0x00);
    MPU6050_RA_I2C_MST_DELAY_CTRL,  //More slave config    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_I2C_MST_DELAY_CTRL, 0x00);
    MPU6050_RA_SIGNAL_PATH_RESET,      //Reset sensor signal paths    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_SIGNAL_PATH_RESET, 0x00);
    MPU6050_RA_MOT_DETECT_CTRL,    //Motion detection control    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_MOT_DETECT_CTRL, 0x00);
    MPU6050_RA_USER_CTRL,    //Disables FIFO, AUX I2C, FIFO and I2C reset bits to 0    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_USER_CTRL, 0x00);
    MPU6050_RA_INT_PIN_CFG,    //MPU6050_RA_I2C_MST_STATUS //Read-only    //Setup INT pin and AUX I2C pass through    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_INT_PIN_CFG, 0x00);
    MPU6050_RA_INT_ENABLE,    //Enable data ready interrupt    LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_INT_ENABLE, 0x00);
    MPU6050_RA_FIFO_R_W,       // LDByteWriteI2C(MPU6050_ADDRESS, MPU6050_RA_FIFO_R_W, 0x00);
    0xff
};   
    LDByteWriteI2C(I2CAdd, MPU6050_RA_GYRO_CONFIG, 0b00001000);

   
//    //Sets sample rate to 8000/1+7 = 1000Hz
 //   LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 0x07);
    //Sets sample rate to 8000/1+15 = 500Hz
//    LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 15);
    //Disable gyro self tests, scale of 500 degrees/s
    //Sets sample rate to 8000/1+79 = 100Hz
 //   LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 79);


    //Disable accel self tests, scale of +-16g, no DHPF
 //   LDByteWriteI2C(I2CAdd, MPU6050_RA_ACCEL_CONFIG, 0x18);

    loop=0;
   do
   {
       TheReg = MPU6050RegTable[loop++];
       if(TheReg==0xff) break;
       LDByteWriteI2C(I2CAdd,TheReg,0);
    }while(1);



    //Sets clock source to gyro reference w/ PLL
    LDByteWriteI2C(I2CAdd, MPU6050_RA_PWR_MGMT_1, 0b00000010);
    //Controls frequency of wakeups in accel low power mode plus the sensor standby modes
    LDByteWriteI2C(I2CAdd, MPU6050_RA_PWR_MGMT_2, 0x00);
 
    //MPU6050_RA_WHO_AM_I             //Read-only, I2C address
 LDByteWriteI2C(I2CAdd, MPU6050_RA_INT_ENABLE, 0x01);

 MPU6050_setSampleRate(I2CAdd,_control.sampleRate);
 MPU6050_setScale(I2CAdd,_control.gScale);

//    cputs("\r\nMPU6050 Setup Complete\r\n");
}


void  MPU6050_setSampleRate(unsigned char I2CAdd,unsigned char rate)
{
  
  switch(rate)
  {
    case 0 : // 50Hz (8000/50)= 160
             LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 159);
             break;

    case 1: // 100Hz (8000/100)= 80
             LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 79);
             break;

    case 2: // 200Hz (8000/200)= 40
                LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 39);
             break;

    case 3: // 500Hz (8000/50)= 16
             LDByteWriteI2C(I2CAdd, MPU6050_RA_SMPLRT_DIV, 15);
             break;

  }

}


void  MPU6050_setScale(unsigned char I2CAdd, unsigned char scale)
{
  
   switch(scale)
    {
      case 0 :  // +/- 1G
              LDByteWriteI2C(I2CAdd, MPU6050_RA_ACCEL_CONFIG, 0);
              break;
      case 1 :  // +/- 2G
              LDByteWriteI2C(I2CAdd, MPU6050_RA_ACCEL_CONFIG, 0x08);
              break;
      case 2 :  // +/- 4G
              LDByteWriteI2C(I2CAdd, MPU6050_RA_ACCEL_CONFIG, 0x10);
              break;
      case 3 :  // +/- 8G
              LDByteWriteI2C(I2CAdd, MPU6050_RA_ACCEL_CONFIG, 0x18);
              break;
   }
}



void MPU6050_getValues(unsigned char I2CAdd, MPU6050_dataStruct * Accel)
{
  unsigned char cval[14];
 if(Accel->Valid)
 {
  LDByteReadI2C(I2CAdd, MPU6050_RA_ACCEL_XOUT_H, &cval[0], 14);

  Accel->AccX = (((unsigned short) cval[0]<<8)|cval[1]);
  Accel->AccY = (((unsigned short) cval[2]<<8)|cval[3]);
  Accel->AccZ = (((unsigned short) cval[4]<<8)|cval[5]);
  Accel->Temp = (((unsigned short) cval[6]<<8)|cval[7]);
  Accel->GyroX = (((unsigned short) cval[8]<<8)|cval[9]);
  Accel->GyroY = (((unsigned short) cval[10]<<8)|cval[11]);
  Accel->GyroZ = (((unsigned short) cval[12]<<8)|cval[13]);
 }
  else
{
 Accel->AccX = 0;
  Accel->AccY = 0;
  Accel->AccZ = 0;
  Accel->Temp = 0;
  Accel->GyroX = 0;
  Accel->GyroY = 0;
  Accel->GyroZ = 0;
}  
}




unsigned char MPU6050_gotInterrupt(unsigned char I2CAdd)
{
  unsigned char uc_temp;

   // Do we have a new data

  LDByteReadI2C(I2CAdd,MPU6050_RA_INT_STATUS, &uc_temp, 1);
  return ((uc_temp & 1) == 1 ? 1 : 0);
}	
