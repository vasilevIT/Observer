//
//  WeatherStation.cpp
//  DesignPatterns
//
//  Created by admin on 27/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#include <iostream>
#include <vector>
#include "WeatherData.cpp"
#include "CurrentConditionsDisplay.cpp"
#include "StatisticsDisplay.cpp"
#include "ForecastDisplay.cpp"
#include "Subject.cpp"
#include "Observer.cpp"
using namespace std;

#pragma once
class WeatherStation {
public:
    WeatherStation() {
        ;
    }
    
    void run() {
        cout << "Станция запущена..." << endl;
        WeatherData* weatherData = new WeatherData();
        CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);
        StatisticsDisplay* statDisplay = new StatisticsDisplay(weatherData);
        ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData);
        
        weatherData->setMeasurements(-5, 80, 450);
        cout << endl;
        weatherData->setMeasurements(10, 85, 450);
        cout << endl;
        weatherData->setMeasurements(22, 80, 450);
        cout << endl;
        
    }
};

