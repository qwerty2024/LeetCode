class Foo 
{
    atomic<bool> flag1 = false;
    atomic<bool> flag2 = false;

public:
    Foo() 
    {
        
    }

    void first(function<void()> printFirst) 
    {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag1 = true;
    }

    void second(function<void()> printSecond) 
    {
        
        while (true)
        {
            if (flag1) break;
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        flag2 = true;
    }

    void third(function<void()> printThird) 
    {
        while (true)
        {
            if (flag2) break;
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};