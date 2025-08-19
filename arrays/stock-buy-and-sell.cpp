#include<iostream>
#include<vector>

using namespace std;

// Stock Buy And Sell

int maxProfit(vector<int>& prices) {
    int minprice=1e5;
    int maxpro=0;

    for(auto &i: prices){
        if(i<minprice) minprice=i;
        else{
            maxpro = max(maxpro, i-minprice);
        }
    }

    return maxpro;
}

int main(){

    vector<int> vec = {7,1,5,3,6,4};
    
    cout<<maxProfit(vec);

    return 0;
}

