class ProductOfNumbers
{
    vector<int> data;

public:
    ProductOfNumbers()
    {
        data.push_back(1);
    }

    void add(int num)
    {
        if (data[data.size() - 1])
        {
            data.push_back(data[data.size() - 1] * num);
        }
        else
        {
            data.push_back(num);
        }

        if (!num)
        {
            data.push_back(0);

            for (int i = 0; i < data.size(); i++)
            {
                data[i] = 0;
            }
        }
    }

    int getProduct(int k)
    {
        int n = data.size();
        int ch = data[n - 1];

        int del = data[n - k - 1];
        int test = data[n - k];

        if (del)
        {
            return ch / del;
        }

        if (!test)
        {
            return 0;
        }
            
        return ch;
    }
};