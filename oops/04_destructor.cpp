#include<iostream>
#include<string>
using namespace std;

/*
    Revision [15/10/2026]

    Topic: Classes, Objects, Access Specifiers, Constructor & Destructor

    Key Concepts:
    1. Class Choice contains data members and member functions.
    2. Private members (id1, id2) cannot be accessed directly outside the class.
    3. Public members (name1, name2, option) can be accessed using the object.
    4. Constructor initializes IDs and option automatically.
    5. Choose() takes user input (1 or 2).
    6. getValue() displays the ID according to the selected option.
    7. Option() displays the selected name, ID, and result.
    8. Destructor (~Choice()) executes automatically when the object goes out of scope.

    Important Notes:
    - Use void when a function does not return any value.
    - Initialize variables before reading or using them.
    - Handle invalid choices using else.
    - Constructor removes the need to call setValue() separately.
    - Object members are accessed using the dot (.) operator.

    Time Complexity:
    - Choose(): O(1)
    - getValue(): O(1)
    - Option(): O(1)

    Space Complexity: O(1)

    Important Learning:
    Constructor -> Initializes the object.
    Member functions -> Define object behavior.
    Destructor -> Performs cleanup when the object is destroyed.
*/

class Choice {

private :
    int id1;
    int id2;

public :
    string name1;
    string name2;
    int option;

    void setValue(){
        id1 = 1001;
        id2 = 2002;
    }

    //Initialized ID & Option
    void Choose(){
        cout<<"Enter your choice [1 or 2] : ";
        cin>>option; 
    }

    void getValue(){

        if(option == 1){
            cout<<"ID - "<<id1<<endl;
        }
        else if(option == 2){
            cout<<"ID - "<<id2<<endl;
        }
    }

    int Option(){

        if(option == 1){
            cout<<"Name - "<<name1<<endl;
            getValue();
            cout<<"YOU PASS !! "<<endl;
        }

        else if (option == 2){
            cout<<"Name - "<<name2<<endl;
            getValue();
            cout<<"YOU FAIL !!"<<endl;
        }

        else {
            cout<<"INVALID CHOICE !!"<<endl;
        }
    }

    ~Choice()
    {cout<<"This is Destructor "<<endl;}
};

int main(){

    Choice c1;
    c1.setValue();

    c1.name1 = "Popat Lal  ";
    cout<<"Name - "<<c1.name1<<endl;

    //Choice c2(c1);
    c1.name2 = "Namakuul ";
    cout<<"Name - "<<c1.name2<<endl;

    c1.getValue();
    c1.Choose();
    c1.Option();
    
    return 0;
}
