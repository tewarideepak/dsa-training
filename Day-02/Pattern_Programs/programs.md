Nested Loop:

1. Print solid rectangle star

* * * * *
* * * * *
* * * * *
* * * * *
* * * * *

for(int i=1; i<=5; i++){
	for(int j=1; j<=5; j++){
		cout<<"*"<<" ";
	}
	cout<<endl;
}


2. Print number 10 patterns

10 10 10 10 10
10 10 10 10 10
10 10 10 10 10
10 10 10 10 10


row = 1
row <= 4
print 10 five times
go to next line
row = row + 1


for(int row=1; row<=4; row++){
	for(int col=1; col<=5; col++){
		cout<<10<<" ";
	}
	cout<<endl;
}


3. Pattern Number Pattern - 1

1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5


for(int row =1; row<=5; row++){
	for(int col=1; col<=5; col++){
		cout<<row<<" ";
	}
	cout<<endl;
}


4. Number Pattern - 2

1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5


for(int row=1; row<=5; row++){
	for(int col=1; col<=5; col++){
		cout<<col<<" ";
	}
	cout<<endl;
}


5. Descending number pattern

5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1

for(int row=5; row>=1; row--){
	for(int col=5; col>=1; col--){
		cout<<col<<" ";
	}
	cout<<endl;
}


6. Ascending square pattern

1 4 9 16 25
1 4 9 16 25
1 4 9 16 25
1 4 9 16 25
1 4 9 16 25

for(int row=1; row<=5; row++){
	for(int col=1; col<=5; col++){
		cout<<col*col<<" ";
	}
	cout<<endl;
}


7. Pattern of alphabets

a a a a a
b b b b b
c c c c c
d d d d d
e e e e e

for(int row=1; row<=5; row++){
	char name = 'a' + (row - 1);
	for(int col=1; col<=5; col++){
		cout<<name<<" ";
	}
	cout<<endl;
}


8. Ascending alphabet pattern

a b c d e
a b c d e
a b c d e
a b c d e
a b c d e


for(int row=1; row<=5; row++){
	for(int col=1; col<=5; col++){
		char name = 'a' + (col - 1);
		cout<<name<<" ";
	}
	cout<<endl;
}


9. Number Pattern

1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25


int count = 1;

for(int row=1; row<=5; row++){
	for(int col=1; col<=5; col++){
		cout<<count<<" ";
		count++;
	}
	cout<<endl;
}

((row-1)*5)+1


-----------------------------------------------------------------------------

1. Print right handed triangle

*
* *
* * *
* * * *
* * * * *

for(row=1; row<=5; row++){
	for(int col=1; col<=row; col++){
		cout<<"* ";
	}
	cout<<endl;
}


2. Ascending Number pattern

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5


for(int row=1; row<=5; row++){
	for(int col=1; col<=row; col++){
		cout<<col<<" ";
	}
	cout<<endl;
}


3. Number pattern - 2

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

for(int row=1; row<=5; row++){
	for(int col=1; col<=row; col++){
		cout<<row<<" ";
	}
	cout<<endl;
}


4. Reverse number pattern

1
2 1
3 2 1
4 3 2 1
5 4 3 2 1


for(int row=1; row<=5; row++){
	for(int col=row; col>=1; col--){
		cout<<col<<" ";
	}
	cout<<endl;
}


5. Alphabet pattern

a
b b
c c c
d d d d
e e e e e

for(int row=1; row<=5; row++){
	char name = 'a' + (row - 1);
	for(int col=1; col<=row; col++){
		cout<<name<<" ";
	}
	cout<<endl;
}


6. Star pattern

* * * * *
* * * *
* * *
* *
*

for(int row=1; row<=5; row++){
	for(int col=1; col>=5-row+1; col--){
		cout<<"* ";
	}
	cout<<endl;
}


7. Number Pattern

1 2 3 4 5
1 2 3 4
1 2 3
1 2
1


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row+1; col++){
		cout<<col<<" ";
	}
	cout<<endl;
}


8. Number pattern

5
5 4
5 4 3
5 4 3 2
5 4 3 2 1


for(int row=1; row<=5; row++){
	for(int col=5; col>=5-row+1; col--){
		cout<<col<<" ";
	}
	cout<<endl;
}


H.W.

1. Character Pattern

A
A B
A B C
A B C D
A B C D E

for(int row=1; row<=5; row++){
	for(int col=1; col<=row; col++){
		char name = 'A' + col - 1;
		cout<<name<<" ";
	}
	cout<<endl;
}


2. Number Pattern

10
10 11
10 11 12
10 11 12 13
10 11 12 13 14
10 11 12 13 14 15

for(int row=10; row<=15; row++){
	for(int col=10; col<=row; col++){
		cout<<col<<" ";
	}
	cout<<endl;
}


3. Character Pattern

A B C D
A B C
A B
A

for(int row=1; row<=4; row++){
	for(int col=1; col<=4-row+1; col++){
		char name = 'A' + col - 1;
		cout<<name<<" ";
	}
	cout<<endl;
}


--------------------------------------------------------------------------------------------------------------------------------


1. Star Pattern

n = 5

	*
      * *
    * * *
  * * * *
