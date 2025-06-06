class Solution 
{
    int n = 0;

    void backtr(vector<string>& ans, const vector<vector<char>>& nums, const string& digits, int pos, string res)
    {
        if (pos == n)
        {
            ans.push_back(res);
            return;
        }

        for (const auto& a : nums[digits[pos] - '0'])
        {
            res += a;

            backtr(ans, nums, digits, pos + 1, res);

            res.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) 
    {
        n = digits.size();

        if (n == 0)
            return {};

        vector<vector<char>> nums{ {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, 
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, 
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

        vector<string> ans;

        backtr(ans, nums, digits, 0, "");

        return ans;
    }
};