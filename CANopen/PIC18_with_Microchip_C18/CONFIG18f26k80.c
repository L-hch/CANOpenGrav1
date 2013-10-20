//-------------------------------------------------------------------------------
//
// User functions
//
//-------------------------------------------------------------------------------


#ifndef __CONFIG__
   #define __CONFIG__

   //----------------------------------------------------------------------
   // Definitie configuratie bits
   //----------------------------------------------------------------------



//   VREG Sleep Enable bit:
//     RETEN = OFF          Disabled - Controlled by SRETEN bit
//     RETEN = ON           Enabled
//

#pragma config RETEN = OFF


//   LF-INTOSC Low-power Enable bit:
//     INTOSCSEL = LOW      LF-INTOSC in Low-power mode during Sleep
//     INTOSCSEL = HIGH     LF-INTOSC in High-power mode during Sleep



//   SOSC Power Selection and mode Configuration bits:
//     SOSCSEL = LOW        Low Power SOSC circuit selected
//     SOSCSEL = DIG        Digital (SCLKI) mode
//     SOSCSEL = HIGH       High Power SOSC circuit selected

#pragma config SOSCSEL = DIG

//   Extended Instruction Set:
//     XINST = OFF          Disabled
//     XINST = ON           Enabled

#pragma config XINST = OFF

//   Oscillator:
//     FOSC = LP            LP oscillator
//     FOSC = XT            XT oscillator
//     FOSC = HS2           HS oscillator (High power, 16 MHz - 25 MHz)
//     FOSC = HS1           HS oscillator (Medium power, 4 MHz - 16 MHz)
//     FOSC = EC3IO         EC oscillator, CLKOUT function on OSC2 (High power, 16 MHz - 64 MHz)
//     FOSC = EC3           EC oscillator (High power, 16 MHz - 64 MHz)
//     FOSC = RC            External RC oscillator, CLKOUT function on OSC2
//     FOSC = RCIO          External RC oscillator
//     FOSC = INTIO2        Internal RC oscillator
//     FOSC = INTIO1        Internal RC oscillator, CLKOUT function on OSC2
//     FOSC = EC2IO         EC oscillator, CLKOUT function on OSC2 (Medium power, 160 kHz - 4 MHz)
//     FOSC = EC2           EC oscillator (Medium power, 160 kHz - 4 MHz)
//     FOSC = EC1IO         EC oscillator, CLKOUT function on OSC2 (Low power, DC - 160 kHz)
//     FOSC = EC1           EC oscillator (Low power, DC - 160 kHz)



#pragma config FOSC= HS1

//   PLL x4 Enable bit:
//     PLLCFG = OFF         Disabled
//     PLLCFG = ON          Enabled

#pragma config PLLCFG = ON

//   Fail-Safe Clock Monitor:
//     FCMEN = OFF          Disabled
//     FCMEN = ON           Enabled
//
//   Internal External Oscillator Switch Over Mode:
//     IESO = OFF           Disabled
//     IESO = ON            Enabled
//

#pragma config IESO = OFF

//   Power Up Timer:
//     PWRTEN = ON          Enabled
//     PWRTEN = OFF         Disabled
//

#pragma config PWRTEN = ON

//   Brown Out Detect:
//     BOREN = OFF          Disabled in hardware, SBOREN disabled
//     BOREN = ON           Controlled with SBOREN bit
//     BOREN = NOSLP        Enabled while active, disabled in SLEEP, SBOREN disabled
//     BOREN = SBORDIS      Enabled in hardware, SBOREN disabled
//

#pragma config BOREN = OFF

//   Brown-out Reset Voltage bits:
//     BORV = 0             3.0V
//     BORV = 1             2.7V
//     BORV = 2             2.0V
//     BORV = 3             1.8V
//

#pragma config BORV = 0

//   BORMV Power level:
//     BORPWR = LOW         BORMV set to low power level
//     BORPWR = MEDIUM      BORMV set to medium power level
//     BORPWR = HIGH        BORMV set to high power level
//     BORPWR = ZPBORMV     ZPBORMV instead of BORMV is selected

#pragma config BORPWR= MEDIUM

//   Watchdog Timer:
//     WDTEN = OFF          WDT disabled in hardware// SWDTEN bit disabled
//     WDTEN = NOSLP        WDT enabled only while device is active and disabled in Sleep mode// SWDTEN bit disabled
//     WDTEN = ON           WDT controlled by SWDTEN bit setting
//     WDTEN = SWDTDIS      WDT enabled in hardware// SWDTEN bit disabled
//
#pragma config WDTEN = ON


