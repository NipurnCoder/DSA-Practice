#include<iostream>
#include<string>
using namespace std;

/*
    Revision [14/10/2026]

    Topic: Copy Constructor and Deep Copy

    Key Concepts:
    1. Parameterized Constructor initializes object data.
    2. Copy Constructor creates a new object from an existing object.
    3. Shallow Copy copies pointer addresses, causing shared memory.
    4. Deep Copy allocates separate memory and copies the actual value.
    5. Destructor releases dynamically allocated memory using delete.

    Important Code:
    racingbikePtr = new string;
    *racingbikePtr = *o.racingbikePtr;

    Why Deep Copy?
    Each object gets its own dynamically allocated string.
    Changing b2.racingbikePtr does not affect b1.racingbikePtr.

    Destructor:
    Each object deletes its own allocated memory.

    Output:
    b1 -> Dawson, Kawasaki
    b2 -> Kingston, Hayabusa

    Important Note:
    Prefer const Bike& in the copy constructor:
    Bike(const Bike& o)

    Time Complexity: O(L), where L is the length of the copied string.
    Space Complexity: O(L) additional memory for the copied string.
*/

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