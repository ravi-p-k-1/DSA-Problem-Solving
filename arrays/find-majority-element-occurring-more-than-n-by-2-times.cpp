#include<iostream>
#include<vector>

using namespace std;

// Find the Majority Element that occurs more than N/2 times

int majorityElement(vector<int>& nums) {
    long long int ele = 1e9+1;
    int cnt = 0;

    for(auto &i: nums){
        if(i==ele){
            cnt++;
        }
        else if(i!=ele){
            if(cnt==0){
                ele=i;
                cnt++;
            }else{
                cnt--;
            }
        }
    }

    return ele;
}

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};
    
    cout<<majorityElement(nums);

    return 0;
}