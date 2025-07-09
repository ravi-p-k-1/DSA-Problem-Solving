#include <iostream>
using namespace std;

int reverseNumber(int n){
    int ans=0;

    while(n){
        ans=ans*10+n%10;
        n=n/10;
    }

    return ans;
}

int main(){

    int n=10400;

    cout<<reverseNumber(n);

    return 0;
}

