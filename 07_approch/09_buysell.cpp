#include<iostream>
#include<vector>
using namespace std;

//Revision Day 09
//22-05-2026

//Function to find max profit
int stock (vector<int> price){      //LeetCode : 121 Best Time To Buy and Sell Stocks

    //initialize maxProfit 
    int max_profit = 0;
    //Intitialize bestBuy with vecPrice val at idx=0
    int best_buy = price[0];


    for(int i=1;i<price.size();i++){
        
        //curr day val should be less than future val
        if(price[i]>best_buy){
            //find max profit future - curr
            max_profit = max(max_profit, price[i]-best_buy);
        }
        //cal best day
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