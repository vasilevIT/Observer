//
//  ForecastDisplay.cpp
//  DesignPatterns
//
//  Created by admin on 28/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#include <iostream>
#include "Observer.cpp"
#include "DisplayElement.cpp"
using namespace std;
#pragma once

class ForecastDisplay : public Observer, DisplayElement {
private:
    double press;
    Object* weatherData;
public:
    ForecastDisplay(Object* s){
        this->weatherData = s;
        this->weatherData->registerObserver(this);
        this->press = 0;
    }
    
    void update(Object* s,double temperature, double humidity, double pressure) {
        this->press = pressure;
        this->display();
    }
    
    void display() {
        cout << "Показания барометра!" << endl;
        cout << "Давление:" << this->press << endl;
        cout << endl;
    }
};