//   Watchdog Postscaler:
//     WDTPS = 1            1:1
//     WDTPS = 2            1:2
//     WDTPS = 4            1:4
//     WDTPS = 8            1:8
//     WDTPS = 16           1:16
//     WDTPS = 32           1:32
//     WDTPS = 64           1:64
//     WDTPS = 128          1:128
//     WDTPS = 256          1:256
//     WDTPS = 512          1:512
//     WDTPS = 1024         1:1024
//     WDTPS = 2048         1:2048
//     WDTPS = 4096         1:4096
//     WDTPS = 8192         1:8192
//     WDTPS = 16384        1:16384
//     WDTPS = 32768        1:32768
//     WDTPS = 65536        1:65536
//     WDTPS = 131072       1:131072
//     WDTPS = 262144       1:262144
//     WDTPS = 524288       1:524288
//     WDTPS = 1048576      1:1048576

#pragma config WDTPS = 64

//   ECAN Mux bit:
//     CANMX = PORTC        ECAN TX and RX pins are located on RC6 and RC7, respectively
//     CANMX = PORTB        ECAN TX and RX pins are located on RB2 and RB3, respectively

#pragma config CANMX= PORTB


//   MSSP address masking:
//     MSSPMSK = MSK5       5 bit address masking mode
//     MSSPMSK = MSK7       7 Bit address masking mode
//



//   Master Clear Enable:
//     MCLRE = OFF          MCLR Disabled, RG5 Enabled
//     MCLRE = ON           MCLR Enabled, RG5 Disabled
#pragma config MCLRE= ON
//
//   Stack Overflow Reset:
//     STVREN = OFF         Disabled
//     STVREN = ON          Enabled
//
//   Boot Block Size:
//     BBSIZ0 = BB1K        1K word Boot Block size
//     BBSIZ0 = BB2K        2K word Boot Block size



//   Code Protect 00800-03FFF:
//     CP0 = ON             Enabled
//     CP0 = OFF            Disabled

#pragma config CP0 = ON
//
//   Code Protect 04000-07FFF:
//     CP1 = ON             Enabled
//     CP1 = OFF            Disabled
//

#pragma config CP1 = ON

//   Code Protect 08000-0BFFF:
//     CP2 = ON             Enabled
//     CP2 = OFF            Disabled
//

#pragma config CP2 = ON
//   Code Protect 0C000-0FFFF:
//     CP3 = ON             Enabled
//     CP3 = OFF            Disabled
//
#pragma config CP3 = ON

//   Code Protect Boot:
//     CPB = ON             Enabled
//     CPB = OFF            Disabled
//

#pragma config CPB = OFF

//   Data EE Read Protect:
//     CPD = ON             Enabled
//     CPD = OFF            Disabled
//
#pragma config CPD = OFF

//   Table Write Protect 00800-03FFF:
//     WRT0 = ON            Enabled
//     WRT0 = OFF           Disabled

#pragma config WRT0 = OFF


//   Table Write Protect 04000-07FFF:
//     WRT1 = ON            Enabled
//     WRT1 = OFF           Disabled
//
#pragma config WRT1 = OFF

//   Table Write Protect 08000-0BFFF:
//     WRT2 = ON            Enabled
//     WRT2 = OFF           Disabled

#pragma config WRT2 = OFF

//   Table Write Protect 0C000-0FFFF:
//     WRT3 = ON            Enabled
//     WRT3 = OFF           Disabled

#pragma config WRT3 = OFF

//   Config. Write Protect:
//     WRTC = ON            Enabled
//     WRTC = OFF           Disabled

#pragma config WRTC = OFF

//   Table Write Protect Boot:
//     WRTB = ON            Enabled
//     WRTB = OFF           Disabled

#pragma config WRTB = OFF

//   Data EE Write Protect:
//     WRTD = ON            Enabled
//     WRTD = OFF           Disabled

#pragma config WRTD = OFF

//   Table Read Protect 00800-03FFF:
//     EBRT0 = ON           Enabled
//     EBRT0 = OFF          Disabled

#pragma config EBRT0 = OFF

//   Table Read Protect 04000-07FFF:
//     EBRT1 = ON           Enabled
//     EBRT1 = OFF          Disabled

#pragma config EBRT1 = OFF

//   Table Read Protect 08000-0BFFF:
//     EBRT2 = ON           Enabled
//     EBRT2 = OFF          Disabled
//

#pragma config EBRT2 = OFF

//   Table Read Protect 0C000-0FFFF:
//     EBRT3 = ON           Enabled
//     EBRT3 = OFF          Disabled
//

#pragma config EBRT3 = OFF

//   Table Read Protect Boot:
//     EBRTB = ON           Enabled
//     EBRTB = OFF          Disabled

#pragma config EBRTB = OFF
#endif
// Einde van de headerfile CONFIG.H
