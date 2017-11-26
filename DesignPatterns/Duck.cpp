//
//  Duck.cpp
//  DesignPatterns
//
//  Created by admin on 27/11/2017.
//  Copyright © 2017 Vasilev corp. All rights reserved.
//

#include <iostream>
using namespace std;

// Интерфейс для летающих уток
class IFlyBehavior {
public:
    virtual void fly() = 0;
};

//Интерфейс для крякующих уток
class IQuackBehavior {
public:
    virtual void quack() = 0;
};

class Quack : public IQuackBehavior {
public:
    void quack() {
        cout << "Кря!" << endl;
    }
};

class Squeak : public IQuackBehavior {
public:
    void quack() {
        cout << "Пи-пи!" << endl;
    }
};

class MuteQuack : public IQuackBehavior {
public:
    void quack() {
        ;
    }
};

// Летает
class FlyWithWings : public IFlyBehavior {
public:
    void fly() {
        cout << "Я летаю с крыльями!" << endl;
    }
};

// Не летает
class FlyNoWay : public IFlyBehavior {
public:
    void fly() {
        ;
    }
};
// Реактивный полет
class FlyRocketPowered : public IFlyBehavior {
public:
    void fly() {
        cout << "I'm flying with a rocket!" << endl;
    }
};

// Абстрактный класс уточки
class Duck {
protected:
    IFlyBehavior* flyBehavior;
    IQuackBehavior* quackBehavior;
public:
    Duck() {
        cout << "Duck contruct" << endl;
    }
    
    void setFlyBehavior(IFlyBehavior* flyBehavior) {
        this->flyBehavior = flyBehavior;
    }
    
    void setQuackBehavior(IQuackBehavior* quackBehavior) {
        this->quackBehavior = quackBehavior;
    }
    
    void performQuack() {
        this->quackBehavior->quack();
    }
    
    void swim() {
        cout<< "swim" << endl;
    }
    
    virtual void display() = 0;
    
    void performFly() {
        this->flyBehavior->fly();
    }
};

class ModelDuck : public Duck {
public:
    ModelDuck() {
        Duck::flyBehavior = new FlyNoWay();
        Duck::quackBehavior = new Quack();
    }
    
    void display() {
        cout << "I'm model duck!" << endl;
    }
};

//Настоящая утка
class MallarDuck : public Duck {
    
public:
    MallarDuck() {
        Duck::flyBehavior = new FlyWithWings();
        Duck::quackBehavior = new Quack();
    }
    
    void display() {
        cout<< "MallarDuck.display" << endl;
    }
};

class RedheadDuck : public Duck {
    
public:
    RedheadDuck() {
        Duck::flyBehavior = new FlyWithWings();
        Duck::quackBehavior = new Quack();
    }
    
    void display() {
        cout<< "RedheadDuck.display" << endl;
    }
};

// Резиновые утки. Не летают
class RubberDuck : public Duck {
    
public:
    RubberDuck() {
        Duck::flyBehavior = new FlyNoWay();
        Duck::quackBehavior = new Squeak();
    }
    
    void display() {
        cout<< "RubberDuck.display - резиновая утка" << endl;
    }
    
    void fly() {
        
    }
};

//Деревянные утки. Не летают и не крякают
class DecoyDuck : public Duck {
    
public:
    DecoyDuck() {
        Duck::flyBehavior = new FlyNoWay();
        Duck::quackBehavior = new MuteQuack();
    }
    
    void display() {
        cout<< "RubberDuck.display - деревянная утка" << endl;
    }
    
    void quack() {
        ;
    }
    
    void fly() {
        ;
    }
};
