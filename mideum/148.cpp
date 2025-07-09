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
    void merge(ListNode*& head_1, ListNode*& head_2, int left, int right)
    {
        ListNode* start = new ListNode(0);
        ListNode* curr = start;

        while (head_1 != nullptr && head_2 != nullptr) 
        {
            if(head_1->val <= head_2->val)
            {
                curr->next = head_1;
                head_1 = head_1->next;
            }
            else
            {
                curr -> next = head_2;
                head_2 = head_2->next;
            }
        
            curr = curr->next;
        }

        if(head_1 != nullptr)
        {
            curr->next = head_1;
            head_1 = head_1->next;
        }
        
        if(head_2 != nullptr)
        {
            curr->next = head_2;
            head_2 = head_2->next;
        }

        head_1 = start->next;
        start->next = nullptr;
        delete start;
    }
    
    void mergeSort(ListNode*& head, int n)
    {
        if (n <= 1)
            return;

        int mid = n / 2;

        ListNode* tmp_end = head;
        for (int i = 0; i < mid - 1; i++)
        {
            tmp_end = tmp_end->next;
        }

        ListNode* tmp = tmp_end->next;
        tmp_end->next = nullptr;

        mergeSort(head, mid);
        mergeSort(tmp, n - mid);

        merge(head, tmp, mid, n - mid);
    }

public:
    ListNode* sortList(ListNode* head) 
    {
        int n = 0;
        ListNode* curr = head;
        while (curr)
        {
            curr = curr->next;
            n++;
        }

        mergeSort(head, n);

        return head;
    }
};