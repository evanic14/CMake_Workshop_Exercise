//
// Created by victor on 5-10-23.
//
#include <string.h>
#include <pico/cyw43_arch.h>
#include "mqtt_lib.hpp"




void mqtt_pub_request_cb(void *arg, err_t err) {
    printf("mqtt_pub_request_cb: err %d\n", err);
}

static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status) {
    if (status != 0) {
        printf("Error during connection: err %d.\n", status);
    } else {
        printf("MQTT connected.\n");
    }
}

void mqtt_sub_cb(void *arg, err_t err) {
    printf("mqtt_sub_request_cb: err %d\n", err);
}

err_t pico_mqtt_connect(mqtt_client_t* client, ip_addr_t* server_addr, uint32_t server_port, const char *client_hostname) {
    struct mqtt_connect_client_info_t ci;

    err_t err;

    memset(&ci, 0, sizeof(ci));

    ci.client_id = client_hostname;
    ci.client_user = NULL;
    ci.client_pass = NULL;
    ci.keep_alive = 0;
    ci.will_topic = NULL;
    ci.will_msg = NULL;
    ci.will_retain = 0;
    ci.will_qos = 0;

    const struct mqtt_connect_client_info_t *client_info = &ci;
    err = mqtt_client_connect(client, server_addr, server_port, mqtt_connection_cb, 0, client_info);
    return err;
}

err_t pico_mqtt_subscribe(mqtt_client_t* client, const char* topic_name) {
    err_t err = mqtt_sub_unsub(client, topic_name, 0, mqtt_sub_cb, 0, 1);
    return err;
}

err_t pico_mqtt_unsubscribe(mqtt_client_t* client, const char* topic_name, mqtt_request_cb_t cb) {
    err_t err = mqtt_sub_unsub(client, topic_name, 0, mqtt_sub_cb, 0, 0);
    return err;
}

err_t pico_mqtt_publish(mqtt_client_t* client, const char* topic_name, const char* message, size_t message_size) {
    err_t err;
    u8_t qos = 0; /* 0 1 or 2, see MQTT specification.  AWS IoT does not support QoS 2 */
    u8_t retain = 0;
    cyw43_arch_lwip_begin();
    err = mqtt_publish(client, topic_name, message, message_size, qos, retain, mqtt_pub_request_cb, 0);
    cyw43_arch_lwip_end();
    return err;
}

err_t pico_set_mqtt_incoming_publish_callback(mqtt_client_t *client, mqtt_incoming_publish_cb_t incoming_publish_cb, mqtt_incoming_data_cb_t incoming_data_cb){
    mqtt_set_inpub_callback(client, incoming_publish_cb, incoming_data_cb, 0);
    return ERR_OK;
}