#include<iostream>
#include<vector>

using namespace std;

// Stock Buy And Sell

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int mini = INT_MAX;
    int maxi = INT_MIN;

    int n=prices.size();

    for(int i=0;i<n;i++){
        if(mini>=prices[i]) mini = prices[i];
        maxi = max(maxi, prices[i] - mini);
    }

    cout<<maxi;

    return 0;
}


