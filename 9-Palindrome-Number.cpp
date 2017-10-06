/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        int orig = x;
        int res = 0;
        if (x < 0)
        {
            return false;
        }
        else
        {
            while (x != 0)
            {
                int tail = x % 10;
                res = res * 10 + tail;
                x = x / 10;
            }
            if (orig == res)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};