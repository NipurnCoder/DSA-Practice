#include <iostream>
#include <string>
using namespace std;

/*
    Revision [12/10/2026]

    Topic: Constructor Overloading & Copy Constructor

    Key Points:

    1. Constructor Overloading:
    - Multiple constructors in the same class with different parameter lists.
    - Example: Parameterized Constructor and Copy Constructor.

    2. this Pointer:
    - Points to the current object.
    - this->name = name distinguishes the member variable from the parameter.

    3. Parameterized Constructor:
    - Initializes an object using arguments.
    - Student s1("Nipurn", "187", "Oops");

    4. Copy Constructor:
    - Creates a new object by copying an existing object.
    - Syntax: Student(const Student &orgObj);
    - Example: Student s2(s1);

    5. Shallow Copy:
    - Copies member values; pointer members may share the same memory.
    - This class uses string and double, so no raw-pointer copying issue exists.

    6. Important Note:
    - The parameter 'r' is unused in the original constructor.
    - Use rollnumber = stod(r) to convert the string into a double.

    Time Complexity: O(1) for a fixed number of members,
        excluding the time needed to copy strings.

    Space Complexity: O(1) auxiliary space, excluding string storage.
*/

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