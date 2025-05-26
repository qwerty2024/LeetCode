class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* mini = new ListNode(666);
        ListNode* maxi = new ListNode(666);
        ListNode* current_mini = mini;
        ListNode* current_maxi = maxi;
        ListNode* current = head;

        while (current)
        {
            if (current->val < x)
            {
                current_mini->next = current;
                current_mini = current_mini->next;
            }
            else
            {
                current_maxi->next = current;
                current_maxi = current_maxi->next;
            }

            current = current->next;
        }

        current_maxi->next = nullptr;
        current_mini->next = maxi->next;

        return mini->next;
    }
};