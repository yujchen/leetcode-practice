Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


#include <vector> 
#include <stdio.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int stringLength = s.size();
 
        int sol = -1, i = 0;
        int found = 0;
        int x = 0;
        string temp;
        while ( stringLength != 0 )
        {
            for ( x = 0; x < temp.size(); x++)
            {
                if (s[i] == temp[x])
                {
                    found = 1;
                    //cout << x << "Found: " << temp << endl;
                    int y = temp.size();
                    if ( sol < y )
                    {
                     sol = y;
                    }                    
                    temp.erase(0,x+1);

                    break;
                }
            }//Reach the end of forloop = not found
            if (found == 1)
            {
                //cout << temp << endl;
                temp.push_back(s[i]);
            }
            else
            {
                temp.push_back(s[i]);
            }
            found = 0;
            i++;
            stringLength--;
        }

        return sol > (int)temp.size() ? sol : (int)temp.size();
    }
};