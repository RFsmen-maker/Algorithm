/*
 * 18932-ex2.3 出栈序列合法性判定
 * times : 2
 * 下一个出栈的只能是当前这个的左边或者右边两个之一，只有判定合法性能用
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        int n;
        cin >> n;
        vector<int> in(n); // 读取压栈
        for (int &i : in) cin >> i;

        int temp, left, right; // 双指针记录出栈那个的左右两个
        cin >> temp; // 初始化先读取一个，作为开端
        for (int i = 0; i < n; ++i) if (in[i] == temp) left = i - 1, right = i + 1; // 找到这个开端在压栈时的顺序

        for (int i = 1; i < n; ++i) {
                cin >> temp;
                if (left >= 0 && temp == in[left]) left--;
                else if (right < n && temp == in[right]) right++;
                else {
                        cout << "no";
                        return 0;
                }
        }
        cout << "yes";

        return 0;
}

