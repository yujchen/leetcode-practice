/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode *head)
{
  struct ListNode *p = head;
  int count = 0;
  while (p)
  {
    count++;
    p = p->next;
  }
  //0->1->2
  int seeker = 0;
  struct ListNode *pp = head;
  //printf("count: %d\n", count);
  while (count && pp != p)
  {
    p = head;
    pp = head;
    for (int i = 0; i < count - 1; i++)
    {
      if (i < seeker)
      {
        pp = pp->next;
      }
      p = p->next;
    }
    //printf("p->val = %d ;  pp->val = %d\n", p->val, pp->val);
    if (p->val != pp->val)
    {
      return false;
    }
    seeker++;
    count--;
  }
  return true;
}

//Next Attempt
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//1, 2, 3, 3, 2, 1  ;; 6   half = 3
//1, 2, 3, 2, 1     ;; 5   half = 2
//0, 0, 1, 1, 1, 0, 0     ;; 7   half = 3
// (count-1)/2;
bool isPalindrome(struct ListNode *head)
{
  int origCount = 0;
  if (!head || !head->next)
  {
    return true;
  }
  struct ListNode *p = head;
  int count = 0;
  while (p)
  {
    count++;
    p = p->next;
  }
  origCount = count;
  count = (count - 1) / 2;
  int seeker = 0;
  p = head;
  struct ListNode *next, *newNext = NULL, *newHead;

  while (seeker != count + 1)
  {
    next = p->next;
    p->next = newNext;
    newNext = p;
    newHead = p;
    p = next;
    seeker++;
  }
  seeker = 0;
  if (origCount % 2)
  {
    printf("here?\n");
    newHead = newHead->next;
    seeker++;
  }

  struct ListNode *pp = newHead;
  while (pp)
  {
    printf("%d\n", pp->val);
    pp = pp->next;
  }

  while (seeker != count + 1)
  {
    printf("p->val: %d; newHead->val: %d \n", p->val, newHead->val);

    if (p->val != newHead->val)
    {
      return false;
    }
    p = p->next;
    newHead = newHead->next;
    seeker++;
  }
  return true;
}
