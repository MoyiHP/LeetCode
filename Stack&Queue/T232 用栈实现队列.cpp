#include <stack>
using namespace std;

class MyQueue 
{
private:
    stack<int> stack_in;
    stack<int> stack_out;

    void in2out()
    {
        while (!stack_in.empty())
        {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
    }

public:
    MyQueue() 
    {
        
    }

    void push(int x) 
    {
        stack_in.push(x);
    }

    int pop() 
    {
        if (stack_out.empty())
        {
            in2out();
        }

        int num = stack_out.top();
        stack_out.pop();
        return num;
    }

    int peek() 
    {
        if (stack_out.empty())
        {
            in2out();
        }

        return stack_out.top();
    }

    bool empty() 
    {
        return stack_in.empty() && stack_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */