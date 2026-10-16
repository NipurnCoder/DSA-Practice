#include <iostream>
#include <string>
using namespace std;

/*
    Revision [16/10/2026]

    Topic: Multilevel Inheritance in C++

    Concept:
    - Multilevel inheritance occurs when a class inherits from another
        derived class.
    - Car2 inherits Car1.
    - Car3 inherits Car2 and indirectly receives Car1's public members.

    Inheritance Chain:
        Car1 -> Car2 -> Car3

    Members:
    - Car1: name
    - Car2: engine
    - Car3: model

    Object:
    - c0 is an object of Car3.
    - It can access name, engine, and model because they are public.

    Important Note:
    - Public inheritance allows public members of the base class to remain
        publicly accessible through the derived class.
    - Private members are not directly accessible in the derived class.

    Time Complexity: O(1) for these assignments and output operations,
        excluding the cost of printing strings.
*/

class Car1 {
public :
    string name;
};

class Car2 : public Car1{ // Inherit Car1 properties in Car 2
public :
    string engine;
};

class Car3 : public Car2{
public :
    string model;
};

int main(){

    Car3 c0;

    c0.name = "ROLLS ROYCE";
    c0.engine = "V8s";
    c0.model = "Phantom";

    cout<<c0.name<<endl;
    cout<<c0.engine<<endl;
    cout<<c0.model<<endl;

    return 0;

}