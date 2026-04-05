#include <iostream>
using namespace std;

class Sparse_Matrix
{

private:
    int arr[3][3];
    int x;

public:

    Sparse_Matrix(){
        x=0;
    }
    void getdata();
    void check();
    void storedata();

};

void Sparse_Matrix::getdata(){

    cout<<"Enter the element : "<<endl;

    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<arr[i][j];
        }
    }
}

int main(){
    Sparse_Matrix m;
    m.getdata();
}
