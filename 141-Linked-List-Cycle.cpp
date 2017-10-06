/*
 Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
  if (!head)
  {
    return false;
  } //No Linked List

  if (head == head->next)
  {
    return true;
  } //If one node points to itself

  struct ListNode **pp_fast = &head;
  struct ListNode **pp_slow = &head;
  if ((*pp_fast)->next && (*pp_fast)->next->next)
  {
    pp_fast = &(*pp_fast)->next->next;
  }
  else
  {
    return false;
  }

  while (*pp_fast)
  {
    if (*pp_slow == *pp_fast)
    {
      return true;
    }
    pp_slow = &(*pp_slow)->next;
    if ((*pp_fast)->next && (*pp_fast)->next->next)
    {
      pp_fast = &(*pp_fast)->next->next;
    }
    else
    {
      break;
    }
  }

  return false;
}

//Better Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
  struct ListNode *slow, *fast;
  if (head == NULL || head->next == NULL)
  {
    return false;
  }
  slow = head;
  fast = head;
  while (slow != NULL && fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      return true;
    }
  }
  return false;
}
0101 = 5 1 2 4 8 7 XOR 5 0111 ^ 0101