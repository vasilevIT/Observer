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

void action(Duck* duck) {
    duck->performQuack();
    duck->swim();
    duck->display();
    duck->performFly();
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    Duck* duck = new MallarDuck();
    action(duck);
    
    duck = new RedheadDuck();
    action(duck);
    
    duck = new RubberDuck();
    action(duck);
    
    duck = new DecoyDuck();
    action(duck);
    
    duck->setFlyBehavior(new FlyRocketPowered());
    action(duck);
    
    return 0;
}
