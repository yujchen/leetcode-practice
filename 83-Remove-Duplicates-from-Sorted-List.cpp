/*

 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
  struct ListNode **pp = &head;
  if (!head)
  {
    return NULL;
  }
  if (!head->next)
  {
    return head;
  }
  while ((*pp) && (*pp)->next)
  {
    //printf("*pp: %p; (*pp)->next: %p\n", *pp, (*pp)->next);
    //printf("head: %p; headnext: %p\n", head, head->next);
    if ((*pp)->val == (*pp)->next->val)
    {
      (*pp)->next = (*pp)->next->next;
    }
    else
    {
      pp = &(*pp)->next;
    }
  }

  return head;
}