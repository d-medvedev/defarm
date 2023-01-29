/**
 * @Author: Your name
 * @Date:   2023-01-28 16:58:26
 * @Last Modified by:   Dmitry Medvedev
 * @Last Modified time: 2023-01-29 17:54:36
 */
#include "nvs_flash.h"

#include "wifi_app.h"

/**
 * Application entry point
*/
void app_main(void)
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Start WiFi
    wifi_app_start();

}