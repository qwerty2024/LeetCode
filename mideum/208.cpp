class Trie 
{
    struct Node
    {
        bool end = false;
        unordered_map<char, Node*> alph;
    };

    Node* root = nullptr;

public:
    Trie() 
    {
        root = new Node;
    }
    
    void insert(string word) 
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->alph.contains(word[i]))
            {
                curr = curr->alph[word[i]];
            }
            else
            {
                Node *new_node = new Node;
                curr->alph[word[i]] = new_node;
                curr = curr->alph[word[i]];
            }
        }

        curr->end = true;
    }
    
    bool search(string word) 
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->alph.contains(word[i]))
            {
                curr = curr->alph[word[i]];
            }
            else
            {
                return false;
            }
        }

        if (!curr->end)
            return false;

        return true;
    }
    
    bool startsWith(string prefix) 
    {
        Node *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (curr->alph.contains(prefix[i]))
            {
                curr = curr->alph[prefix[i]];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */