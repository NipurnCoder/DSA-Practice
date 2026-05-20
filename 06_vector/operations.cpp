#include<iostream>
#include<vector>
using namespace std;

//Revise today 20/05

int main() {
    vector <int> vec;

    //operations of vector

    //add val
    vec.push_back(34);
    vec.push_back(23);
    vec.push_back(90);
    vec.push_back(99);

    //remove val
    vec.pop_back();

    //loop to print values

    for(int val : vec) {
        cout << val << " ";
    }
    cout<<endl;

    //vector's size
    cout << "size " << vec.size() << endl;
    //capacity increase by x2
    cout<<"capacity"<<vec.capacity()<<endl;
    
    //element in front
    cout<<vec.front()<<endl;
    //elementm in last
    cout<<vec.back()<<endl;
    //al idx val
    cout<<vec.at(1)<<endl;
    
    return 0;
}
