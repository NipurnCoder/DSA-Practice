#include <iostream>
#include <string>
using namespace std;

class Car1 {
public :
    string name;
};

class Car2 : public Car1{
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