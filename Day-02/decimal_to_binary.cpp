// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int num = 13, mul = 1;
//     int rem=0, ans=0;
    
//     while(num!=0){
//         rem = num%2;
//         ans = rem*mul+ans;
//         mul = mul * 10;
//         num = num/2;
//     }
    
//     cout<<ans;
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 13, mul = 1;
    int rem=0, ans=0;
    
    while(num!=0){
        rem = num&1;
        ans += rem*mul;
        mul *= 10;
        num = num>>1;
    }
    
    cout<<ans;
}


// For large numbers it will store in 32 bit which will exceed the integer range and we will get unexpected result.