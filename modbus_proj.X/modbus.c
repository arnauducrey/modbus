#include "modbus.h"
#include "crc.h"
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "mcc_generated_files/mcc.h"
// Modbus functions
#define READ_INPUT_REGISTERS    0x04
#define READ_HOLDING_REGISTERS  0x03
#define WRITE_SINGLE_REGISTER   0x06

// Modbus data model
uint8_t modbusAddress;
uint16_t input_registers[2];//voltage, current
uint16_t holding_registers[2];// zcontrol, addressSet

// Modbus error codes
#define ILLEGAL_FUNCTION		1
#define ILLEGAL_DATA_ADDRESS	2
#define ILLEGAL_DATA_VALUE		3
#define SLAVE_DEVICE_FAILURE	4

/**
 * Buffers for serial receive and send operations 
 * which are more than one byte long
 **/
uint8_t rx_buf[256];
uint8_t tx_buf[256];
uint8_t index = 0;
// Current position pointer for storing receive position
uint8_t recPtr = 0;

void modbus_timer(void)
{
    modbus_send(modbus_analyse_and_answer()); // analise and answer
    index = 0; //reset the index of rx_buff
}

uint8_t modbus_analyse_and_answer(void)
{
    if(holding_registers[1] == rx_buf[0])
    {
        // TODO -> complete the modbus analyse and answer
        //verify CRC
        uint16_t crc = rx_buf[index-1];
        //crc *= 256;
        crc = crc << 8;
        crc += rx_buf[index-2];
        uint16_t crcAtt = CRC16(rx_buf,index-2);
        if(crc == crcAtt){
            
            //Decript msg
            /*switch case :
             *0x04 read input register(VOLTAGE CURRENT)
             * 0x06 write holding register PWM
            */
            uint8_t functionCode = rx_buf[1];
            uint16_t startingAddress = 0;
            uint16_t nbofRegister = 0;
            uint16_t pwmValue = 0;
            tx_buf[0] = 0x80;//Address of destination
            switch (functionCode){
                case 0x04:
                    
                    //Decrypting the msg
                    startingAddress = rx_buf[2];
                    startingAddress = startingAddress << 8;
                    startingAddress += rx_buf[3];
                    nbofRegister = rx_buf[4];
                    nbofRegister <<= 8;
                    nbofRegister += rx_buf[5];
                    //Encrypting the answer
                    tx_buf[1] = 0x04; // Function cod
                    tx_buf[2] = 2*nbofRegister; // Byte count
                    //Value asked by the user
                    for(int i = 0;i < nbofRegister;i++)
                    {
                        //I*2 because we have to jump by two for each iteration (16bits goes into two time 8bits)
                        tx_buf[3+(i*2)] = (input_registers[startingAddress + i]>>8);// Register the 8 msb  
                        tx_buf[3+(i*2)+1] = input_registers[startingAddress + i]; // register the 8 lsb         
                    }
                    //Calculate the crc of the answer
                    crc = CRC16(tx_buf,nbofRegister*2+3);
                    tx_buf[nbofRegister*2+3] = crc;
                    crc >>= 8;
                    tx_buf[nbofRegister*2+4] = crc;
                    return nbofRegister*2+5;
                    break;
                case 0x06:
                    //Decrypting the msg
                    startingAddress = rx_buf[2];
                    startingAddress = startingAddress << 8;
                    startingAddress += rx_buf[3];
                    pwmValue = rx_buf[4];
                    pwmValue <<= 8;
                    pwmValue += rx_buf[5];
                    holding_registers[0] = pwmValue; //Store the new pwm value
                    //Encrypting the answer
                    for (int i = 0; i < 7; i++){
                        tx_buf[i+1] = rx_buf[i+1];
                    }
                    return 8;//return the size of rx_buf
                    break;
                default:
                    break;
            }
            //Encrypte answer in tx_buff
            //return answer size
            
            
            /*if(functionCode != 0)
            {
            functionCode = 0;
            crcAtt=0;
            }*/

        }
    }
}

void modbus_char_recvd(uint8_t c)
{
	// TODO -> complete modbus char receive 
    TMR0ON = 1; // restart timer
    rx_buf[index] = c;
    index ++;
}

void modbus_send(uint8_t length)
{
	uint16_t temp16; 
	uint8_t i;

	// TODO -> complete modbus RCR calculation
	//length += 2; // add 2 CRC bytes for total size

	// For all the bytes to be transmitted
    for(int i = 0; i < length; i++){
        EUSART1_Write(tx_buf[i]);
    }
  
}

void modbus_init(uint8_t address)
{
	modbusAddress = address;
  // TODO -> configute timer for modbus usage
}