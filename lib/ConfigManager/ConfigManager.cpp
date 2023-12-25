#include "ConfigManager.h"

ConfigManager::ConfigManager(const char* filename) {
    this->filename = filename;
}

ConfigManager::ConfigManager() {
    this->filename = DEFAULT_CONFIG_FILE;
}

ConfigManager::~ConfigManager() {
    free(this->config.mqtt.host);
    free(this->config.mqtt.username);
    free(this->config.mqtt.password);
    free(this->config.mqtt.topic);

    free(this->config.system.ntp);

    free(this->config.smtp.host);
    free(this->config.smtp.email);
    free(this->config.smtp.password);
    free(this->config.smtp.recipient);

    free(this->config.wifi.ssid);
    free(this->config.wifi.password);
}

void ConfigManager::load_config() {
    // open file
    File file = LittleFS.open(this->filename, "r");

    // check if file exists
    if (!file) {
        Serial.println("Config file not found!");
        return;
    }

    StaticJsonDocument<JSON_BUFFER_SIZE> doc;

    DeserializationError error = deserializeJson(doc, file);

    // check if file is valid json
    if (error) {
        Serial.println("Config file is not valid json!");
        file.close();
        return;
    }

    // wifi config
    strcpy(this->config.wifi.ssid, doc["wifi"]["ssid"]);
    strcpy(this->config.wifi.password, doc["wifi"]["password"]);

    // mqtt config
    this->config.mqtt.enabled = doc["mqtt"]["enabled"];
    strcpy(this->config.mqtt.host, doc["mqtt"]["host"]);
    this->config.mqtt.port = doc["mqtt"]["port"];
    strcpy(this->config.mqtt.username, doc["mqtt"]["username"]);
    strcpy(this->config.mqtt.password, doc["mqtt"]["password"]);
    strcpy(this->config.mqtt.topic, doc["mqtt"]["topic"]);

    // smtp config
    this->config.smtp.enabled = doc["smtp"]["enabled"];
    strcpy(this->config.smtp.host, doc["smtp"]["host"]);
    this->config.smtp.port = doc["smtp"]["port"];
    strcpy(this->config.smtp.email, doc["smtp"]["email"]);
    strcpy(this->config.smtp.password, doc["smtp"]["password"]);
    strcpy(this->config.smtp.recipient, doc["smtp"]["recipient"]);

    // system config
    strcpy(this->config.system.ntp, doc["system"]["ntp"]);

    // close file
    file.close();
}

mqtt_t ConfigManager::get_mqtt() {
    return this->config.mqtt;
}

system_t ConfigManager::get_system() {
    return this->config.system;
}

smtp_t ConfigManager::get_smtp() {
    return this->config.smtp;
}

wifi_t ConfigManager::get_wifi() {
    return this->config.wifi;
}
