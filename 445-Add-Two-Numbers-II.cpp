/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
  struct StackNode *top;
};

struct StackNode
{
  int item;
  struct ListNode *cur;
  struct StackNode *prev;
};

struct Stack *create_stack(void)
{
  struct Stack *a = malloc(sizeof(struct Stack));
  a->top = NULL;
  return a;
}
void push(struct Stack *a, struct StackNode *node)
{
  node->prev = a->top;
  a->top = node;
}
struct StackNode *pop(struct Stack *a)
{
  struct StackNode *popped = a->top;
  a->top = a->top->prev;
  return popped;
}
int isNotEmpty(struct Stack *a)
{
  if (a->top == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  if (!l1)
  {
    return l2;
  }
  if (!l2)
  {
    return l1;
  }
  struct Stack *a = create_stack(); //l1
  struct Stack *b = create_stack(); //l2

  while (l1)
  {
    struct StackNode *l1node = malloc(sizeof(struct StackNode));
    l1node->item = l1->val;
    l1node->cur = l1;
    push(a, l1node);
    l1 = l1->next;
  }
  while (l2)
  {
    struct StackNode *l2node = malloc(sizeof(struct StackNode));
    l2node->item = l2->val;
    l2node->cur = l2;
    push(b, l2node);
    l2 = l2->next;
  }
  int apop = 0;
  int bpop = 0;
  int carry = 0;
  int ssum = 0;
  struct StackNode *atemp;
  struct StackNode *btemp;
  struct ListNode *xprev;
  while (isNotEmpty(a) || isNotEmpty(b))
  {
    if (isNotEmpty(a))
    {
      atemp = pop(a);
      apop = atemp->item;
    }
    else
    {
      struct ListNode *addNode = malloc(sizeof(struct ListNode));
      addNode->val = 0;
      addNode->next = atemp->cur;
      atemp->cur = addNode;
      apop = 0;
    }
    if (isNotEmpty(b))
    {
      btemp = pop(b);
      bpop = btemp->item;
    }
    else
    {
      btemp = NULL;
      bpop = 0;
    }
    //printf("popped a: %d\n", apop);
    //printf("popped b: %d\n", bpop);
    //printf("\n");
    ssum = apop + bpop + carry;
    carry = 0;
    if (ssum > 9)
    {
      ssum = ssum % 10;
      carry = 1;
    }
    atemp->cur->val = ssum;
  }
  if (carry == 1)
  {
    struct ListNode *addNode = malloc(sizeof(struct ListNode));
    addNode->val = 1;
    addNode->next = atemp->cur;
    atemp->cur = addNode;
  }
  return atemp->cur;
}