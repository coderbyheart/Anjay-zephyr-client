/*
 * Copyright 2020-2021 AVSystem <avsystem@avsystem.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "status_led.h"

#include <devicetree.h>
#include <drivers/gpio.h>

#include <avsystem/commons/avs_log.h>

#if STATUS_LED_AVAILABLE
#    define STATUS_LED_GPIO_PORT DT_GPIO_CTLR(STATUS_LED_NODE, gpios)
#    define STATUS_LED_GPIO_PIN DT_GPIO_PIN(STATUS_LED_NODE, gpios)
#    define STATUS_LED_GPIO_FLAGS \
        (GPIO_OUTPUT_INACTIVE | DT_GPIO_FLAGS(STATUS_LED_NODE, gpios))

static const struct device *STATUS_LED_DEVICE =
        DEVICE_DT_GET(STATUS_LED_GPIO_PORT);

void status_led_init(void) {
    if (!device_is_ready(STATUS_LED_DEVICE)
            || gpio_pin_configure(STATUS_LED_DEVICE, STATUS_LED_GPIO_PIN,
                                  STATUS_LED_GPIO_FLAGS)) {
        STATUS_LED_DEVICE = NULL;
        avs_log(status_led, WARNING, "failed to initialize status led");
    }
}

static void status_led_set(int value) {
    if (STATUS_LED_DEVICE) {
        gpio_pin_set(STATUS_LED_DEVICE, STATUS_LED_GPIO_PIN, value);
    }
}

void status_led_on(void) {
    status_led_set(1);
}

void status_led_off(void) {
    status_led_set(0);
}

void status_led_toggle(void) {
    if (STATUS_LED_DEVICE) {
        gpio_pin_toggle(STATUS_LED_DEVICE, STATUS_LED_GPIO_PIN);
    }
}
#else  // STATUS_LED_AVAILABLE
void status_led_init(void) {}

void status_led_on(void) {}

void status_led_off(void) {}

void status_led_toggle(void) {}
#endif // STATUS_LED_AVAILABLE
