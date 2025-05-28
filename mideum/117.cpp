/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        deque<Node*> dq;

        if (root)
            dq.push_back(root);
        int n = 1;

        while (!dq.empty())
        {
            Node* prev = nullptr;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                Node* curr = dq.front();
                dq.pop_front();

                curr->next = prev;
                prev = curr;

                if (curr->right)
                {
                    dq.push_back(curr->right);
                    count++;
                }

                if (curr->left)
                {
                    dq.push_back(curr->left);
                    count++;
                }   
            }
            n = count;
        }

        return root;
    }
};