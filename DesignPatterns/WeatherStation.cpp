//
//  WeatherStation.cpp
//  DesignPatterns
//
//  Created by admin on 27/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    void update(double temperature, double humidity, double pressure) {
        
    }
};

class DisplayElement{
    
};

class Subject {
public:
    virtual void registerObserver(Observer o) = 0;
    virtual void removeObserver(Observer o) = 0;
    virtual void notifyObserver() = 0;
};

// Погодные данные
class WeatherData : public Subject {
private:
    vector<Observer> observers;
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
        ;
    }
    
    void registerObserver(Observer o){
        this->observers.push_back(o);
    }
    
    void removeObserver(Observer o) {
        for (int i = 0; i < this->observers.size(); i++) {
            if (false) { //o == this->observers.size()) {
                // TODO неправильная реализация - изменить
                this->observers.pop_back();
            }
        }
    }
};
