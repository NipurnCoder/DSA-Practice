#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector <int> vec;

    vec.push_back(34);
    vec.push_back(23);
    vec.push_back(90);
    vec.pop_back();

    for(int val : vec) {
        cout << val << " ";
    }
    cout<<endl;

    cout << "size " << vec.size() << endl;
    cout<<"capacity"<<vec.capacity()<<endl;
    
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;
    cout<<vec.at(1)<<endl;
    
}
