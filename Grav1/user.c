/*******************************************************************************

   User functions

*******************************************************************************/

#include "CANopen.h"
#include <i2c.h>
#include <delays.h>
#include "mpu6050.h"
// Timer
unsigned short Timersec;
unsigned short Timerms;
unsigned char SecFlag;
unsigned char I2CStartupDelay;


// let`s reset flash data
#pragma romdata eedata_scn=0xf00000
  rom sODE_EEPROM  rom_flash={0,0};
 #pragma romdata





void  User_PrepareTPDO(unsigned char i);



#ifdef CANnodeID_ON_SWITCH

/******************************************************************************
  ReadDipSwitches()
  Function is called to get Node Id  from DIP switches attached to RC0..RC7  except RC3 and RC4 (i2C)
  node from 1 to 65 will be return
  bit 0..2 ->  RC0.. RC2  bit 3..5 -> RC5.. RC7
 ******************************************************************************/
  unsigned char ReadDipSwitches(void)
  {
     unsigned char _temp;
      
     // port on input mode
     TRISCbits.TRISC0=1;
     TRISCbits.TRISC1=1;
     TRISCbits.TRISC1=1;
     // PORTA
     TRISAbits.TRISA2=1;
     TRISAbits.TRISA3=1;
     TRISAbits.TRISA5=1;

     // wait a little to stabilize the pins      
     Delay10TCYx( 5 );  // 50 clock cycle
     
     // let's read the node 
     _temp = PORTC & 0x07; // RC0..RC3

     if(PORTAbits.RA2==1)
      _temp |= 0x08;

     if(PORTAbits.RA3==1)
      _temp |= 0x10;

     if(PORTAbits.RA5==1)
      _temp |= 0x20;

     _temp += ODD_CANnodeID;
     return(_temp);
  } 
 #endif




/*******************************************************************************
   User_Init - USER INITIALIZATION OF NODE
   Function is called after start of program.
*******************************************************************************/
void User_Init(void){
 ADCON1 =0x0;  // disable analog
 ANCON0 = 0;
 
 ODE_EEPROM.PowerOnCounter++;
 Timersec=0;
 Timerms=0;
 SecFlag=0;
 
  // PORTB0 PORTB1 output (device led info)

 TRISBbits.TRISB0 = 0;
 TRISBbits.TRISB1 = 0;
 

 I2CStartupDelay=5;  // put 10 seconds for I2C startup 
 i2c_Init();
 MPU6050_reset();
}

/*******************************************************************************
   User_Remove - USER EXECUTION ON EXIT OF PROGRAM
   Function is called before end of program. Not used in PIC.
*******************************************************************************/
void User_Remove(void){

}

/*******************************************************************************
   User_ResetComm - USER RESET COMMUNICATION
   Function is called after start of program and after CANopen NMT command: Reset
   Communication.
*******************************************************************************/
void User_ResetComm(void){
MPU6050_reset();
}


/*******************************************
  Check Accelerometers
*******************************************/
void CheckAccelerometers(void)
{

     if(MPU6050_device1Data.Valid)
       {
         //ok device valid. Do we have new data
         if(MPU6050_gotInterrupt(MPU6050_ADDRESS1))
          {
            // get accelerometer1 values
            MPU6050_getValues(MPU6050_ADDRESS1,&MPU6050_device1Data);  // read accelerometer1 sensor
            User_PrepareTPDO(0);		              // Fill TPDO_0 buffer with data
            CO_TPDOsend(0);                              // Set TPDO_0 buffer Flag to ready to transmit
            if(ODE_EEPROM.MPU6050_control.gyroEnable)
             {
               User_PrepareTPDO(1);                        // Fill TPDO_1 buffer with data
               CO_TPDOsend(1);                              // Set TPDO_1 buffer Flag to ready to transmit
             }
          }
        }
       else
        {
           // ok not valid yet! Just check if we are able to locate the device
           if(MPU6050_isFound(MPU6050_ADDRESS1))
             {
               // ok we got it! let's Initiate it
               MPU6050_setup(MPU6050_ADDRESS1, ODE_EEPROM.MPU6050_control);
               MPU6050_device1Data.Valid=1;    // it is valid now
               setDevice1LED(1);
             }
           }
      
     // now the second accelerometer
     
     if(MPU6050_device2Data.Valid)
       {
         //ok device valid. Do we have new data
         if(MPU6050_gotInterrupt(MPU6050_ADDRESS2))
          {
            // get accelerometer1 values
            MPU6050_getValues(MPU6050_ADDRESS2,&MPU6050_device2Data);  // read accelerometer1 sensor
            User_PrepareTPDO(2);		              // Fill TPDO_0 buffer with data
            CO_TPDOsend(2);                              // Set TPDO_0 buffer Flag to ready to transmit
            if(ODE_EEPROM.MPU6050_control.gyroEnable)
             {
               User_PrepareTPDO(3);                        // Fill TPDO_1 buffer with data
               CO_TPDOsend(3);                              // Set TPDO_1 buffer Flag to ready to transmit
             }
          }
        }
       else
        {
           // ok not valid yet! Just check if we are able to locate the device
           if(MPU6050_isFound(MPU6050_ADDRESS2))
             {
               // ok we got it! let's Initiate it
               MPU6050_setup(MPU6050_ADDRESS2,ODE_EEPROM.MPU6050_control);
               MPU6050_device2Data.Valid=1;    // it is valid now
               setDevice2LED(1);
             }
           
       }


}


