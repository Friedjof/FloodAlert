#ifndef __CONFIG_CONFIG_MANAGER_H__
#define __CONFIG_CONFIG_MANAGER_H__

// constants (changes may lead to crashes)

#define JSON_BUFFER_SIZE 4096              // size of json buffer
#define MAX_HOSTNAME_LENGTH 64             // max length of hostname
#define MAX_USERNAME_LENGTH 64             // max length of username
#define MAX_PASSWORD_LENGTH 64             // max length of password
#define MAX_TOPIC_LENGTH 64                // max length of topic
#define MAX_EMAIL_LENGTH 64                // max length of email
#define MAX_RECIPIENT_LENGTH 64            // max length of recipient
#define MAX_NTP_LENGTH 64                  // max length of ntp server
#define DEFAULT_CONFIG_FILE "/config.json" // default config file

#include <Arduino.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <LittleFS.h>

// type definitions
typedef struct {
    short enabled;
    char host[MAX_HOSTNAME_LENGTH];
    int  port;

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];    
    char topic[MAX_TOPIC_LENGTH];
} mqtt_t;

typedef struct {
    char ntp[MAX_NTP_LENGTH];
} system_t;

typedef struct {
    short enabled;
    char host[MAX_HOSTNAME_LENGTH];
    int  port;

    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    char recipient[MAX_RECIPIENT_LENGTH];
} smtp_t;

typedef struct {
    char ssid[MAX_HOSTNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} wifi_t;

typedef struct {
    mqtt_t   mqtt;
    system_t system;
    smtp_t   smtp;
    wifi_t   wifi;
} config_t;

class ConfigManager {
    private:
        const char* filename;

    public:
        ConfigManager(const char* filename);
        ConfigManager();
        ~ConfigManager();

        config_t config;

        void load_config();
        
        mqtt_t   get_mqtt();
        system_t get_system();
        smtp_t   get_smtp();
        wifi_t   get_wifi();
};

#endif