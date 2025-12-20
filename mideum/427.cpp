/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution 
{
    const unordered_map<int, int> pows {{1, 0}, {2, 1}, {4, 2}, {8, 3}, {16, 4}, {32, 5}, {64, 6}};

public:
    Node* construct(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int p = pows.at(n); 

        if (p == 0)
        {
            Node* tree = new Node(grid[0][0] == 1, true);
            return tree;
        }

        vector<vector<Node*>> tree(n / 2, vector<Node*>(n / 2, nullptr));

        // стартовое заполнение
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < n; j += 2)
            {
                if (grid[i][j] == grid[i][j + 1] && grid[i + 1][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 1][j])
                {
                    tree[i / 2][j / 2] = new Node(grid[i][j] == 1, true);
                }
                else
                {
                    Node* topLeft = new Node(grid[i][j] == 1, true);
                    Node* topRight = new Node(grid[i][j + 1] == 1, true);
                    Node* bottomLeft = new Node(grid[i + 1][j] == 1, true);
                    Node* bottomRight = new Node(grid[i + 1][j + 1] == 1, true);

                    tree[i / 2][j / 2] = new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
                }
            }   
        }

        // создание дерева вверх
        int offset = 1;
        for (int it = 0; it < p - 1; it++)
        {
            for (int i = 0; i < n / 2; i += (offset * 2))
            {
                for (int j = 0; j < n / 2; j += (offset * 2))
                {
                    if (tree[i][j]->isLeaf == true && tree[i][j + offset]->isLeaf == true &&
                    tree[i + offset][j]->isLeaf == true && tree[i + offset][j + offset]->isLeaf == true && ((
                        tree[i][j]->val == true && tree[i][j + offset]->val == true &&
                    tree[i + offset][j]->val == true && tree[i + offset][j + offset]->val == true) || (
                        tree[i][j]->val == false && tree[i][j + offset]->val == false &&
                    tree[i + offset][j]->val == false && tree[i + offset][j + offset]->val == false)))
                    {
                        Node* new_node = new Node(tree[i][j]->val, true);
                        delete tree[i][j];
                        delete tree[i][j + offset];
                        delete tree[i + offset][j];
                        delete tree[i + offset][j + offset];

                        tree[i][j] = new_node;
                    }
                    else
                    {
                        tree[i][j] = new Node(false, false, tree[i][j], tree[i][j + offset], tree[i + offset][j], tree[i + offset][j + offset]);
                    }
                }   
            }

            offset <<= 1;
        }

        return tree[0][0];
    }
};