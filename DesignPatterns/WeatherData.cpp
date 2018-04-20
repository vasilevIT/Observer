//
//  WeatherData.cpp
//  DesignPatterns
//
//  Created by admin on 28/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#pragma once

#include <iostream>
#include "Subject.cpp"

using namespace std;


// Погодные данные
class WeatherData : public Subject {
private:
    double temperature, humidity, pressure;
    
public:
    
    WeatherData() {
        this->temperature = 0;
        this->humidity = 0;
        this->pressure = 0;
    }
    
    double getTemperature() {
        return this->temperature;
    }
    
    double getHumidity() {
        return this->humidity;
    }
    
    double getPressure() {
        return this->pressure;
    }
    
    void measurementsChanged() {
        notifyObservers(this->temperature, this->humidity, this->pressure);
    }
    
    void setMeasurements(double temperature, double humidity, double pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};
