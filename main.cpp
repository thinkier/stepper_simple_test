#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/gpio.h"

#define ENN_X 12
#define ENN_Y 7
#define ENN_Z 2
#define ENN_E 15

#define STEP_X 11
#define STEP_Y 6
#define STEP_Z 19
#define STEP_E 14

#define DIR_X 10
#define DIR_Y 5
#define DIR_Z 28
#define DIR_E 13

int main() {
    stdio_init_all();

    gpio_init(ENN_X);
    gpio_init(ENN_Y);
    gpio_init(ENN_Z);
    gpio_init(ENN_E);
    gpio_set_dir(ENN_X, GPIO_OUT);
    gpio_set_dir(ENN_Y, GPIO_OUT);
    gpio_set_dir(ENN_Z, GPIO_OUT);
    gpio_set_dir(ENN_E, GPIO_OUT);
    gpio_pull_down(ENN_X);
    gpio_pull_down(ENN_Y);
    gpio_pull_down(ENN_Z);
    gpio_pull_down(ENN_E);

    gpio_init(DIR_X);
    gpio_init(DIR_Y);
    gpio_init(DIR_Z);
    gpio_init(DIR_E);
    gpio_set_dir(DIR_X, GPIO_OUT);
    gpio_set_dir(DIR_Y, GPIO_OUT);
    gpio_set_dir(DIR_Z, GPIO_OUT);
    gpio_set_dir(DIR_E, GPIO_OUT);
    gpio_pull_down(DIR_X);
    gpio_pull_down(DIR_Y);
    gpio_pull_down(DIR_Z);
    gpio_pull_down(DIR_E);

    gpio_init(STEP_X);
    gpio_init(STEP_Y);
    gpio_init(STEP_Z);
    gpio_init(STEP_E);
    gpio_set_dir(STEP_X, GPIO_OUT);
    gpio_set_dir(STEP_Y, GPIO_OUT);
    gpio_set_dir(STEP_Z, GPIO_OUT);
    gpio_set_dir(STEP_E, GPIO_OUT);

    while (true) {
        gpio_pull_up(STEP_X);
        gpio_pull_up(STEP_Y);
        gpio_pull_up(STEP_Z);
        gpio_pull_up(STEP_E);
        sleep_ms(5);

        gpio_pull_down(STEP_X);
        gpio_pull_down(STEP_Y);
        gpio_pull_down(STEP_Z);
        gpio_pull_down(STEP_E);
        sleep_ms(5);
    }
}
