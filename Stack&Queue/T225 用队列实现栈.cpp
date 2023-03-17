#include <queue>
using namespace std;

class MyStack 
{
private:
    queue<int> q;
public:
    MyStack() 
    {

    }

    void push(int x) 
    {
        q.push(x);
    }

    int pop() 
    {
        // 出队入队前面size-1个元素
        int n = q.size() - 1;
        while (n--)
        {
            q.push(q.front());
            q.pop();
        }

        // 此时队列最前面的元素就是要弹栈的元素
        int tmp = q.front();
        q.pop();
        
        return tmp;
    }

    int top() 
    {
        int tmp = this->pop();
        q.push(tmp);
        return tmp;
    }

    bool empty() 
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */