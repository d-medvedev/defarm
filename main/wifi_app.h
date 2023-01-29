/**
 * @Author: Dmitry Medvedev
 * @Date:   2023-01-28 20:57:45
 * @Last Modified by:   Dmitry Medvedev
 * @Last Modified time: 2023-01-29 17:41:20
 */
#ifndef __WIFI_APP_H__
#define __WIFI_APP_H__

#include "esp_netif.h"

// WiFI application settings
#define WIFI_AP_SSID            "BIOLOGICA_AP"  // AP name
#define WIFI_AP_PASSWORD        "password"      // AP password
#define WIFI_AP_CHANNEL         1               // AP cnannel
#define WIFI_AP_SSID_HIDDEN     0               // AP visibility
#define WIFI_AP_MAX_CONNECTIONS 5               // AP max clients 
#define WIFI_AP_BEACON_INTERVAL 100             // AP beacon: 100 recommended
#define WIFI_AP_IP              "192.168.0.1"   // AP default IP
#define WIFI_AP_GATEWAY         "192.168.0.1"   // AP default Gatewate (should be the same as IP)
#define WIFI_AP_NETMASK         "255.255.255.1" // AP netmask
#define WIFI_AP_BANDWIDTH       WIFI_BW_HT20    // AP bandwidth 20 MHz (40 MHz is the other option)
#define WIFI_STA_POWER_SAVE     WIFI_PS_NONE    // Power save not used
#define MAX_SSID_LENGTH         32              // IEEE standard maximum
#define MAX_PASSWORD_LENGTH     64              // IEEE standard maximum
#define MAX_CONNECTION_RETRIES  5               // Retry number on disconnect

// netif object for the Station and Access Poitn
extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;

/**
* Message IDs for the WiFi applicaton task
* @note Expand this based on your application requirements
*/
typedef enum wifi_app_message {
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP,

} wifi_app_message_e;

/**
 * Structure for the message queue
 * @note Expand this based on application requirements e.g. add another type and parameter as required
*/

typedef struct wifi_app_queue_message {
    wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/**
 * Sends a message to the queue
 * @param msgID message ID from the wifi_app_message_e enum
 * @return pdTRUE if an item was successfully sent to the queue, otherwise pdFALSE
 * @note Expand the parameter list based on your requirements e.g. how you're expanded the wifi_app_queue_message_t.
*/
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

typedef struct _wifi_app
{

}wifi_app_t;

#endif /* __WIFI_APP_H__ */

/**
 * Starts the WiFi RTOS task
*/
void wifi_app_start(void);