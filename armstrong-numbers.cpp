#include<cmath>
#include<iostream>
using namespace std;

bool checkArmstrong(int n){
    
    int store=n;
    int cnt = (int)log10(n)+1;
    int cnstore=cnt;
    int ans=0;

    while(cnt--){
        int digit=n%10;
        digit = pow(digit, cnstore);
        ans+=digit;
        n=n/10;
    }

    return ans==store;

}

int main(){

    int n = 12;

    cout<<checkArmstrong(n);

    return 0;
}