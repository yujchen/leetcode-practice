/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
  if (l1 == NULL)
  {
    return l2;
  }
  if (l2 == NULL)
  {
    return l1;
  }
  struct ListNode *head = l1->val < l2->val ? l1 : l2; //save new head pointer
  struct ListNode *newlistmove = head;
  struct ListNode *cur1 = l1 == newlistmove ? l1->next : l1;
  struct ListNode *cur2 = l2 == newlistmove ? l2->next : l2;

  while (cur1 != NULL || cur2 != NULL)
  {
    if (cur1 != NULL && cur2 != NULL)
    {
      if (cur1->val < cur2->val)
      {
        newlistmove->next = cur1;
        cur1 = cur1->next;
      }
      else
      {
        newlistmove->next = cur2;
        cur2 = cur2->next;
      }
    }
    else
    {
      if (cur1 == NULL)
      {
        newlistmove->next = cur2;
        cur2 = cur2->next;
      }
      else
      {
        newlistmove->next = cur1;
        cur1 = cur1->next;
      }
    }
    newlistmove = newlistmove->next;
  }
  return head;
}

//Better Solution
class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(INT_MIN); //Variable on the stack
    ListNode *tail = &dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }
};

//Improved Version of Better Solution
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while (l1 && l2)
  {
    ListNode *&node = l1->val < l2->val ? l1 : l2;
    tail = tail->next = node;
    node = node->next;
  } // Loop breaks one of the linked list ends, then assign the rest to tail.
  tail->next = l1 ? l1 : l2;
  return dummy.next;
}