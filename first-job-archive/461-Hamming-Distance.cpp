/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/

int hammingDistance(int x, int y)
{
  int count = 0;
  if (x < 0 ^ y < 0)
  {
    x = x & 0x7fffffff;
    y = y & 0x7fffffff;
    count++;
  }
  int z = x ^ y;

  while (z)
  {
    if (z & 0x00000001)
    {
      count++;
    }
    z >>= 1;
  }
  return count;
}
//

/*Better solution from leetcode*/
int hammingDistance(int x, int y)
{
  int dist = 0, n = x ^ y;
  while (n)
  {
    ++dist;
    n &= n - 1;
  }
  return dist;
}
