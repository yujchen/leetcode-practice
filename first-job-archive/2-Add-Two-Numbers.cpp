You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

                                                                  You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.

        Input : (2->4->3) +
        (5->6->4)
            Output : 7->0->8

        /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
        class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(-1);
        ListNode *sol = temp; //Head of List
        int carry = 0;
        int flag1 = 0, flag2 = 0;
        while (l1 || l2)
        {

            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            int rem = sum % 10;
            carry = 0;
            if (temp->val == -1)
            {
                temp->val = rem;
            }
            else
            {
                temp->next = new ListNode(rem);
                temp = temp->next;
            }

            if (sum > 9)
            {
                carry = 1;
            }
            if (l1)
            {
                if (l1->next == NULL)
                {
                    l1 = l1->next;
                    flag1 = 1;
                }
                else
                {
                    l1 = l1->next;
                }
            }
            if (l2)
            {
                if (l2->next == NULL)
                {
                    l2 = l2->next;
                    flag2 = 1;
                }
                else
                {
                    l2 = l2->next;
                }
            }
        }
        if (carry == 1)
        {
            temp->next = new ListNode(1);
        }
        return sol;
    }
};