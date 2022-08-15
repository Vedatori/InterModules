#include "weather.h"

void Weather::processCurrentWeather(JsonObject JSON){
	temperature = JSON["main"]["temp"];
	tempFeelsLike = JSON["main"]["feels_like"];
	humidity = JSON["main"]["humidity"];
	pressure = JSON["main"]["pressure"];

	visibility = JSON["visibility"];

	windSpeed = JSON["wind"]["speed"];
	windHeading = JSON["wind"]["deg"];
	windGust = JSON["wind"]["gust"];

	clouds = JSON["clouds"]["all"];

	positionLongitude = JSON["coord"]["lon"];;
	positionLatitude = JSON["coord"]["lat"];
	weatherString = JSON["weather"].as<JsonArray>()[0].as<JsonObject>()["main"].as<const char*>();
	weatherDescription = JSON["weather"].as<JsonArray>()[0].as<JsonObject>()["description"].as<const char*>();
	weatherCode = JSON["weather"].as<JsonArray>()[0].as<JsonObject>()["id"];
	timeOfCalculation = JSON["dt"];
	timeZone = JSON["timezone"];
	sunrise = JSON["sys"]["sunrise"];
	sunset = JSON["sys"]["sunset"];
	cityName = JSON["name"].as<const char*>();
	cityId = JSON["id"];
	countryCode = JSON["sys"]["country"].as<const char*>();

	rain = JSON["rain"]["3h"];
	snow = JSON["snow"]["3h"];
}

void Weather::processForecast(JsonObject JSON){
	JsonArray tempJsonArray = JSON["list"].as<JsonArray>();
	JsonObject tempList1stElement = tempJsonArray.getElement(0).as<JsonObject>();

	temperature = tempList1stElement["main"]["temp"];
	tempFeelsLike = tempList1stElement["main"]["feels_like"];
	humidity = tempList1stElement["main"]["humidity"];
	pressure = tempList1stElement["main"]["pressure"];

	visibility = tempList1stElement["visibility"];

	windSpeed = tempList1stElement["wind"]["speed"];
	windHeading = tempList1stElement["wind"]["deg"];
	windGust = tempList1stElement["wind"]["gust"];

	clouds = tempList1stElement["clouds"]["all"];

	weatherString = tempList1stElement["weather"].as<JsonArray>()[0].as<JsonObject>()["main"].as<const char*>();
	weatherDescription = tempList1stElement["weather"].as<JsonArray>()[0].as<JsonObject>()["description"].as<const char*>();
	timeOfCalculation = tempList1stElement["dt"];
	weatherCode = tempList1stElement["weather"].as<JsonArray>()[0].as<JsonObject>()["id"];

	rain = tempList1stElement["rain"]["3h"];
	snow = tempList1stElement["snow"]["3h"];

	positionLongitude = JSON["city"]["coord"]["lon"];
	positionLatitude = JSON["city"]["coord"]["lat"];
	timeZone = JSON["city"]["timezone"];
	sunrise = JSON["city"]["sunrise"];
	sunset = JSON["city"]["sunset"];
	cityName = JSON["city"]["name"].as<const char*>();
	cityId = JSON["city"]["id"];
	countryCode = JSON["city"]["country"].as<const char*>();

	
}

void Weather::dump(Stream &stream){
	stream.printf("temperature: %f\n",temperature);
	stream.printf("tempFeelsLike: %f\n",tempFeelsLike);
	stream.printf("humidity: %f\n",humidity);
	stream.printf("pressure: %f\n",pressure);
	stream.printf("visibility: %d\n",visibility);
	stream.printf("windSpeed: %f\n",windSpeed);
	stream.printf("windHeading: %f\n",windHeading);
	stream.printf("windGust: %f\n",windGust);
	stream.printf("clouds: %f\n",clouds);
	stream.printf("positionLongitude: %f\n",positionLongitude);
	stream.printf("positionLatitude: %f\n",positionLatitude);
	stream.printf("weatherString: %s\n",weatherString.c_str());
	stream.printf("weatherDescription: %s\n",weatherDescription.c_str());
	stream.printf("timeOfCalculation: %u\n",timeOfCalculation);
	stream.printf("timeZone: %u\n",timeZone);
	stream.printf("sunrise: %u\n",sunrise);
	stream.printf("sunset: %u\n",sunset);
	stream.printf("cityName: %s\n",cityName.c_str());
	stream.printf("cityId: %u\n",cityId);
	stream.printf("countryCode: %s\n",countryCode.c_str());
	stream.printf("rain: %f\n", rain);
	stream.printf("snow: %f\n", snow);
	stream.printf("weatherCode: %d\n", weatherCode);
}