

Given an array of integers, return indices of the two numbers such that they add up to a specific target.You may assume that each input would have exactly one solution,
    and you may not use the same element twice.

        Example :

        Given nums = [ 2, 7, 11, 15 ],
              target = 9,

              Because nums[0] + nums[1] = 2 + 7 = 9,
              return [ 0, 1 ].

    ;
}

typedef vector<int> IntVec;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        IntVec Sol;
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++)
        {
            for (vector<int>::iterator itr2 = nums.begin(); itr2 != nums.end(); itr2++)
            {
                if (itr2 == itr)
                {
                    continue;
                }
                if ((*itr) + (*itr2) == target)
                {
                    if (itr > itr2)
                    {
                        Sol.push_back(itr2 - nums.begin());
                        Sol.push_back(itr - nums.begin());
                    }
                    else
                    {
                        Sol.push_back(itr - nums.begin());
                        Sol.push_back(itr2 - nums.begin());
                    }
                    return Sol;
                }
            }
        }
        return Sol;
    }
};