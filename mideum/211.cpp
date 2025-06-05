class WordDictionary 
{
    struct Node
    {
        bool end = false;
        unordered_map<char, Node*> alph;
    };

    Node *root = nullptr; 

    bool search_dfs(const string& str, Node* root, int pos)
    {
        if (!root)
            return false;

        if (pos == str.size())
            return root->end;

        if (str[pos] == '.')
        {
            bool test = false;

            for (const auto& a : root->alph)
            {
                test |= search_dfs(str, a.second, pos + 1);
            }

            return test;
        }
        else
        {
            if (root->alph.contains(str[pos]))
                return search_dfs(str, root->alph[str[pos]], pos + 1);
            else
                return false;
        }

        return false;
    }

public:
    WordDictionary() 
    {
        root = new Node;
    }
    
    void addWord(string word) 
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
        return search_dfs(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */