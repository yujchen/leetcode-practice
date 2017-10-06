/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
*/
void printArray(int *nums, int numsSize)
{
  printf("[");
  for (int i = 0; i < numsSize - 1; i++)
  {
    printf("%d,", nums[i]);
  }
  printf("%d]\n", nums[numsSize - 1]);
}

void moveZeroes(int *nums, int numsSize)
{
  //printArray(nums,numsSize);
  int count = 0;
  while (count < numsSize)
  {
    //printf("Count %d:  ", count);
    //printArray(nums,numsSize);
    //printf("\n");
    if (nums[count] == 0)
    {
      for (int j = 1; count + j < numsSize; j++)
      {
        if (nums[count + j] != 0)
        {
          nums[count] = nums[count + j];
          nums[count + j] = 0;
          break;
        }
      }
      if (nums[count] == 0)
      {
        break;
      }
    }
    count++;
  }
}
