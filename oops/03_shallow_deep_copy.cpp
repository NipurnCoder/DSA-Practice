#include<iostream>
#include<string>
using namespace std;

class Bike {

public :
    string name;
    //string racingbike;
    string* racingbikePtr;

    Bike(string name, string racingbike){
        this->name = name;
       // this->racingbike = racingbike;
       racingbikePtr = new string;
       *racingbikePtr = racingbike;

    }

    Bike(Bike &o){
        this->name = o.name;
        //this->racingbike = o.racingbike;
        //this->racingbikePtr = o.racingbikePtr;
        racingbikePtr = new string;
        *racingbikePtr = *o.racingbikePtr;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Racing Bike : "<<*racingbikePtr<<endl;
    }

     ~Bike(){
        cout<<"This is Destructor "<<endl;
        delete racingbikePtr;
    }

};

int main(){

    Bike b1("Dawson", "Kawasaki");
    b1.getInfo();

    Bike b2(b1);
    b2.name = "Kingston";
    *(b2.racingbikePtr) = "Hayabusa";
    b2.getInfo();
    return 0;
}