/*******************************************************************************
   User_ProcessMain - USER PROCESS MAINLINE
   This function is cyclycally called from main(). It is non blocking function.
   It is asynchronous. Here is longer and time consuming code.
*******************************************************************************/
void User_ProcessMain(void){
  MPU6050_controlUnion   _control;  
  if(I2CStartupDelay>0) 
   {
     //check for   end of startup delay
     if(SecFlag)
        {
         I2CStartupDelay--;
     
        SecFlag=0;
  
      }
   }
  else
   {
     // ok startup delay done
    CheckAccelerometers();  // process the accelerometers sensors
    }

  //let's check RPDO_0

if(CO_RPDO_New(0)){  
        CO_DISABLE_CANRX_TMR();
        _control.value=CO_RPDO(0).BYTE[0];
        CO_RPDO_New(0) = 0;
        CO_ENABLE_CANRX_TMR();
  
   // Do we have to reload default
     if(_control.reloadSetting)
      { 
        ODE_EEPROM.MPU6050_control = _control;
        if(MPU6050_device1Data.Valid)
          MPU6050_setup(MPU6050_ADDRESS1,ODE_EEPROM.MPU6050_control);
        if(MPU6050_device2Data.Valid)
          MPU6050_setup(MPU6050_ADDRESS2,ODE_EEPROM.MPU6050_control);
      }
      if(_control.sampleRate != ODE_EEPROM.MPU6050_control.sampleRate)
      {
         //Sample Rate Different .  Need to be change
         if(MPU6050_device1Data.Valid)
          MPU6050_setSampleRate(MPU6050_ADDRESS1, _control.sampleRate);
         if(MPU6050_device2Data.Valid)
          MPU6050_setSampleRate(MPU6050_ADDRESS2, _control.sampleRate);
      }     
      if(_control.gScale != ODE_EEPROM.MPU6050_control.gScale)
      {
         if(MPU6050_device1Data.Valid)
          MPU6050_setScale(MPU6050_ADDRESS1, _control.gScale);
         if(MPU6050_device2Data.Valid)
          MPU6050_setScale(MPU6050_ADDRESS2, _control.gScale);
       }
     ODE_EEPROM.MPU6050_control.value = _control.value;
     ODE_EEPROM.MPU6050_control.reloadSetting = 0; // single shot just remove flag
   }  
 
}

/*******************************************************************************
   User_Process1msIsr - 1 ms USER TIMER FUNCTION
   Function is executed every 1 ms. It is deterministic and has priority over
   mainline functions.
*******************************************************************************/
void User_Process1msIsr(void){
    Timerms++;

  if(Timerms>=1000)
   {
     Timerms=0;
     Timersec++;
     SecFlag=1;
  }
//  LATBbits.LATB0= Timerms > 500 ? 1 : 0;
}


/******************************************************************
 User_PrepareTPDO(unsigned char i)

  // automatically called by CO_TXCANSend in main.c
  // patch addon  line 574 and 594

manipulate info to be send correctly;
******************************************************************/

// TPDO  Accelerometer1 Acceleration data
void  PrepareTPDO_0(void)
{
	CO_DISABLE_ALL();
	CO_TPDO(0).WORD[0] =  MPU6050_device1Data.AccX;
	CO_TPDO(0).WORD[1] =  MPU6050_device1Data.AccY;
	CO_TPDO(0).WORD[2] =  MPU6050_device1Data.AccZ;
	CO_ENABLE_ALL();
}

// TPDO Accelerometer1  Gyro data
void  PrepareTPDO_1(void)
{
	CO_DISABLE_ALL();
	CO_TPDO(1).WORD[0] =  MPU6050_device1Data.GyroX;
	CO_TPDO(1).WORD[1] =  MPU6050_device1Data.GyroY;
	CO_TPDO(1).WORD[2] =  MPU6050_device1Data.GyroZ;
	CO_ENABLE_ALL();
}

// TPDO Accelerometer2 Acceleration data
void  PrepareTPDO_2(void)
{
	CO_DISABLE_ALL();
	CO_TPDO(2).WORD[0] =  MPU6050_device2Data.AccX;
	CO_TPDO(2).WORD[1] =  MPU6050_device2Data.AccY;
	CO_TPDO(2).WORD[2] =  MPU6050_device2Data.AccZ;
	CO_ENABLE_ALL();
}

// TPDO Accelerometer2  Gyro data
void  PrepareTPDO_3(void)
{
	CO_DISABLE_ALL();
	CO_TPDO(3).WORD[0] =  MPU6050_device2Data.GyroX;
	CO_TPDO(3).WORD[1] =  MPU6050_device2Data.GyroY;
	CO_TPDO(3).WORD[2] =  MPU6050_device2Data.GyroZ;
	CO_ENABLE_ALL();
}


 
#ifdef __LARGE__
#pragma   MSG_LARGE_MODEL
#define  ROMVOID far rom void
#endif

#ifdef __SMALL__
#pragma   MSG_SMALL_MODEL
#define  ROMVOID rom void 
#endif



rom const void (* far rom PrepareTable[])(void)=
{
  (ROMVOID *) 	PrepareTPDO_0,
  (ROMVOID *)	PrepareTPDO_1,
  (ROMVOID *)	PrepareTPDO_2,
  (ROMVOID *)   PrepareTPDO_3  
};

void  User_PrepareTPDO(unsigned char i)
{
   if(i<4)
   (*PrepareTable[i])();
}