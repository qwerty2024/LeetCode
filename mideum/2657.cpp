class Solution 
{
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<int> ans(n, 0);
        vector<int> v(n + 1, 0);

        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            v[B[i]]++;
            v[A[i]]++;

            if (B[i] != A[i])
            {
                if (v[B[i]] == 2)
                    curr++;

                if (v[A[i]] == 2)
                    curr++;
            }
            else 
                curr++;
                
            ans[i] = curr;
        }

        return ans;
    }
};