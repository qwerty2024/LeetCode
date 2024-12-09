class Solution 
{
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qu) 
    {
        int n = nums.size();
        vector<int> tmp;
        tmp.push_back(-1);
        bool prev = (nums[0] % 2 == 0) ? true : false;

        for (int i = 1; i < n; i++)
        {
            // ищем правую границу
            bool curr = (nums[i] % 2 == 0) ? true : false;
            if (prev == curr)
            {
                tmp.push_back(i - 1);
            }
            prev = curr;
        }

        tmp.push_back(n - 1);

        //for (auto a : tmp)
        //{
        //    cout << a << endl;
        //}

        vector<bool> ans;

        for (int i = 0; i < qu.size(); i++)
        {
            auto it = lower_bound(tmp.begin(), tmp.end(), qu[i][0]);

            if (*it >= qu[i][1] && (*(--it)) < qu[i][0])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};