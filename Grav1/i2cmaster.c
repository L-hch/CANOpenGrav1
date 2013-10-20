#include <p18cxxx.h>
#include "i2cMaster.h"
#include <delays.h>

// info extract from
// http://www.hobbytronics.co.uk/hi-tech-c-i2c-master


// try to unlock i2c devices  by clocking sck 9 times with sla HIGH
void i2c_Reset(void)
{
/*
  int loop;
   // disable i2c I/O PORTS
  SSPCON1bits.SSPEN=0;

  // SDA has inputs
 TRISCbits.TRISC4=1;
  // SCL has outputs
 TRISCbits.TRISC3=0;

 // now let's clock at 100Khz 9 times
for(loop=0;loop<9;loop++)
  {
   LATCbits.LATC3=1;
   // 100Khz = 10us => (at 32Mhz it is  80 cycle) than 40 cycle up 40 cycle down 
   Delay10TCYx(4);  // use this c18 build in function to delay 40 cycles
   LATCbits.LATC3=0;
   Delay10TCYx(4);  // use this c18 build in function to delay 40 cycles
  }
 // Need to restart i2c because it is now disable
  i2c_Stop();
*/
// i2c_Init();
}
  

 



// Initialise MSSP port. (18F26K80 - other devices may differ)
void i2c_Init(void){

   // Initialise I2C MSSP
   // Master 400KHz
   TRISCbits.TRISC3=1;                    // set SCL  pins as inputs
   TRISCbits.TRISC4=1;                    // set SDA pins as inputs

   SSPCON1 = 0b00101000; 	// I2C enabled, Master mode
   SSPCON2 = 0x00;
   // I2C Master mode, clock = FOSC/(4 * (SSPADD + 1)) 
   SSPADD = 19;    		// 400Khz @ 32Mhz Fosc

 //  SSPSTAT = 0b11000000; 	// Slew rate disabled
   SSPSTAT = 0b00000000;// slew rate on smb bus disable
}

// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait(void){
    while ( ( SSPCON2 & 0x1F ) || ( SSPSTAT & 0x04 ) );
}

// i2c_Start - Start I2C communication
void i2c_Start(void){
    i2c_Wait();
    SSPCON2bits.SEN=1;
}

// i2c_Restart - Re-Start I2C communication
void i2c_Restart(void){
    i2c_Wait();
    SSPCON2bits.RSEN=1;
}


// i2c_Stop - Stop I2C communication
void i2c_Stop(void)
{
    i2c_Wait();
    SSPCON2bits.PEN=1;
}

// i2c_Write - Sends one byte of data
void i2c_Write(unsigned char data)
{
    i2c_Wait();
    SSPBUF = data;
}

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address(unsigned char address, unsigned char mode)
{
    unsigned char l_address;

    l_address=address<<1;
    l_address+=mode;
    i2c_Wait();
    SSPBUF = l_address;
}

// i2c_Read - Reads a byte from Slave device
unsigned char i2c_Read(unsigned char ack)
{
    // Read data from slave
    // ack should be 1 if there is going to be more data read
    // ack should be 0 if this is the last byte of data read
    unsigned char i2cReadData;

    i2c_Wait();
    SSPCON2bits.RCEN=1;
    i2c_Wait();
    i2cReadData = SSPBUF;
    i2c_Wait();
    if ( ack ) SSPCON2bits.ACKDT=0;	        // Ack
    else       SSPCON2bits.ACKDT=1;	        // NAck
    SSPCON2bits.ACKEN=1;                    // send acknowledge sequence
    return( i2cReadData );
}


/*********************************************************************
* Function:        LDByteWriteI2C()
* Input:		Control Byte, 8 - bit address, data.
* Overview:		Write a byte to low density device at address LowAdd
********************************************************************/
void LDByteWriteI2C(unsigned char i2cSlaveAddress, unsigned char LowAdd, unsigned char data)
{
	unsigned int ErrorCode=0;

    i2c_Start();					//Generate Start COndition
    i2c_Address(i2cSlaveAddress,I2CWRITE);
    i2c_Write(LowAdd);	                // Servo Speed 
    i2c_Write(data);	                // 2 seconds on servo 0
    i2c_Stop();	                        // send Stop
}


/*********************************************************************
* Function:        LDByteReadI2C()
* Input:		Control Byte, Address, *Data, Length.
* Overview:		Performs a low density read of Length bytes and stores in *Data array
*				starting at Address.
********************************************************************/
void LDByteReadI2C(unsigned char i2cSlaveAddress, unsigned char Address, unsigned char *Data, unsigned char Length)
{
    unsigned char read_byte;
    i2c_Start();                        // send Start
    i2c_Address(i2cSlaveAddress, I2CWRITE);  // Send slave address - write operation
    i2c_Write(Address);	                // Set register for servo 0
    i2c_Restart();                      // Restart
    i2c_Address(i2cSlaveAddress, I2CREAD);   // Send slave address - read operation	

    while(Length-- > 1)
    *(Data++) = i2c_Read(1);            // Read one byte
    *(Data++) = i2c_Read(0);
    i2c_Stop();
}






