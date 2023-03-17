#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    // 获取KMP next数组 - 这里直接采用前缀表作为next数组
    // 此时 next[x] 的意义是 needle[0,x]的最长相等前后缀的长度为next[x]，其中前缀的末尾字符为needle[next[x]-1]
    // 参数needle 模式串 
    vector<int> getNext(string needle)
    {
        // j 为前缀串的末尾 前缀串[0,j]
        int j = 0;
        // i 为后缀串的末尾 后缀串[i-j,i]
        int i = 1;

        // 初始化 设定仅含有单个字符的字符串的最长相等前后缀的长度为0
        vector<int> next(needle.size());
        next[0] = 0;

        // 开始计算 前提[0,j]已经计算完成 现在加入i以计算next[i]
        for (i = 1; i < needle.size(); i++)
        {
            // WHEN needle[j] != needle[i]
            /* 
            因为 [0,j-1] & [i-j, i-1] 是 [0,i-1] 的最长相等前后缀；
            所以目前需要尝试在 [0,j-1]的前缀 和 [i-j, i-1]的后缀 中找到最长的相等的两个，以使得 [0,x] == [i-x-1, i-x] 且 needle[x+1] == needle[i]
            又因为 [0,j-1] == [i-j, i-1]， 所以 [0,x] == [i-x-1, i-x] 等价于 [0,x] == [j-x-1, j-1]，即需要找的就是 [0,j-1] 中的最长相等前后缀
            所以我们需要找到的是 [0, j-1] 的最长相等前后缀的前缀的位置 这个信息已经在next先前的运算过程中获取了
            */
            // TIP1 新找到的[0,x]可能仍旧不能满足needle[x+1]==needle[i] 所以可能需要进一步重复上述流程 故而这里需要使用while循环完成
            // TIP2 注意这里需要找 [0,j-1] 说明 j > 0 当 j==0 而 needle[j] != needle[i] 时说明 [0,i] 的最长相等前后缀长度为0 
            while (j > 0 && needle[j] != needle[i])
            {
                j = next[j - 1];
            }

            // WHEN needle[j] == needle[i]
            // 不论是 一开始就满足条件 还是说经过了 上面循环的寻找后满足的条件
            // 因为 [0,j-1] & [i-j, i-1] 是 [0,i-1] 的最长相等前后缀；所以 [0,j] & [i-j,i] 是 [0,i] 的最长相等前后缀，长度为 j+1
            if (needle[j] == needle[i])
            {
                // 为了保证上述的已知条件：j的位置是[0,i-1]的最长相等前后缀中前缀的末尾字符的后一位
                j++;
            }
           
            next[i] = j;
        }

        return next;
    }

public:
    int strStr(string haystack, string needle) 
    {
        if (needle.size() == 0)
        {
            return 0;
        }

        int ans = -1;
        // 获取next数组
        vector<int> next = getNext(needle);

        // i 用于遍历 haystack; j 用于遍历 needle
        for (int i = 0, j = 0; i < haystack.size(); i++)
        {
            // 发生失配
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            // 匹配的情况
            if (haystack[i] == needle[j])
            {
                // 完成整个的匹配
                if (j == needle.size() - 1)
                {
                    ans = i + 1 - needle.size();
                    break;
                }
                // 仅是单个的匹配 继续尝试下一个字符是否匹配
                else
                {
                    j++;
                }
            }

            //if (haystack[i] == needle[j]) {
            //    j++;
            //}
            //if (j == needle.size()) {
            //    return (i - needle.size() + 1);
            //}

            
        }
        return ans;
    }
};

int main()
{
    Solution so;
    string haystack = "aabaabaaf";
    string needle = "aabaaf";


    cout << "str: " << so.strStr(haystack, needle) << endl;


    return 0;
}
