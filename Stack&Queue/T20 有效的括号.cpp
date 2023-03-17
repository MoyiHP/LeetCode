#include <stack>
#include <string>
using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        if (s.size() % 2 != 0)
        {
            return false;
        }

        stack<char> st;
        for (char& ch : s)
        {
            switch (ch)
            {
            case '{':
            {
                st.push('}');
                break;
            }
            case '[':
            {
                st.push(']');
                break;
            }
            case '(':
            {
                st.push(')');
                break;
            }
            case '}':
            case ']':
            case ')':
            {
                if (st.empty() || st.top() != ch)
                {
                    return false;
                }
                else
                {
                    st.pop();
                    continue;
                }
                break;
            }
            default:
                break;
            }
        }

        return st.empty();
    }
};