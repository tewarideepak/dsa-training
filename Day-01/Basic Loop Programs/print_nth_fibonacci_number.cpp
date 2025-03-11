#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 5, curr = 0;

    int prev=0, next=1;

    if(num==1){
        curr = prev;
    } else if(num==2){
        curr = next;
    } else {
        for(int i=2; i<num; i++){
            curr = prev + next;
            prev = next;
            next = curr;
        }
    
    }
    cout<<curr;
    return 0;
}