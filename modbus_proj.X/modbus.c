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
	// TODO -> complete what to do on modbus timer event
    modbus_send(modbus_analyse_and_answer()); // analise and answer
    index = 0; //reset the index of rx_buff
}

uint8_t modbus_analyse_and_answer(void)
{
	// TODO -> complete the modbus analyse and answer
    //verify CRC
    uint16_t crc = rx_buf[index];
    crc << 8;
    crc += rx_buf[index-1];
    uint16_t crcAtt = CRC16(rx_buf,index);
    if(crc == crcAtt){
    //Decript msg
    //Encrypte answer in tx_buff
    //return answer size
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
	length += 2; // add 2 CRC bytes for total size

	// For all the bytes to be transmitted
  EUSART1_Write(tx_buf[0]);
}

void modbus_init(uint8_t address)
{
	modbusAddress = address;
  // TODO -> configute timer for modbus usage
}