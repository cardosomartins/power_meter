#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"


#define PINO_LEITURA_TENSAO 14

void setup(){
    printf("Medição começou!");

}




void app_main(void)
{

    setup();

    while(1){
        unsigned int adc_value;
        adc_value = adc1_get_raw(ADC2_CHANNEL_5);
        // Convert ADC reading to voltage

        float voltage = (adc_value / 4095.0) * 3.3;

        printf("Leitura do sensor: %u \n", adc_value);
        printf("Voltage: %.2f V\n", voltage);   
        vTaskDelay(pdMS_TO_TICKS(1000));
    }



}
