class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) 
    {
        sort(strength.begin(),strength.end());
        int n = strength.size();
        int ans = INT_MAX;
        do {
            int minute = 0;
            int x = 1;
            // iterating the current permutation
            for(int j = 0; j < n; j++)
            {
                minute += (strength[j] % x == 0 ? strength[j] / x :(strength[j] / x) + 1); // just a little bit of math.
                x += K; // as per the description 
            }
            if (ans > minute) ans = minute; // choosing smaller one as answer
        }while(next_permutation(strength.begin(),strength.end()));
        return ans;
    }
};