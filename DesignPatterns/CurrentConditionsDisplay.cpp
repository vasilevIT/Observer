//
//  CurrentConditionsDisplay.cpp
//  DesignPatterns
//
//  Created by admin on 28/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#pragma once
#include <iostream>
#include "Observer.cpp"
#include "DisplayElement.cpp"
#include "Subject.cpp"
using namespace std;

class CurrentConditionsDisplay : public Observer, DisplayElement {
private:
    double temp, hum, press;
    Subject* weatherData;
    
public:
    CurrentConditionsDisplay(Subject* s) {
        this->weatherData = s;
        this->weatherData->registerObserver(this);
        this->temp = 0;
        this->hum = 0;
        this->press = 0;
    }
    
    void update(Subject* s,double temperature, double humidity, double pressure){
        this->temp = temperature;
        this->hum = humidity;
        this->press = pressure;
        this->display();
    }
    
    void display() {
        cout << "Текущее состояние дисплея :)" << endl;
        cout << "Температура: " << this->temp << endl;
        cout << "Влажность: " << this->hum << endl;
        cout << "Давление: " << this->press << endl;
        cout << endl;
    }
};
