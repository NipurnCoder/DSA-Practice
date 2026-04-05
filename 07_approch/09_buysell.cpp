#include<iostream>
#include<vector>
using namespace std;


    int stock (vector<int> price){
    int max_profit=0;
    int best_buy=price[0];

    for(int i=1;i<price.size();i++){
        if(price[i]>best_buy){
            max_profit = max(max_profit, price[i]-best_buy);
        }
        best_buy = min(best_buy, price[i]);
    }
    return max_profit;
 }


int main(){
    
    vector<int> price = {7,1,5,3,6,4};

    int m = stock(price);
    cout<<m<<endl;

    return 0;
}