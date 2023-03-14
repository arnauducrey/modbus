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


uint16_t measure_voltage()
{
    
        uint32_t result = 0;
        
        for(int i = 0;i < AVERAGE_SAMPLES;i++) // make a few sample
        {
            result +=  ADC_GetConversion(VOLTAGE);
        }
        result/= AVERAGE_SAMPLES; // get the mean
        
        return (result*ADC_REFH)/ADC_RESOLUTION; // convert result to mV and return it
}

uint16_t measure_current(uint16_t offset)
{

        uint32_t result = 0;
    
        for(int i = 0;i < AVERAGE_SAMPLES;i++) // make a few sample
        {
            result +=  ADC_GetConversion(CURRENT);
        }
        result/= AVERAGE_SAMPLES; // get the mean
        
        result = (result*ADC_REFH)/ADC_RESOLUTION; // conversion to mV
        
        result *= 1000; // conversion to uV
        
        result /= GAIN;// uV on R11
        
        result /= RESISTOR; // convert to uA
        
        if(result > offset)
        {
            return result-offset; // remove the offset and return value
        }
        return 0; // return 0 if result is below the offset 
}


