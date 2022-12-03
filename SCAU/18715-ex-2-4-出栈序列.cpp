/*
 * 18715-ex2.4 出栈序列
 * 要找最大的字典序出栈序列，下一个能出栈的可以是当前这个的左边一个到右边所有任意一个
// 测例 1 6 3 4 5 2 ；1 4 3 5 2
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// 参考山羊哥的重写
int main(void)
{
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &i : nums) cin >> i;

        vector<int> maxR(n+1, 0); // 偏移以便使用计算
        for (int i = n-1; i >= 0; --i) { // 从后往前
                maxR[i] = max(nums[i], maxR[i+1]);
        }

        stack<int> st; // 使用一个栈暂存前面的数，其栈顶即上一个出栈位置的左指针，右指针即 i
        vector<int> res;
        for (int i = 0; i < n; ++i) {
                while (!st.empty() && st.top() > maxR[i]) {
                        res.push_back(st.top());
                        st.pop();
                }
                st.push(nums[i]);
        }
        while (!st.empty()) { // 清理剩下的
                res.push_back(st.top());
                st.pop();
        }

        for (int i : res) cout << i << ' ';

        return 0;
}
