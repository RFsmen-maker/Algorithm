/*
 * 21 年机试题
 * times : 2
*/
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 正方形和圆
void _1(void)
{
        const double PI = 3.14;
        double L, R;
        cin >> L >> R;
        double square = L * L;
        double circle = PI * R * R;

        if (fabs(square - circle) < 0.001) cout << "Equal"; // 相等
        else if (square - circle >= 0.001) cout << "Square";
        else cout << "Circle"; // circle - quare >= 0.001
}

// 2. 数字拆分
void _2(void)
{
        int n;
        cin >> n;

        while (n) {
                cout << n % 10 << ' ';
                n /= 10;
        }
}

// 3. 平均分
void _3(void)
{
        int n;
        cin >> n;
        vector<double> arr(n);
        for (double &i : arr) cin >> i;

        double sum, top, bot;
        sum = 0.0, top = bot = arr[0];
        for (int i = 0; i < n; ++i) {
                sum += arr[i];
                if (arr[i] > top) top = arr[i];
                if (arr[i] < bot) bot = arr[i];
        }

        // cout << "top : " << top << ", bot : " << bot << endl;

        double res;
        if (n <= 5) res = sum / n;
        else res = (sum - top - bot) / static_cast<double>(n - 2);

        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.precision(2);
        cout << res;
}

// 4. 查找 SCAU，一眼就能看出，每次回必然是回到第一个字母，因为没有相同前后缀
void _4(void)
{
        string str;
        cin >> str;
        string pat = "SCAU";

        int len = str.size();
        int i = 0, j = 0;
        while (i < len && j < 4) {
                if (j == 0 || str[i] == pat[j]) ++i, ++j;
                else j = 0;
        }
        if (j == 4) cout << i - j;
        else cout << "NO";
}

// 5. 杨辉三角
void _5(void)
{
        int n;
        cin >> n;
        if (n == 1) {
                cout << 1 << endl;
                return;
        }

        // 初始化
        vector<int> arr = {1};
        for (int i = 1; i <= n; ++i) {
                for (int j : arr) cout << j << ' ';
                cout << endl;

                arr.push_back(1);
                for (int j = i-1; j >= 1; --j) { // 要从后往前
                        arr[j] = arr[j-1] + arr[j];
                }
        }
}

// 6. 哥德巴赫猜想
bool isPrime(int key) {
        for (int i = 2; i <= sqrt(key); ++i) {
                if (key % i == 0) return false;
        }
        return true;
}
void _6(void)
{
        int L, R;
        cin >> L >> R;
        if (L % 2) L++;
        if (R % 2) R--;

        while (L <= R) {
                for (int i = 2; i <= L / 2; ++i) {
                        if (isPrime(i) && isPrime(L - i)) {
                                cout << L << "=" << i << "+" << L - i << endl;
                                break;
                        }
                }
                L += 2;
        }
}

// 7. 随机数
void _7(void)
{
        int n;
        cin >> n;
        set<int> T;
        int temp;
        for (int i = 0; i < n; ++i) {
                cin >> temp;
                T.insert(temp);
        }

        cout << T.size() << endl;
        for (int i : T) cout << i << ' ';
}

// 8. 约瑟夫问题
void _8(void)
{
        int n, m, s = 0;
        cin >> n >> m;
        m += n-1;
        for (int i = 2; i <= n; ++i) {
                s = (s + m) % i;
                m--;
        }
        cout << s;
}

// 9. 卡片队列
void _9(void)
{
        int n;
        cin >> n;

        list<int> L;
        L.push_back(1);
        vector<list<int>::iterator> itArr(n+1); // 偏移，方便使用
        itArr[1] = L.begin();

        int x, p;
        for (int i = 2; i <= n; ++i) {
                cin >> x >> p;
                auto it = itArr[x]; // x 一定已经在链表里
                if (p) it++; // p 为 1 在右边插入
                itArr[i] = L.insert(it, i); // insert 之后返回的是 insert 位置的指针（迭代器）
        }
        for (int i : L) cout << i << ' ';
}

// 10. 跳跃机器人、18725 宇宙迁跃
bool check(vector<int> &pre, const int step, const int k) {
        int len = pre.size(), cur = 0, count = 0, sum = 0;
        while (count < k && cur < len) {
                if (sum + pre[cur] <= step) sum += pre[cur++];
                else sum = 0, count++;
        }
        if (cur < len) return false; // 没到对岸
        else return true;
}
void _10(void)
{
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        if (k == 1) { // 只跳一次
                cout << arr[n-1];
                return;
        }
        if (n == 1) { // 只有对岸
                cout << arr[0];
                return;
        }

        vector<int> pre(n); // 差数，便于计算
        pre[0] = arr[0];
        for (int i = 1; i < n; ++i) pre[i] = arr[i] - arr[i-1];

        if (k >= n) { // 跳跃次数多于等于石头，直接找最大间隔
                int res = pre[0];
                for (int i = 1; i < n; ++i) if (pre[i] > res) res = pre[i];
                cout << res;
                return;
        }

        int mid, left = arr[0] - 1, right = arr[n-1] + 1, minStep = arr[n-1];
        while (left + 1 != right) {
                mid = (right + left) / 2;
                if (check(pre, mid, k)) minStep = min(mid, minStep), right = mid; // 继续找更小的
                else left = mid; // 无法跳过肯定是不够大
        }
        // 只要够大，一定能跳过去！
        cout << minStep;
}

int main(void)
{
        _10();

        return 0;
}
