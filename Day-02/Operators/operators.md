1. Arithmetic Operator


- Binary:

plus
minus
multiply
divide
modulus



// Explicit Type Conversion

(type) expression

(int)x + 1;


2. Precedence of operators


{*, /, %}  >  {+, -}

Associativity: Left to Right


3. Unary operators

++, --

// Post increment

b = a++

first assign then increase

// Pre increment

b = ++a

first increase then assign

// Post decrement

b = a--

first assign then decrease

// Pre decrement

b = --a

first decrease then assign


4. Comparison Operator

{==, >, >=, <, <=, !=}

a == b  

// if no then 0 otherwise 1


5 > 4 > 3   // 0

Associativity: Left to Right


5. Precision of comparison operator


{>, <, >=, <=} > {==, !=}

Associativity: Left to Right


6. Logical Operator

{&&, ||, !}

// Returns 0 or 1

5 && 5	// 1
0 && 5	// 0

5 || 5	// 1
0 || 5	// 1

!5	// 0
!0	// 1



7. Find the largest number among 3

if(a>b && a>c){
	cout<<a;
} else if(b>c){
	cout<<b;
} else {
	cout<<c;
}


8. Bitwise Operator

{&, |, ^, ~, <<, >>}

2 & 3 = 2

010
011
----
010

2 | 3 = 3

010
011
----
011


2 ^ 3 = 1

010
011
----
001


6 << 1 = 12	(number * 2^x)

0000......0000000110
0000......0000001100

// For large numbers doing left shift can also result in negative number

-6 << 2

// It is compiler dependent, nothing is defined in c++ for this.


6 >> 1 = 3	 number/2^x

00000000110
00000000011


~5 = -6

00000000000101
11111111111010

2's complement

00000000000101
	     1
----------------
00000000000110


9. Precedence of Bitwise Operator

{<<, >>} > {&, |, ^}


10. Assignment operator

a = 3
a *= 3		// a = a * 3
.
.
.
.


11. Precedence table in c++

Go to geeksforgeeks