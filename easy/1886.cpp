class Solution 
{
    bool test(vector<vector<int>>& mat1, vector<vector<int>>& mat2)
    {
        int n = mat1.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat1[i][j] != mat2[i][j])
                    return false;
        }

        return true;
    }

    void rotate(vector<vector<int>>& mat)
    {
        int n = mat.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }   
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(mat[i][j], mat[i][n - j - 1]);
            }   
        }
    }

    void printer(vector<vector<int>>& mat)
    {
        int n = mat.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }   
            cout << endl;
        }
        cout << endl;
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        int n = mat.size();
        bool t = test(mat, target);
        if (t) return true;

        rotate(mat);        
        t = test(mat, target);
        if (t) return true;
        //printer(mat);

        rotate(mat);        
        t = test(mat, target);
        if (t) return true;
        //printer(mat);

        rotate(mat);        
        t = test(mat, target);
        if (t) return true;
        //printer(mat);

        return false;
    }
};