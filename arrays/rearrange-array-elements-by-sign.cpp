#include<iostream>
#include<vector>

using namespace std;

// Rearrange Array Elements by Sign

vector<int> rearrangeArray(vector<int>& nums) {
    int posind = 0;
    int negind = 1;
    int n=nums.size();

    vector<int> ans(n, 0);

    for(int i=0;i<n;i++){
        if(nums[i]>=0){
            ans[posind]=nums[i];
            posind++;
            posind++;
        }
        else{
            ans[negind]=nums[i];
            negind++;
            negind++;
        }
    }

    return ans;
}

int main(){

    vector<int> vec = {3,1,-2,-5,2,-4};
    
    vector<int> ans = rearrangeArray(vec);

    for(auto &i: ans){
        cout<<i<<" ";
    }

    return 0;
}