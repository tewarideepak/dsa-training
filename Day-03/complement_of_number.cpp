int bitwiseComplement(int n){
    int ans = 0, mul = 1, rem;

    if (n == 0) return 1;

    while(n){
        rem = n % 2;
        rem = rem ^ 1;
        n /= 2;
        ans = ans + rem * mul;
        mul *= 2;
    }
    return ans;
}


// Approach:

//     Find the number of bits in the binary representation of n:
//         If n is a number, its binary representation will have a certain number of bits. For example, 5 is 101 in binary, which has 3 bits.
//         We can calculate the number of bits using the following logic:
//             Find the largest number which is all 1s and has the same number of bits as n. For example, if n = 5, the largest number with 3 bits is 111 (binary), which is 7 in decimal.

//     Create a mask of 1s with the same number of bits as n:
//         To flip the bits of n, we first need to create a number with all 1s in the same length as n. This can be done by subtracting 1 from a number that's a power of 2 and greater than n.

//     Flip the bits:
//         Once we have a number mask where all bits are 1 (of the same length as n), we can flip the bits of n by taking the bitwise XOR of n and the mask.

//     Return the result.


class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;

        if(n == 0) return 1;

        while(mask <= n){
            mask = mask << 1;
        }

        mask = mask - 1;

        return n ^ mask;
        
    }
};