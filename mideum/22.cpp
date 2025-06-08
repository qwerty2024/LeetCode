class Solution 
{
    int n = 0;
    int count_open = 0;
    int count_close = 0;
    vector<string> ans;
    string curr = "";

    void backtr()
    {
        if (curr.size() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        if (count_close < count_open)
        {
            curr += ')';
            count_close++;
            backtr();
            count_close--;
            curr.pop_back();
        }

        if (count_open < n)
        {
            curr += '(';
            count_open++;
            backtr();
            count_open--;
            curr.pop_back();
        }

    }

public:
    vector<string> generateParenthesis(int _n) 
    {
        n = _n;

        backtr();

        return ans;
    }
};