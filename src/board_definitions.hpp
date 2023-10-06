#ifndef BOARD_DEFINITIONS_HPP
#define BOARD_DEFINITIONS_HPP

/**
 * Fill in your group-name here!
 * Everything has to be lower case and fit in 400 characters!
 */
const char *group_name = "<Emiel-Mark-Tim>";

/**
 * Add custom phrase for requesting the price!
 * Can be anything..
 * Leave at default if you're out of creativity ;)
 */
const char *winning_phrase = "honk!";


/**
 * Fill in the Wifi details
 */
#define WIFI_SSID "<cmake_demonstration>"
#define WIFI_PASSWORD "<demopassword!>"


/**
 * Leave these settings as-is. These are set correctly for rpi zero
 */
#define MQTT_SERVER_IP PP_HTONL(LWIP_MAKEU32(192,168,0,10))
#define MQTT_SERVER_PORT 1883


#endif