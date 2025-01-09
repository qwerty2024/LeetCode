class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> um;
        for (int i = 0; i < list1.size(); i++)
        {
            um[list1[i]] = i;
        }

        int mini(INT_MAX);
        for (int i = 0; i < list2.size(); i++)
        {
            if (um.contains(list2[i]))
            {
                mini = min(mini, i + um[list2[i]]);
            }
        }

        vector<string> ans;

        for (int i = 0; i < list2.size(); i++)
        {
            if (um.contains(list2[i]))
            {
                if (mini == i + um[list2[i]])
                {
                    ans.push_back(list2[i]);
                }
            }
        }

        return ans;
    }
};