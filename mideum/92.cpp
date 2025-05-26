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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left == right)
            return head;

        int curr = 1;
        ListNode* list = new ListNode(666, head);
        ListNode* point = list;

        while (curr < left)
        {
            point = point->next;
            curr++;
        }

        ListNode* current = point->next;
        ListNode* next_node = current->next;

        for (int i = 0; i < right - left; i++)
        {
            ListNode* tmp = next_node->next;
            next_node->next = current;
            current = next_node;
            next_node = tmp;
        }

        ListNode* tmp = point->next;
        point->next = current;
        tmp->next = next_node;

        head = list->next;
        
        list->next = nullptr;
        delete list;

        return head;
    }
};