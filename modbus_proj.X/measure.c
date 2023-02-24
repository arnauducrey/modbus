#include <xc.h>

#include "measure.h"
#include "mcc_generated_files/mcc.h"

#define VOLTAGE_CHANNEL 0
#define CURRENT_CHANNEL 1

#define ADC_RESOLUTION  (1024 - 1)
#define ADC_REFH        3300
#define GAIN            66
#define RESISTOR        3

// Number of samples to do the averaging during measures
#define AVERAGE_SAMPLES 8

void adc_init(void)
{
	// TODO -> complete adc initialisation

}

/**
 * Read one ADC channel. This function is only
 * local to this file.
 *
 * @param channel : the channel to be measured
 * @return the ADC read value
 */
static uint16_t measure_adc(uint8_t channel)
{
	// TODO -> complete adc measure
    
    switch(channel)
    {
        case VOLTAGE:
            
            break;
    }
}

uint16_t measure_voltage()
{
	// TODO -> complete measure of voltage
    
        uint32_t result;
        
        for(int i = 0;i < AVERAGE_SAMPLES;i++)
        {
            result +=  ADC_GetConversion(VOLTAGE);
        }
        result/= AVERAGE_SAMPLES;
        
        return (result*ADC_REFH)/ADC_RESOLUTION;
}

uint16_t measure_current(uint16_t offset)
{
	// TODO -> complete measure of current
}