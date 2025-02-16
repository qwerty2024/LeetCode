class Solution 
{
public:
    long long maxWeight(vector<int>& pizzas) 
    {
        sort(pizzas.begin(), pizzas.end(), greater<>());
        int n = pizzas.size();
        int day = n / 4;
        
        long long ans = 0;
        
        int chet_day = day / 2;
        int nech_day = day - chet_day;

        int i = 0;
        for (i; i < nech_day; i++)
        {
            ans += pizzas[i];
        }

        for (i; chet_day > 0; chet_day--)
        {
            i++;
            ans += pizzas[i];
            i++;
        }
            
        return ans;
    }
};