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

#pragma once

#include <autoconf.h>
#include <avsystem/commons/avs_log.h>

#define CLIENT_VERSION "21.10.1"

#define DEFAULT_LOG_LEVEL AVS_LOG_INFO

#ifdef CONFIG_WIFI
#    define WIFI_SSID "ssid"

#    define WIFI_PASSWORD "password"
#endif // CONFIG_WIFI

#define SERVER_URI "coaps://try-anjay.avsystem.com:5684"

#define PSK_KEY "psk"

#define BOOTSTRAP "n"

#ifdef CONFIG_ANJAY_CLIENT_GPS_NRF
#    define GPS_NRF_PRIO_MODE_TIMEOUT "300"

#    define GPS_NRF_PRIO_MODE_COOLDOWN "1800"
#endif // CONFIG_ANJAY_CLIENT_GPS_NRF

#define NTP_SERVER "time.nist.gov"
