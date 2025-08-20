#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Next Permutation

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    int bp = -1;

    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            bp=i;
            break;
        }
    }

    if(bp==-1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i=n-1;i>bp;i--){
        if(nums[bp]<nums[i]){
            swap(nums[bp], nums[i]);
            break;
        }
    }

    reverse(nums.begin()+bp+1, nums.end());
}

int main(){

    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    for(auto &i: nums){
        cout<<i<<" ";
    }

    return 0;
}