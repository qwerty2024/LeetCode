/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
    void dfs(Node* node, unordered_map<int, pair<Node*, bool>>& created)
    {
        created[node->val].second = true;

        for (auto a : node->neighbors)
        {
            Node* new_node = nullptr;
            if (!created.contains(a->val))
            {
                new_node = new Node(a->val);
                created[new_node->val] = {new_node, false};
                created[node->val].first->neighbors.push_back(new_node);
                new_node->neighbors.push_back(created[node->val].first);
            }
            else if (created[a->val].second == false)
            {
                created[node->val].first->neighbors.push_back(created[a->val].first);
                created[a->val].first->neighbors.push_back(created[node->val].first);
            }
        }

        for (auto a : node->neighbors)
        {
            if (created[a->val].second == false)
            {
                dfs(a, created);
            }
        }
    }

public:
    Node* cloneGraph(Node* node) 
    {
        if (!node)
            return nullptr;

        unordered_map<int, pair<Node*, bool>> created;
        Node* new_node = new Node(node->val);
        created[new_node->val] = {new_node, false};
        dfs(node, created);

        return new_node;
    }
};