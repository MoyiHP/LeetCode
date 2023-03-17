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
        // �������ǰ��size-1��Ԫ��
        int n = q.size() - 1;
        while (n--)
        {
            q.push(q.front());
            q.pop();
        }

        // ��ʱ������ǰ���Ԫ�ؾ���Ҫ��ջ��Ԫ��
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