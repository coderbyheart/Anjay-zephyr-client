# Copyright 2020-2021 AVSystem <avsystem@avsystem.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(anjay_zephyr_demo)
set(root_dir ${ANJAY_ZEPHYR_CLIENT_DIR})

set(app_common_sources
    src/main.c
    src/anjay_shell.c
    src/status_led.c
    src/status_led.h
    src/common.h
    src/config.c
    src/config.h
    src/utils.c
    src/utils.h
    src/gps.h
    src/default_config.h
    src/objects/objects.h
    src/objects/device.c
    src/objects/location.c
    src/objects/push_button.c
    src/objects/switch.c
    src/objects/basic_sensors.c
    src/objects/three_axis_sensors.c
    src/objects/buzzer.c
    src/objects/led_color_light.c)

if(CONFIG_ANJAY_CLIENT_GPS_NRF)
    target_sources(app PRIVATE
                   ${app_common_sources}
                   src/gps_impl/gps_nrf.c)
else()
    target_sources(app PRIVATE
                   ${app_common_sources})
endif()
