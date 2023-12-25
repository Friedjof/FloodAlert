#include <Arduino.h>

#include "ConfigManager.h"
#include "AlertManager.h"

ConfigManager* config = new ConfigManager();
AlertManager* alert = new AlertManager(config);

void setup() {
  Serial.begin(9600);
  
  config->load_config();
}

void loop() {
  Serial.println("Hello World!");
  delay(1000);
}
