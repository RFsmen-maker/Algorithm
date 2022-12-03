/*
 * 18709. 魔法
 * times : 2
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 从前往后统计黑色奶牛数量，从后往前统计白色奶牛数量，重新遍历一边，取得最小和
int main(void)
{
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        vector<int> toWhite(n), toBlack(n); // 需要偏移
        toWhite[0] = 0, toBlack[n-1] = 0;
        for (int i = 1; i < n; ++i) {
                if (arr[i-1] == 2) toWhite[i] = toWhite[i-1] + 1;
                else toWhite[i] = toWhite[i-1];
        }
        for (int i = n-2; i >= 0; --i) {
                if (arr[i+1] == 1) toBlack[i] = toBlack[i+1] + 1;
                else toBlack[i] = toBlack[i+1];
        }

        int res = n;
        for (int i = 0; i < n; ++i) {
                res = min(res, toBlack[i] + toWhite[i]);
        }
        cout << res;

        return 0;
}

int try1(void)
{
        int n;
        cin >> n;
        vector<int> cows(n);
        for (int &i : cows) {
                cin >> i;
        }

        vector<int> black(n);
        int cur = 0;
//        cout << "front black : ";
        for (int i = 0; i < n; ++i) {
                if (cows[i] == 2) cur++;
                black[i] = cur;
        }
//        for (int i : black) cout << i << ' ';
//        cout << endl;

        vector<int> white(n);
        cur = 0;
//        cout << "back white : ";
        for (int i = n - 1; i >= 0; --i) {
                white[i] = cur;
                if (cows[i] == 1) cur++;
        }
//        for (int i : white) cout << i << ' ';
//        cout << endl;

        int change = n+1;
        for (int i = 0; i < n; ++i) {
                change = min(change, white[i] + black[i]);
        }
//        change = min(change, black[n-1]); // 全变白
//        change = min(change, white[0]); // 全变黑
        // 还要考虑不用变的情况
        cout << change;

        return 0;
}

