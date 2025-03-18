1. Syntax of while loop

initialization;

while(condition){
	// statement
}


Example: Print 1 to 10

int i=1;

while(i<=10){
	cout<<i<<" ";
	i++;
}


Example: Find factor of n

int n;
int i=1;

while(i<=n){
	if(n%i==0){
		cout<<i<<" ";
	}
}


2. do while loop

int i=1;

do{

	i++;
} while (i<=10);


Example: Sum of n natural numbers

int n, sum = 0;
int i=1;

do{
	sum+=i;
	i++;
}while(i<=n)


3. Concept of Break, Continue

4. Switch


int i=1;

switch(i){
	case 1: statement
	break;
	case 2: statement
	break;
	default: statement
}


// The case value must be either int or char type.
// There can be any number of cases.
// No duplicate case values are allowed.
// Each statement of the case can have a break statement. It is optional.
// The default Statement is also optional.


H.W.

1. Take a number n from the user and print all the even numbers between 1 and n(inclusive). Do this using while and do while loop separately.

#include <iostream>
using namespace std;

int main()
{
    int n, i=1;
    
    cout<<"Enter a number: ";
    cin>>n;

    while(i<=n){
    	if(i%2==0){
    	    cout<<i<<" ";
    	}
    	i++;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n, i=1;
    
    cout<<"Enter a number: ";
    cin>>n;

    do{
        if(i%2==0){
            cout<<i<<" ";
        }
        i++;
    }while(i<=n);

    return 0;
}


2. Find the factorial of a number n using a while loop and do a while loop.

#include <iostream>
using namespace std;

int main()
{
    int n, fact=1, i=1;
    
    cout<<"Enter a number: ";
    cin>>n;

    while(i<=n){
        fact*=i;
        i++;
    }
    
    cout<<"Factorial: "<<fact;
    

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n, fact=1, i=1;
    
    cout<<"Enter a number: ";
    cin>>n;
    
    do{
        fact*=i;
        i++;
    }while(i<=n);
    
    cout<<"Factorial: "<<fact;
    

    return 0;
}


3. Given a number n, print all the numbers from 1 to n(inclusive) which are not divisible by 3 and 5. (use Continue here).

#include <iostream>
using namespace std;

int main()
{
    int n, i=1;
    
    cout<<"Enter a number: ";
    cin>>n;
    
    while(i<=n){
        if(i%3==0 && i%5==0){
            i++;
            continue;
        }
        cout<<i;
        i++;
    }

    return 0;
}