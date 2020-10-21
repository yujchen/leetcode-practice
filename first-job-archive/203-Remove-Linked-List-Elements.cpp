/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
  struct ListNode *origHead = head;
  struct ListNode *prev, *next;
  if (head == NULL)
  {
    return head;
  }

  prev = NULL;
  next = NULL;

  while (head)
  {
    next = head->next;
    if (head->val == val)
    {
      if (prev)
      {
        prev->next = head->next;
      }
      if (head == origHead)
      {
        origHead = head->next;
      }
      free(head);
    } //Remove this node
    else
    {
      prev = head;
    }
    head = next;
  }
  return origHead;
}

//Better Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
  struct ListNode **list = &head;

  while (*list != NULL)
  {
    if ((*list)->val == val)
    {
      *list = (*list)->next;
    }
    else
    {
      list = &(*list)->next;
    }
  }

  return head;
}