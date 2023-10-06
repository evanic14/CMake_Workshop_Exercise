//
// Created by victor on 5-10-23.
//

#ifndef CMAKE_WORKSHOP_MQTT_LIB_HPP
#define CMAKE_WORKSHOP_MQTT_LIB_HPP

#include <stdint.h>
#include "lwip/apps/mqtt.h"

typedef struct {
    char *buffer_ptr;
    size_t buffer_size;
}recv_buf_t;


err_t pico_mqtt_connect(mqtt_client_t* client, ip_addr_t* server_addr, uint32_t server_port, const char* client_hostname);

err_t pico_mqtt_subscribe(mqtt_client_t* client, const char* topic_name);

err_t pico_mqtt_unsubscribe(mqtt_client_t* client, const char* topic_name);

err_t pico_mqtt_publish(mqtt_client_t* client, const char* topic_name, const char* message, size_t message_size);

err_t pico_set_mqtt_incoming_publish_callback(mqtt_client_t *client, mqtt_incoming_publish_cb_t incoming_publish_cb, mqtt_incoming_data_cb_t incoming_data_cb);

#endif //CMAKE_WORKSHOP_MQTT_LIB_HPP
