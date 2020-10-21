/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
  struct ListNode *fast = head;
  struct ListNode *slow = head;
  struct ListNode *prev = head;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    fast = fast->next;
  } // move fast pointer ahead by difference of n

  while (fast)
  {
    if (count > 0)
    {
      prev = slow;
    }
    slow = slow->next;
    fast = fast->next;
    count++;
  }
  if (count > 0)
  {
    prev->next = slow->next;
  }
  else
  {
    head = head->next;
  }
  free(slow);
  return head;
}