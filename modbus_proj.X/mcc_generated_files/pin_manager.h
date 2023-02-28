/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F97J60
        Version           :  2.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB             :  MPLAB X 6.00

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RC2 procedures
#define RC2_SetHigh()               do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()                do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()                do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()       do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()      do { TRISCbits.TRISC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()                do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)

// get/set VOLTAGE aliases
#define VOLTAGE_TRIS                 TRISFbits.TRISF0
#define VOLTAGE_LAT                  LATFbits.LATF0
#define VOLTAGE_PORT                 PORTFbits.RF0
#define VOLTAGE_ANS                  anselRF0bits.anselRF0
#define VOLTAGE_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define VOLTAGE_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define VOLTAGE_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define VOLTAGE_GetValue()           PORTFbits.RF0
#define VOLTAGE_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define VOLTAGE_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define VOLTAGE_SetAnalogMode()      do { anselRF0bits.anselRF0 = 1; } while(0)
#define VOLTAGE_SetDigitalMode()     do { anselRF0bits.anselRF0 = 0; } while(0)

// get/set CURRENT aliases
#define CURRENT_TRIS                 TRISFbits.TRISF1
#define CURRENT_LAT                  LATFbits.LATF1
#define CURRENT_PORT                 PORTFbits.RF1
#define CURRENT_ANS                  anselRF1bits.anselRF1
#define CURRENT_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define CURRENT_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define CURRENT_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define CURRENT_GetValue()           PORTFbits.RF1
#define CURRENT_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define CURRENT_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define CURRENT_SetAnalogMode()      do { anselRF1bits.anselRF1 = 1; } while(0)
#define CURRENT_SetDigitalMode()     do { anselRF1bits.anselRF1 = 0; } while(0)


/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/