/*
771. Jewels and Stones
Easy

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0

Note:

    S and J will consist of letters and have length at most 50.
    The characters in J are distinct.

*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewelStones = 0;
        for (int x = 0; x < J.size(); x++)
        {
            //printf("%c\n", J[x]);
            for (int y = 0; y < S.size(); y++)
            {
                if (J[x] == S[y])
                {
                    jewelStones++;
                }
            }
        }
        return jewelStones;
    }
};