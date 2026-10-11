#include <iostream>
#include <string>
using namespace std;

/*
    Revision [11/10/2026] 
    
    Topic: OOP in C++ - Class, Object & Encapsulation

    Key Concepts:
    1. Class: Blueprint for creating objects (Teacher).
    2. Object: Instance of a class (t1).
    3. Private Data Member: salary cannot be accessed directly outside the class.
    4. Public Data Members: name, dept, subject can be accessed directly.
    5. Constructor: Teacher() initializes dept = "Computer Science".
    6. Setter: setSalary(double s) sets the private salary.
    7. Getter: getSalary() returns the private salary.
    8. Encapsulation: Wrapping data and methods into a class and controlling
        access to data using access specifiers.

    Important Notes:
    - Private members can only be accessed directly within the class
        (and by authorized friends or members).
    - Use t1.setSalary(200000) to set salary.
    - Use t1.getSalary() to retrieve salary.
    - Initialize salary to 0 to avoid reading an uninitialized value.
    - Use << endl or " " to separate printed values.

    Example:
    Teacher t1;
    t1.setSalary(200000);
    cout << t1.getSalary();

    Time Complexity:
    - Setter: O(1)
    - Getter: O(1)
*/

class Teacher{

private:
    double salary;

public:
    Teacher(){
        dept = "Computer Science";
    }

    string name;
    string dept;
    // double salary ;
    string subject;

    void changeDept(string newdept){
        dept = newdept;
    }

    // setter
    void setSalary(double s){
        salary = s;
    }

    // getter
    double getSalary(){
        return salary;
    }
};

int main(){

    Teacher t1;

    t1.name = "Nipurn";
    //t1.dept = "Coputer Science";
    //t1.salary = 100000;
    t1.subject = "C++";
    t1.setSalary(200000);

    cout << t1.name << endl;
    //cout << t1.salary << endl;
    cout << t1.getSalary() << t1.dept << endl;
    
    return 0;
}
