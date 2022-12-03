/*
 * 18936-ex1.10 手串
 * times : 2
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, lim, types;

// 把前面 lim-1 个珠子连后面去，直接使用前缀和方法统计一遍
void listMethod(void)
{
        vector<vector<int>> bra;
        int amount, temp;
        for (int i = 0; i < n; ++i) {
                vector<int> pearl;
                cin >> amount;
                while (amount--) {
                        cin >> temp;
                        pearl.push_back(temp);
                }
                bra.push_back(pearl);
        }

        if (lim >= n) { // 直接要求整串珠子不重复
                vector<int> pre(types+1, 0);
                for (auto it : bra) for (auto i : it) pre[i]++;
                cout << count_if(pre.begin(), pre.end(), [](int i)->bool{return i >= 2;}) << endl;
                return;
        }

        for (int i = 0; i < lim-1; ++i) bra.push_back(bra[i]); // 只需要用到的范围，把队列解换成链
        int len = bra.size();

        vector<vector<int>> pre; // 计算前缀和
        vector<int> seg(types+1, 0);
        pre.push_back(seg); // 提前偏移

        for (int i = 1; i <= len; ++i) { // 第一颗初始化
                pre.push_back(pre[i-1]);
                for (int c : bra[i-1]) pre[i][c]++;
        }

        vector<bool> flag(types+1, false); // 开始统计
        int left = 0, right = lim;
        while (right <= len) {
                for (int i = 1; i <= types; ++i)
                        if (pre[right][i] - pre[left][i] >= 2) flag[i] = true;
                ++left, ++right;
        }

        cout << count_if(flag.begin() + 1, flag.end(), [](bool i)->bool{return i;}) << endl;
}

void circleMethod(void)
{
        vector<vector<int>> segment; // 直接在输入时计算前缀和数组，方便后面统计
        vector<int> frag(types + 1, 0);
        int m;
        for (int i = 0; i < n; ++i) {
                cin >> m;
                int c;
                for (int j = 0; j < m; ++j) {
                        cin >> c;
                        frag[c]++;
                }
                segment.push_back(frag);
        }

        vector<bool> flag(types + 1, false);
        if (lim >= n) { for (int i = 1; i <= types; ++i) if (segment[n-1][i] > 1) flag[i] = true; } // 初始化
        else {
                int left = 1;
                int right = lim;
                for (int i = 1; i <= types; ++i) if (segment[right - 1][i] > 1) flag[i] = true; // 初始化
                while (left < n) // left 到达 n，整串遍历完成
                {
                        vector<int> check(types + 1, 0);
                        if (right < n) for (int i = 1; i <= types; ++i) check[i] = segment[right][i] - segment[left-1][i]; // [][]|---->[][]
                        else { // -->[][][][]|--
                                int over = right % n;
                                for (int i = 1; i <= types; ++i)
                                        check[i] = segment[n-1][i] - segment[left-1][i] + segment[over][i];
                        }
                        for (int i = 1; i <= types; ++i) if (check[i] > 1) flag[i] = true;
                        left++, right++;
                }
        }

        cout << count_if(flag.begin()+1, flag.end(), [](bool i)->bool{return i;}) << endl;
}

// n 个珠子的手串，一个珠子多种颜色，要求统计 lim 个连续珠子内的重复颜色个数
int main(void)
{
        ios::sync_with_stdio(false);
        cin >> n >> lim >> types;

        listMethod();
        // circleMethod();

        return 0;
}
