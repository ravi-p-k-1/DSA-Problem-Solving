#include <iostream>

using namespace std;

bool checkPalindrome(int n){
    if(n<0) return false;
    int rev=0;
    int x=n;

    while(x){
        rev=rev*10+x%10;
        x=x/10;
    }

    if(rev==n) return true;
    else return false;

}

int main(){

    int n=-121;

    cout<<checkPalindrome(n);

    return 0;
}