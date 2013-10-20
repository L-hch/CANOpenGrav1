CANOpenGrav1
============

  Simple CanOpen module which support 2 MPU6050 devices.
  
  Base source code from sourceforge
    http://sourceforge.net/projects/canopennode/files/canopennode/CANopenNode-1.10/
    
  Base code modified to accept microchip PIC18F26K80.
  
  Also modified to use DIP switch for NodeId
  
  
  Canbus speed is set to 1MBS but could be modified using  ODD_CANbitRat  from CO_OD.h (need recompile).

  Protocol is CanOpen and ,
  
  TPDO_0 send 16bits signed (accelerometer value for X,Y and Z) from MPU6050 unit 1
  TPDO_1 send 16bits signed (Gyroscope value for X,Y, and Z) from MPU6050 unit 1
  TPDO_2 send 16bits signed (accelerometer value for X,Y and Z) from MPU6050 unit 2
  TPDO_3 send 16bits signed (Gyroscope value for X,Y, and Z) from MPU6050 unit 2
  
  RCPD_0 receive Command Control
  
   Bit0..1 ->  Sample rate
               0: 50
               1: 100
               2: 200
               3: 300
               
   Bit2..3 ->  Acceleration Span
               0: +/- 2G
               1: +/- 4G
               2: +/- 8G
               3: +/- 16G
          
   Bit4    ->  Gyro Enable
   
   Bit5    ->  Reload Settings
   
   
   DIP switch Sw-1 (bit 0) to Sw-6 (bit 5)  select the Node ID.
     The real Node ID is an offset from the DIP swicth  + ODD_CANnodeID from CO_OD.H
     
     
           
  This is basically a test bench code to see if it is possible.
  
  One module at 1MBS bus use 10% bandwith if only the Accelerometer values ( 2 MPU6050) are send at 500 Sample/sec Than 7 modules are
  the maximum load possible. If it is 100 Samples/sec than it will be possible to use 35 modules. 
  
  
  
  
