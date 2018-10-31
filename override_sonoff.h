#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is inlcuded
#warning **** user_config_override.h: Using settings override with flavour "sonoff"

/*********************************************************************************************\
 * SECTION 1
 * - After initial load any change here only take effect if CFG_HOLDER is changed too
\*********************************************************************************************/

// -- Wifi ----------------------------------------

#undef  STA_SSID1
#define STA_SSID1              "{{ env "WIFI_SSID" }}"  // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1              "{{ env "WIFI_PASS" }}"  // [Password1] Wifi password

// -- Ota -----------------------------------------
#undef  OTA_URL
#define OTA_URL                "{{ env "OTA_URL" }}"    // [OtaUrl]

// -- MQTT ----------------------------------------
#undef  MQTT_HOST
#define MQTT_HOST              "{{ env "MQTT_HOST" }}"  // [MqttHost]

#undef  MQTT_USER
#define MQTT_USER              "{{ env "MQTT_USER" }}"  // [MqttUser] MQTT user

#undef  MQTT_PASS
#define MQTT_PASS              "{{ env "MQTT_PASS" }}"  // [MqttPassword] MQTT password

// -- MQTT topics ---------------------------------
// %topic% token options (also ButtonTopic and SwitchTopic)
#undef  MQTT_TOPIC
#define MQTT_TOPIC             "unconfigured"    // [Topic] (unique) MQTT device topic, set to 'PROJECT "_%06X"' for unique topic including device MAC address

// -- MQTT - Telemetry ----------------------------
#undef  TELE_PERIOD
#define TELE_PERIOD            30                // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)

// -- Time - Up to three NTP servers in your region
#undef  NTP_SERVER1
#define NTP_SERVER1            "ptbtime1.ptb.de"    // [NtpServer1] Select first NTP server by name or IP address (129.250.35.250)

#undef  NTP_SERVER2
#define NTP_SERVER2            "ptbtime2.ptb.de"    // [NtpServer2] Select second NTP server by name or IP address (5.39.184.5)

// -- Location ------------------------------------
#undef  LATITUDE
#define LATITUDE               53.58328          // [Latitude] Your location to be used with sunrise and sunset

#undef  LONGITUDE
#define LONGITUDE              9.71719           // [Longitude] Your location to be used with sunrise and sunset

/*********************************************************************************************\
 * END OF SECTION 1
 *
 * SECTION 2
 * - Enable a feature by removing both // in front of it
 * - Disable a feature by preceding it with //
\*********************************************************************************************/

// -- MQTT - Domoticz -----------------------------
#undef  USE_DOMOTICZ                             // Enable Domoticz (+6k code, +0.3k mem)

// -- MQTT - Home Assistant Discovery -------------
#undef  USE_HOME_ASSISTANT                       // Enable Home Assistant Discovery Support (+2k code)

// -- HTTP ----------------------------------------
  #undef  USE_EMULATION                          // Enable Belkin WeMo and Hue Bridge emulation for Alexa (+16k code, +2k mem)

// -- Time ----------------------------------------
#undef  USE_TIMERS                               // Add support for up to 16 timers (+2k2 code)

// -- Rules ---------------------------------------
#undef  USE_RULES                                // Add support for rules (+4k4 code)

// -- Internal Analog input -----------------------
#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

// -- One wire sensors ----------------------------
                                                 // WARNING: Select none for default one DS18B20 sensor or enable one of the following two options for multiple sensors
//#define USE_DS18x20_LEGACY                       // Optional for more than one DS18x20 sensors with dynamic scan using library OneWire (+1k5 code)
#undef  USE_DS18x20                              // Optional for more than one DS18x20 sensors with id sort, single scan and read retry (+1k3 code)
//  #define W1_PARASITE_POWER                      // If using USE_DS18x20 then optimize for parasite powered sensors

// -- Serial sensors ------------------------------
#undef  USE_MHZ19                                // Add support for MH-Z19 CO2 sensor (+2k code)
#undef  USE_SENSEAIR                             // Add support for SenseAir K30, K70 and S8 CO2 sensor (+2k3 code)
#undef  USE_PMS5003                              // Add support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
#undef  USE_NOVA_SDS                             // Add support for SDS011 and SDS021 particle concentration sensor (+0k7 code)
#undef  USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+0k8 code)
#undef  USE_TUYA_DIMMER                          // Add support for Tuya Serial Dimmer

// Power monitoring sensors -----------------------
#undef  USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef  USE_PZEM_AC                              // Add support for PZEM014,016 Energy monitor (+1k1 code)
#undef  USE_PZEM_DC                              // Add support for PZEM003,017 Energy monitor (+1k1 code)
#undef  USE_MCP39F501                            // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)

// -- Low level interface devices -----------------
#undef  USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 and ArduinoJson (+4k code, 0k3 mem, 48 iram)
#undef  USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
#undef  USE_ARILUX_RF                            // Add support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef  USE_SR04                                 // Add support for HC-SR04 ultrasonic devices (+1k code)
#undef  USE_HX711                                // Add support for HX711 load cell (+1k5 code)
#undef  USE_RF_FLASH                             // Add support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB (+3k code)
#undef  USE_TX20_WIND_SENSOR                     // Add support for La Crosse TX20 anemometer (+2k code)
#undef  USE_RC_SWITCH                            // Add support for RF transceiver using library RcSwitch (+2k7 code, 460 iram)


#endif  // _USER_CONFIG_OVERRIDE_H_
