#include<iostream>
#include<algorithm>
using namespace std;

bool recursion(string &s, string &copy, int i, int j){
    if(i<j){
        swap(s[i], s[j]);
        return recursion(s, copy, i+1, j-1);
    }
    else return s==copy;
    
}

int main(){

    string s="abcba";
    string copy=s;

    // Method 1: in built reverse function
    // reverse(s.begin(), s.end());
    // cout<<(copy==s);

    // Method 2: recursion
    cout<<recursion(s, copy, 0, s.size()-1);

    return 0;
}