#pragma once

#include <Arduino.h>
#include <json/json.h>



#define WEATHER_MAX_JSON_SIZE 2048

class Weather {
private:
	float temperature = 0;
	float tempFeelsLike = 0;
	float humidity = 0;
	float pressure = 0;

	int visibility = 0;

	float windSpeed = 0;
	float windHeading = 0;
	float windGust = 0;

	float clouds = 0;

	float positionLongitude = 0;
	float positionLatitude = 0;

	String weatherString = "";
	String weatherDescription = "";

	uint32_t timeOfCalculation = 0;
	int timeZone = 0;
	uint32_t sunrise = 0;
	uint32_t sunset = 0;

	String cityName = "";
	int cityId = 0;
	String countryCode = "";

	float rain = 0;
	float snow = 0;

public:
	float getTemperature(){return temperature;}
	float getTempFeelsLike(){return tempFeelsLike;}
	float getHumidity(){return humidity;}
	float getPressure(){return pressure;}

	int getVisibility(){Serial.println(visibility); return visibility;}

	float getWindSpeed(){return windSpeed;}
	float getWindHeading(){return windHeading;}
	float getWindGust(){return windGust;}

	float getClouds(){return clouds;}

	float getPositionLongitude(){return positionLongitude;}
	float getPositionLatitude(){return positionLatitude;}

	String getWeatherString(){return weatherString;}
	String getWeatherDescription(){return weatherDescription;}

	uint32_t getTimeOfCalculation(){return timeOfCalculation;}
	int getTimeZone(){return timeZone;}
	uint32_t getSunrise(){return sunrise;}
	uint32_t getSunset(){return sunset;}

	String getCityName(){return cityName;}
	int getCityId(){return cityId;}
	String getCountryCode(){return countryCode;}

	float getRain(){return rain;}
	float getSnow(){return snow;}




	void processCurrentWeather(JsonObject JSON);
	void processCurrentWeather(String JSON);


	void processForecast(JsonObject JSON, String countryCode);
	void processForecast(String JSON, String countryCode);

	void dump(Stream &stream);

	/*
	Weather(String JSON);
	Weather(JsonObject JSON);
	*/
};