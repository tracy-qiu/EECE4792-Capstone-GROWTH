#include "adc122s021.h"

uint16_t ADC122S021_ReadADC(spi_inst_t* spi, const uint cs, bool channel) {

    uint8_t ctrl_reg_val[2] = {(uint8_t) ((channel ^ 0x01) << 3), 0};
    uint8_t adc_val[2] = {0, 0};
    uint16_t adc_reading;

    gpio_put(cs, false);
    spi_write_read_blocking(spi, ctrl_reg_val, adc_val, 2);
    gpio_put(cs, true);

    adc_reading = (adc_val[0] << 8) + adc_val[1];

    return adc_reading;
}

double ADC122S021_GetVoltage(spi_inst_t* spi, const uint cs, bool channel) {

    double volts = 3.300 * ((double) ADC122S021_ReadADC(spi, cs, channel)) / (double) 4095;

    return volts;
}