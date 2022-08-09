#pragma once
#include <Arduino.h>
#include "weather.h"
#include <Preferences.h>

#define WEATHER_FORECAST_SIZE 40

class WeatherApi {
private:
	String apiKey = "";
	
	Weather currentWeather;
	Weather forecast[WEATHER_FORECAST_SIZE]; //3h step for 5 days

	Preferences preferences;

public:
	void init();

	void setKey(String key);
	void saveKey(String key);
	void saveKey();

	

	void updateWeather();
	void updateForecast();
	void updateBothWF();

	Weather getWeather();
	Weather getForecast(int index);


};