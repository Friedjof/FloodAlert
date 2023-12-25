#ifndef __ALERT_ALERT_MANAGER_H__
#define __ALERT_ALERT_MANAGER_H__

#include <Arduino.h>

#include "ConfigManager.h"
#include "AlertManager.h"


class AlertManager {
    private:
        ConfigManager* config;

    public:
        AlertManager(ConfigManager* config);
        ~AlertManager();

        void send_alert(const char* message);
};

#endif // __ALERT_ALERT_MANAGER_H__