/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator 
{
    stack<TreeNode*> st;
    TreeNode* pointer = nullptr;

public:
    BSTIterator(TreeNode* root) 
    {
        pointer = root;
        while (pointer->left)
        {
            st.push(pointer);
            pointer = pointer->left;
        }
    }
    
    int next() 
    {
        int res = pointer->val;

        if (pointer->right)
        {
            pointer = pointer->right;
            while (pointer->left)
            {
                st.push(pointer);
                pointer = pointer->left;
            }
        }
        else
        {
            if (!st.empty())
            {
                pointer = st.top();
                st.pop();
            }
            else
                pointer = nullptr;
        }

        return res;
    }
    
    bool hasNext() 
    {
        if (pointer)
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */