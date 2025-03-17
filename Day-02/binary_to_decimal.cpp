#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=1101;
    int ans=0, rem=0, mul=1;

    while(num!=0){
        rem = num%10;
        ans += rem*mul;
        mul*=2;
        num/=10;
    }

    cout<<ans;
}