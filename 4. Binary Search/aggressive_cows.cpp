//  Problem statement

// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

// You are also given an integer 'k' which denotes the number of aggressive cows.

// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

// Print the maximum possible minimum distance.

// Example:

// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2

// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :

// 6 4
// 0 3 4 7 10 9

// Sample Output 1 :

// 3

// Explanation to Sample Input 1 :

// The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.

// Sample Input 2 :

// 5 2
// 4 2 1 3 6

// Sample Output 2 :

// 5

// Expected time complexity:

// Can you solve this in O(n * log(n)) time complexity?

// Constraints :

// 2 <= 'n' <= 10 ^ 5
// 2 <= 'k' <= n
// 0 <= 'arr[i]' <= 10 ^ 9
// Time Limit: 1 sec.

#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> &stalls, int k, int mid)
{
    int cowsCount = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowsCount++;
            lastPos = stalls[i];
        }
        if (cowsCount >= k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int start = 1;
    int end = stalls.back() - stalls.front();
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossibleSol(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << aggressiveCows(stalls, k) << endl; // Output: 3
    return 0;
}

// ✅ In Aggressive Cows:

//     You're placing cows in stalls to maximize the minimum distance between any two cows.

//     So the max possible distance you can try is:

//     high = max(stall) - min(stall)

//     This is the farthest two cows can ever be from each other.

// ✅ In Book Allocation:

// Problem:

//     You’re given an array of book page counts.

//     You must assign books to k students contiguously.

//     Each student gets a segment of books.

//     Goal: Minimize the maximum number of pages assigned to any student.

// Why high = sum of array?

//     In the worst case, if there's only one student, they have to read all books → max load = sum of all pages.

// Why low = max(array)?

//     No student can get fewer pages than the largest book.

// So the binary search range is:

// low = max(pages)
// high = sum(pages)

// You're searching for the minimum possible "maximum pages" (i.e., what is the smallest max-load possible such that k students can handle it?).
// 🔁 Summary:
// Feature	Aggressive Cows	Book Allocation
// Goal	Maximize minimum distance	Minimize maximum pages assigned
// Binary search on	distance	maximum pages
// low	1	max(arr) (largest book)
// high	max(arr) - min(arr)	sum(arr) (total pages if 1 student reads)
// Greedy check (isPossible)	Can we place all cows at ≥ mid?	Can we assign books to ≤ k students with mid pages max?