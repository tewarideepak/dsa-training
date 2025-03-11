#include <bits/stdc++.h>
using namespace std;

int main(){
    int range = 10;
    int prev=0, next=1;

    cout<<prev<<" "<<next<<" ";

    for(int i=2; i<range; i++){
        int curr = prev + next;
        cout<<curr<<" ";

        prev = next;
        next = curr;
    }

    return 0;
}