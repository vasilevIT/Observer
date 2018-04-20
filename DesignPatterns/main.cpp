//
//  main.cpp
//  DesignPatterns
//
//  Created by admin on 27/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#include <iostream>
#include "Duck.cpp"
#include "WeatherStation.cpp"

using namespace std;


int main(int argc, const char * argv[]) {
    
    WeatherStation* station = new WeatherStation();
    station->run();
    
    return 0;
}
