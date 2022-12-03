/*
 * 模拟测试
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void _1(void)
{
        double x;
        cin >> x;
        if (x >= 0) printf("%.2f", sqrt(x));
        else printf("%.2f", x);

}

void _2(void)
{
        double r;
        vector<double> axis(3);
        for (double &i : axis) cin >> i;
        cin >> r;
        r *= 2;
        cout << (count_if(axis.begin(), axis.end(), [=](double l)->bool{return l < r;}) >= 1 ? "N" : "Y");
}

void _3(void)
{
        double ave, sum = 0.0;
        vector<double> arr(10);
        for (double &i : arr) {
                cin >> i;
                sum += i;
        }

        ave = sum / 10.0;
        double temp = 0;
        for (double i : arr) {
                temp += pow((i - ave), 2.0);
        }
        printf("%.3f", sqrt(temp / 10.0));
}

bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); ++i) {
                if (n % i == 0) {
                        return false;
                }
        }
        return true;
}
void _4(void)
{
        int n;
        cin >> n;
        for (int i = n-1; i >= 2; --i) {
                if (isPrime(i)) {
                        cout << i;
                        return;
                }
        }
}

void _5(void)
{
        vector<int> arr(3);
        for (int &i : arr) cin >> i;
        sort(arr.begin(), arr.end());
        int res = 2;
        for (int i = 1; i >= 0; --i) {
                if (abs(6 - arr[i]) <= abs(6 - arr[res])) res = i;
        }
        cout << arr[res];
}

class Line {
public:
        Line() {
                cin >> this->st.first >> this->st.second >> this->ed.first >> this->ed.second;
                k = (this->ed.second - this->st.second) / (this->ed.first - this->st.first);
        }

        pair<double, double> st;
        pair<double, double> ed;
        double k;
};
void _6(void)
{
        Line l1, l2;
        // 斜率：k = (y2 - y1) / (x2 - x1);
        cout << (l1.k == l2.k ? "YES" : "NO");
}

void _7(void)
{
        int m, n;
        cin >> m >> n;
        int count = 0;
        int carry = 0;
        while (m != 0 && n != 0) {
                carry = (carry + (m % 10) + (n % 10)) / 10;
                m /= 10, n /= 10;
                if (carry != 0) count++;
        }
        cout << count;
}

void _8(void)
{
        string str;
        cin >> str;
        int len = str.size();
        int i;
        bool flag = false;
        for (i = len-1; i >= 0; --i) {
                if (str[i] != '0') {
                        flag = true;
                        break;
                }
        }

        if (!flag) {
                cout << 0;
                return;
        }

        int count = 0;
        while (str[i--] != '.') {
                count++;
        }
        if (count > 5) cout << "EX";
        else cout << count;
}

struct Node {
        int left, right;
};
int getDiameter(vector<Node> &T, int cur, int &maxDep, int &offset, bool &flag, int level) {
        maxDep = max(level, maxDep);
        if (T[cur].left == -1 && T[cur].right == -1) return 1;// 叶子结点
        else if (T[cur].left != -1 && T[cur].right != -1) {
                flag = true;
                return min(getDiameter(T, T[cur].left, maxDep, offset, flag, level + 1) + 1
                           , getDiameter(T, T[cur].right, maxDep, offset, flag, level + 1) + 1);
        }
        if (!flag) offset--;
        int &left = T[cur].left != -1 ? T[cur].left : T[cur].right;
        return getDiameter(T, left, maxDep, offset, flag, level + 1) + 1;
}
void _9(void)
{
        int n;
        cin >> n;
        vector<Node> T(n+1, {-1, -1});
        int x, y;
        for (int i = 1; i < n; ++i) {
                cin >> x >> y;
                if (T[x].left == -1) T[x].left = y;
                else T[x].right = y;
        }

        int maxDep = 0, cur = 1, offset = 0, level = 1;
        bool flag = false;
        int minDep = getDiameter(T, cur, maxDep, offset, flag, level);
        minDep--, maxDep--;
        cout << 2 * offset + minDep + maxDep;

}

bool check(vector<int> &_map, int curRow, int pos) {
        for (int i = 0; i < curRow; ++i) { // 测试第一行到当前行的上一行的各个点
                if (_map[i] == pos || _map[i] + (curRow - i) == pos || _map[i] - (curRow - i) == pos) return false;
        }
        return true;
}
void szQueen(vector<int> &_map, int sz, int curRow, int &amount) { //
        if (curRow == sz) { // 找到一个合法的放法
                amount++;
                return;
        }
        for (int i = 0; i < sz; ++i) {
                if (check(_map, curRow, i)) { // 测试一行中的某个放置位置是否合法
                        _map[curRow] = i;
                        szQueen(_map, sz, curRow + 1, amount); // 当前点通过测试立即看下一行
                }
        }
}
void countValid(int sz, int &amount) // 计算 N * N 的棋盘上，N 个皇后的正确放法数
{
        for (int i = 0; i < sz; ++i) { // 指定第一行的每个位置放置皇后作为初始值
                vector<int> _map(sz, -1);
                _map[0] = i; // 指定第一行放置位置
                szQueen(_map, sz, 1, amount);
        }
}
// N 皇后问题，输入 n 个测例，计算放法
void _10(void)
{
        int n;
        cin >> n;
        vector<int> res(14, -1);
        int sz, amount;
        for (int i = 0; i < n; ++i) {
                cin >> sz;
                amount = 0;
                if (res[sz] == -1) {
                        countValid(sz, amount);
                        res[sz] = amount;
                }
                cout << res[sz] << endl;
        }
}

int main(void)
{
        _10();

        return 0;
}
