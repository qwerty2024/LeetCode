class Solution 
{
    int _target;
    void backtr(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int pos, int curr_sum)
    {
        if (curr_sum == _target)
        {
            ans.push_back(curr);
            return;
        }
        else if (curr_sum > _target)
        {
            return;
        }

        if (pos == candidates.size())
            return;

        curr_sum += candidates[pos];
        curr.push_back(candidates[pos]);

        backtr(candidates, ans, curr, pos, curr_sum);

        curr_sum -= candidates[pos];
        curr.pop_back();

        backtr(candidates, ans, curr, pos + 1, curr_sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        _target = target;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        backtr(candidates, ans, curr, 0, 0);

        return ans;
    }
};