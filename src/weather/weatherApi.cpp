#include "weatherApi.h"



// Temp befor wifi module is done
#include <WiFi.h> 
#include <HTTPClient.h>
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("Honzik - IPhone", "1234567890???;;");
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println(WiFi.localIP());
}
int makeHttpRequest(String url, String &out) {
	HTTPClient http;
	http.begin(url);

	int httpResponseCode = http.GET();

	out = http.getString();

	return httpResponseCode;
}


void WeatherApi::init(){
	preferences.begin("weatherApi-owm");
	if(preferences.isKey("apiKey")){
		apiKey = preferences.getString("apiKey");
	}
}
void WeatherApi::setKey(String key){
	apiKey = key;
}
void WeatherApi::saveKey(String key){
	setKey(key);
	saveKey();
}
void WeatherApi::saveKey(){
	preferences.putString("apiKey", apiKey);
}