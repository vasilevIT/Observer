//
//  Subject.cpp
//  DesignPatterns
//
//  Created by admin on 28/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#include "Observer.cpp"
#include <vector>
using namespace std;

#pragma once
class Subject {
private:
    vector<Observer*> observers;
    
public:
    void registerObserver(Observer* o){
        this->observers.push_back(o);
    }
    
    void removeObserver(Observer* o) {
        for (int i = 0; i < this->observers.size(); i++) {
            if (o->id == this->observers[i]->id) {
                for (int j = i; j < this->observers.size()-1; j++) {
                    this->observers[j] = this->observers[j + 1];
                }
                this->observers.pop_back();
            }
        }
    }
    
    void notifyObservers(double temp, double humi, double press) {
        double temperature = temp;
        double humidity = humi;
        double pressure = press;
        for (int i = 0; i < this->observers.size(); i++) {
            this->observers[i]->update(this, temperature, humidity, pressure);
        }
    }
};
