/*
  Reverse a singly linked list.

  click to show more hints.
  Hint:

  A linked list can be reversed either iteratively or recursively. Could you implement both?

  */

/**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     struct ListNode *next;
   * };
   */

struct Stack
{
  struct ListNode *top;
};

struct ListNode *push_stack(struct Stack *a, struct ListNode *b)
{
  b->next = a->top;
  a->top = b;
  return b;
}

struct ListNode *reverseList(struct ListNode *head)
{
  struct Stack *nodeStack = malloc(sizeof(struct Stack));
  nodeStack->top = NULL;
  struct ListNode *temp;
  struct ListNode *justpushed;
  while (head)
  {
    temp = head->next;
    justpushed = push_stack(nodeStack, head);
    head = temp;
  }
  return justpushed;
}

//Better Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
  struct ListNode *newHead, *newNext, *next;

  if (head == NULL || head->next == NULL)
    return head;

  newNext = NULL;
  while (head)
  {
    next = head->next;
    newHead = head;
    newHead->next = newNext;
    head = next;
    newNext = newHead;
  }
  return newHead;
}