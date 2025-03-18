#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 1534236469, rev = 0;

    while(num!=0){
        int rem = num % 10;
        num /= 10;
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)){
            rev = 0;
            break;
        }
        rev = rev * 10 + rem;
    }

    cout<<rev;
}