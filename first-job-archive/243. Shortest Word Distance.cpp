/*

243. Shortest Word Distance
Easy

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*/


#include<stdio.h>
#include<cstring>
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2)
    {
        int inputSize = words.size();
        int index = 0;
        int distance = 0;
        //equivalent for(auto n : words)
        std::vector<int> score; 
        for (std::vector<string>::iterator itr = words.begin(); itr != words.end(); ++itr, ++index)
        {            
            //Found word1
            if (!(itr->compare(word1)))
            {
                for (auto find_word2 : words)
                {
                    if (! (find_word2.compare(word2)))
                    {
                        score.push_back(index < distance ? distance-index : index - distance);
                    }
                    distance++;
                }
                distance = 0;
            }
            //Found word2
            if (!(itr->compare(word2)))
            {
                for (auto find_word2 : words)
                {
                    if (! (find_word2.compare(word1)))
                    {
                        score.push_back( index < distance ? distance-index : index - distance);
                    }
                    distance++;
                }
                distance = 0;
            }
        }
        int smallest;
        if (score.size())
        {
            smallest = score.at(0);        
        }
        else { return 0;}
        for (auto j : score)
        {
            if (j < smallest)
            {
                smallest = j;
            }
        }
        return smallest;
    }
};