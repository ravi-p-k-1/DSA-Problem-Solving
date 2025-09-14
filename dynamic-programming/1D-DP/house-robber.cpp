#include<iostream>
#include<vector>

using namespace std;

// House Robber

int spaceOptimized(vector<int> &vec, int n){
    int prev2=0;
    int prev=vec[0];

    for(int i=1;i<n;i++){
        int pick=vec[i];
        if(i>1) pick+=prev2;
        int notpick = prev;
        int curi=max(pick, notpick);
        prev2=prev;
        prev=curi;
    }

    return prev;
}

int main(){

    vector<int> vec = {1,5,1,2,6};
    int n = 5;

    vector<int> temp1, temp2;

    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(vec[i]);
        if(i!=n-1) temp2.push_back(vec[i]);
    }
    
    int first = spaceOptimized(temp1, n-1);
    int last = spaceOptimized(temp2, n-1);

    cout<<max(first, last);

    return 0;
}
