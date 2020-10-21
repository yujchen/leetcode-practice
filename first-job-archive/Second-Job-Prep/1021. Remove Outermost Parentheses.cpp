/*
A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.

 

Example 1:

Input: "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:

Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:

Input: "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

 

Note:

    S.length <= 10000
    S[i] is "(" or ")"
    S is a valid parentheses string

*/


class Solution {
public:
    string removeOuterParentheses(string S)
    {
        int x = 0;
        int left = 0; 
        int eraseflag = 1;

        //cout << S << endl;
        while (x < S.length() && x <= 10000)
        {
            //printf("Iteration %d\n", x);
            if ( S[x] == '(')
            {
                left++;
                if (eraseflag == 1)
                {
                   // cout << "erase at "<< x << "----new S=" << S << endl;
                    
                    S.erase(x, 1);
                    eraseflag = 0;
                    continue;
                }
                x++;
                continue;
            }
            if ( S[x] == ')')
            {
                left--; 
                if (left == 0)
                {
                    //cout << "erase at "<< x << "----new S=" << S << endl;
                    
                    S.erase(x,1);
                    eraseflag = 1;
                    continue;
                }
                x++;
                continue;
            }
        }
        return S;
    }
};