#include<iostream>
#include<string>
using namespace std;

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

    c1.name1 = "Popat Lal ";
    cout<<"Name - "<<c1.name1<<endl;
    //Choice c2(c1);
    c1.name2 = "Namakuul ";
    cout<<"Name - "<<c1.name2<<endl;

    c1.getValue();
    c1.Choose();
    c1.Option();
    
    return 0;
}
