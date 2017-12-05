#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "your_user_name" //Nombre de tu usuario 
#define DEVICE_ID "your_device_id" //Nombre del dispositivo creado 
#define DEVICE_CREDENTIAL "your_device_credential" //Credencial dada por Thinger  

#define SSID "your_wifi_ssid" //Nombre del router 
#define SSID_PASSWORD "your_wifi_ssid_password" //Contraseña 

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);//Pin D1 esp8266

  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(BUILTIN_LED);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
