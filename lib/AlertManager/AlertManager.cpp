#include "AlertManager.h"

AlertManager::AlertManager(ConfigManager* config) {
    this->config = config;
}

AlertManager::~AlertManager() {
    free(this->config);
}

void AlertManager::send_alert(const char* message) {
    return;
}
