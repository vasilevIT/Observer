//
//  Observer.cpp
//  DesignPatterns
//
//  Created by admin on 28/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//


#include <iostream>
//#include "Subject.cpp"

#pragma once
class Observer {
public:
    int id;
    Observer() {
        this->id = rand() % 100;
    }
    
    virtual void update(Subject* s,double temperature, double humidity, double pressure) = 0;
};
