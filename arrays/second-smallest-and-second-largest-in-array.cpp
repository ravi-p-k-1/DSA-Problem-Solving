#include<iostream>
#include<vector>

using namespace std;

// Second smallest and second largest in an array

int main(){

    int small=INT_MAX, ssmall=INT_MAX, largest=INT_MIN, slargest=INT_MIN;

    vector<int> vec = {1, 2, 5, 5, 3, 4};

    for(auto &i: vec){
        if(small>i){
            ssmall=small;
            small=i;
        }
        else if(ssmall>i && small!=i) ssmall=i;
        if(largest<i){
            slargest=largest;
            largest=i;
        }
        else if(slargest<i && largest!=i) slargest=i;
    }

    cout<<"Second smallest: ";
    if(ssmall==INT_MAX) cout<<-1;
    else cout<<ssmall;

    cout<<endl;

    cout<<"Second largest: ";
    if(slargest==INT_MIN) cout<<-1;
    else cout<<slargest;

    return 0;
}