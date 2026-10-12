#include <iostream>
#include <string>
using namespace std;

class Student{
public:

    string name;
    double rollnumber;
    string subject;

    //Parameterized Constructor
    Student(string name, string r, string s){
        this->name = name; //this pointer use for same parameters
        rollnumber = 187;
        subject = s;
    }

    //Copy Constructor
    Student(Student &orgObj){
        this->name = orgObj.name;
        rollnumber = orgObj.rollnumber;
        subject = orgObj.subject;
    }

    //Display Student Details
    void getData(){
        cout << "Name : " << name << endl;
        cout << "Rollnumber : " << rollnumber << endl;
        cout << "Subject : " << subject << endl;
    }
};

int main(){

    cout<<"Constructor Overload"<<endl;

    Student s1("Nipurn", "187", "Oops");
    s1.getData();

    cout<<"\nShallow Copy Constructor"<<endl;

    Student s2(s1); //Copy s1's data into s2
    s2.getData();

    return 0;
}