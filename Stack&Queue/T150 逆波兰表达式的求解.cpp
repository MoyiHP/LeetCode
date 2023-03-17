#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        // ����ջ ���ڴ洢��ֵtoken
        stack<long long> st;

        for (string& token : tokens)
        {
            // ����token
            if (token == "+"
                || token == "-"
                || token == "*"
                || token == "/")
            {
                long long arg2 = st.top(); st.pop();
                long long arg1 = st.top(); st.pop();
                long long ans = 0;
                switch (token[0])
                {
                case '+':
                    ans = arg1 + arg2;
                    break;
                case '-':
                    ans = arg1 - arg2;
                    break;
                case '*':
                    ans = arg1 * arg2;
                    break;
                case '/':
                    ans = arg1 / arg2;
                    break;
                default:
                    break;
                }
                st.push(ans);
            }
            // ��ֵtoken
            else
            {
                st.push(stoll(token));  // stoll: string to long long 
            }
        }

        return st.top();
    }
};