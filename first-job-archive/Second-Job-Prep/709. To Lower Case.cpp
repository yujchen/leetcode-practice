/*
709. To Lower Case
Easy

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"

*/
class Solution {
public:
    string toLowerCase(string str) 
    {
        int x = 0;
        while (str.length() > x)
        {
            if (64 < str[x] && str[x] < 97)
            {
                str[x] += 32;            
            }
            x++;
        }
        return str;
    }
};