* * * * *


for(int i=1; i<=5; i++){
	for(int j=1; j<=5-i; j++){
		cout<<" ";
	}
	for(int k=1; k<=i; k++){
		cout<<"* ";
	}
	cout<<endl;
}


2. Number Pattern

      1
    2 2
  3 3 3
4 4 4 4


for(int row=1; row<=4; row++){
	for(int col=1; col<=4-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<row<<" ";
	}
	cout<<endl;
}


3. Number Pattern
     
        1
      1 2
    1 2 3
  1 2 3 4
1 2 3 4 5


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<col<<" ";
	}
	cout<<endl;
}


4. Character Pattern
 
        A
      A B
    A B C
  A B C D
A B C D E


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		char name = 'A' + col - 1;
		cout<<name;
	}
	cout<<endl;
}


5. Number Pattern

        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	for(int col=1; col<=row; col++){
		cout<<row - col + 1;
	}
	cout<<endl;
}


H.W.

1. Character Pattern

        A
      B B
    C C C
  D D D D
E E E E E


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		char name = 'A' + row - 1;
		cout<<name;
	}
	cout<<endl;
}


2. Number Pattern

        5
      5 4
    5 4 3
  5 4 3 2
5 4 3 2 1


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<5 - col + 1;
	}
	cout<<endl;
}


3. Character Pattern

        E
      E D
    E D C
  E D C B
E D C B A


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		char name = 'A' + 5 - col;
		cout<<name;
	}
	cout<<endl;
}


--------------------------------------------------------------------------------------------------------------------------------

1. Star Pattern

n = 5

        *
      * * * 
    * * * * *
  * * * * * * *
* * * * * * * * *

row  space  *
1	4   1
2	3   3
3	2   5
4	1   7
5	0   9

row = 1
row <= 5
print space 5-row
print *, 2*row-1
row++


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=2*row-1; col++){
		cout<<"*";
	}
	cout<<endl;
}


2. Number Pattern

        1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1
1 2 3 4 5 4 3 2 1


space	number
5-row	 1 to row and row-1 to 1

row=1
row<=5
print space, 5-row times
print 1 to row, increasing
print row-1 to 1, decreasing
row++


for(int row=1; row<=5; row++){
	for(int col=1; col<=5-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<col;
	}
	
	for(int col=row-1; col>=1; col--){
		cout<<col;
	}
	cout<<endl;
}


3. Star Pattern

n = 5

* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
        
row	space	*
1	0	9
2	1	7
3	2	5
4	3	3
5	4	1

space -> row-1
* -> (n-row)*2+1


for(int row=1; row<=5; row++){
	for(int col=1; col<=row-1; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=(5-row)*2+1; col++){
		cout<<"*";
	}
	cout<<endl;
}


4. Star Pattern

n = 4

* * * * * * * *
* * *     * * *
* *         * *
*             *
*             *
* *         * *
* * *     * * *
* * * * * * * *


row	star	space	star
1	4	0	4
2	3	2	3
3	2	4	2
4	1	6	1

star-> n-row+1
space-> 2*(row-1)
star-> n-row+1

row	star	space	star
1	1	6	1
2	2	4	2
3	3	2	3
4	4	0	4

star-> row
space-> 2*(n-row)
star-> row

for(int row=1; row<=n; row++){
	for(int col=1; col<=n-row+1; col++){
		cout<<"*";
	}
	
	for(int col=1; col<=2*(row-1); col++){
		cout<<" ";
	}
	
	for(int col=1; col<=n-row+1; col++){
		cout<<"*";
	}
	cout<<endl;
}

for(int row=1; row<=n; row++){
	for(int col=1; col<=row; col++){
		cout<<"*";
	}
	
	for(int col=1; col<=2*(n-row); col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<"*";
	}
	cout<<endl;
}


--------------------------------------------------------------------------------------------------------------------------------

1. Star Pattern

n = 4

*             *
* *         * *
* * *     * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *


row	*	space	*
1	1	6	1
2	2	4	2
3	3	2	3
4	4	0	4

*-> row
space-> 2*(n-row)
*-> row

row	*	space	*
3	3	2	3
2	2	4	2
1	1	6	1

*-> row
space-> 2*(n-row)
*-> row

for(int row=1; row<=n; row++){
	for(int col=1; col<=row; col++){
		cout<<"*";
	}
	
	for(int col=1; col<=2*(n-row); col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<"*";
	}
	cout<<endl;
}

for(int row=n-1; row>=1; row--){
	for(int col=1; col<=row; col++){
		cout<<"*";
	}
	
	for(int col=1; col<=2*(n-row); col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<"*";
	}
	cout<<endl;
}


2. Star Pattern

n = 4

      *
    *   *
  *   *   *
*   *   *   *
*   *   *   *
 *    *   *
   *    *
      *
    
    
for(int row=1; row<=4; row++){
	for(int col=1; col<=4-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<" *";
	}
	cout<<endl;
}

for(int row=4; row>=1; row--){
	for(int col=1; col<=4-row; col++){
		cout<<" ";
	}
	
	for(int col=1; col<=row; col++){
		cout<<" *";
	}
	cout<<endl;
}


