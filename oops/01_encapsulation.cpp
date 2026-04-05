#include <iostream>
#include <string>
using namespace std;

class Teacher
{

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

    void changeDept(string newdept)
    {
        dept = newdept;
    }

    // setter
    void setSalary(double s)
    {
        salary = s;
    }
    // getter
    double getSalary()
    {
        return salary;
    }
};

int main()
{
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
