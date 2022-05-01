#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void vtask_blink_led(void *pvParameters) {
    //Setup the GPIO
    gpio_pad_select_gpio(2);
    gpio_set_direction(2, GPIO_MODE_OUTPUT);

    printf("Task em execução...\n");

    int counter = 0;

    for(;;) {
        gpio_set_level(2, (counter % 2));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        counter++;
    }
}

void app_main() {
    xTaskCreate(vtask_blink_led, "blink_led", 2048, NULL, 5, NULL);
    printf("Task criadas com sucesso!\n");
}