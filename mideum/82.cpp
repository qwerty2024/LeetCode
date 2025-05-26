/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* current = new ListNode(-111, head);
        ListNode* head_new = current;
        int last_del = -111;

        while (current)
        {
            ListNode* tmp = current->next;
            ListNode* tmp_curr = current->next;

            while (tmp_curr && tmp_curr->next && tmp_curr->next->val == tmp->val)
            {
                tmp_curr = tmp_curr->next;
            }

            if (tmp == tmp_curr)
            {
                current = current->next;
            }
            else
            {
                current->next = tmp_curr->next;
            }
        }

        return head_new->next;
    }
};