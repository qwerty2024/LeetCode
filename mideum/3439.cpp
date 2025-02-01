class Solution 
{
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        int ans = 0;

        vector<int> tmp;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            int len = startTime[i] - end;
            //if (len != 0)
                tmp.push_back(len);

            end = endTime[i];
        }    
        int len = eventTime - end;
        
        //if (len != 0)
            tmp.push_back(len);

        long long a = 0;

        if (k >= tmp.size())
        {
            for (int i = 0; i < tmp.size(); i++)
                a += tmp[i];
            
            return a;
        }

        k++;
        int i = 0;
        for (; i < k; i++)
            a += tmp[i]; 

        ans = a;
        for (;i < tmp.size(); i++)
        {
            a += tmp[i];
            a -= tmp[i - k];

            ans = max(ans, (int)a);
        }
        
        return ans;
    }
};