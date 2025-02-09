class Solution 
{
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) 
    {
        int n = groups.size();
        int m = elements.size();
        vector<int> assigned(groups.size(), -1);
        
        unordered_map<int, int> um;

        for (int i = 0; i < m; i++)
        {
            if (!um.contains(elements[i]))
                um[elements[i]] = i;
        }

        for (int k = 0; k < n; k++)
        {
            int ch = groups[k];

            int mini = 9999999;
            
            for (int i = 1; i <= std::sqrt(ch); ++i) 
            {
                if (ch % i == 0) 
                {
                    //divisors.push_back(i);

                    if (um.contains(i))
                        mini = min(mini, um[i]);
                    
                    if (i != ch / i) 
                    {
                        //divisors.push_back(n / i);
                        if (um.contains(ch / i))
                            mini = min(mini, um[ch / i]);
                    }
                }
            }

            if (mini != 9999999)
                assigned[k] = mini;
        }

        return assigned;
    }
};