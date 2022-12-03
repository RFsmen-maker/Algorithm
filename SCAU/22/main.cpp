#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>

using namespace std;

void _1(void) {
        double n;
        cin >> n;

        if (n == 0) {
                cout << "0.00";
                return;
        }

        if (n <= 30.0) {
                printf("%.2lf", n * 5.0);
        }
        else { // n > 30
                printf("%.2lf", 30.0 * 5.0 + (n - 30.0) * 8.0);
        }
}


void _2(void) {
        int st, ed;
        cin >> st >> ed;
        int count = 0;
        for (int i = st; i <= ed; ++i) {
                if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) count++;
        }
        cout << count;
}

void _3(void) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n - 1; ++i) {
                int blank = i - n;
                for (int j = blank; j > 0; --j) cout << ' ';
                for (int j = n - abs(n - i); j > 0; --j) cout << '*'; // n -
                cout << endl;
        }
}

void _4(void) { // 每位数字加 6，用和除以 8 的余数再加 1？
        int n;
        cin >> n;
        stack<int> res;
        while (n) {
                int temp = n % 10;
                temp += 6;
                temp = temp % 8;
                temp += 1;
                res.push(temp);
                n /= 10;
        }
        while (!res.empty()) {
                cout << res.top();
                res.pop();
        }
}

void _5(void) {
        int n;
        cin >> n; // 1 ~ 10000

        int mul = 1;
        long long sum = 0;
        while (n) {
                // cout << "day left : " << n << ", give : " << mul * mul << endl;
                if (n >= mul) {
                        sum += mul * mul;
                        n -= mul;
                }
                else {
                        sum += n * mul;
                        break;
                }
                mul++;
        }
        cout << sum;
}

void _6(void) {
        vector<int> arr(3);
        for (int &i : arr) cin >> i;
        int firGap = abs(arr[1] - arr[0]);
        int secGap = abs(arr[2] - arr[1]);
        if (firGap > secGap) {
                cout << arr[0] + secGap;
        }
        else if (firGap == secGap) {
                cout << min({arr[0], arr[1], arr[2]}) - firGap;
        }
        else {
                cout << arr[1] + firGap;
        }
}

bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); ++i) {
                if (n % i == 0) return false;
        }
        return true;
}
int numRev(int i) {
        int len = 0;
        int temp = i;
        while (temp) {
                len++;
                temp /= 10;
        }
        int res = 0;
        len--;
        while (i) {
                res += pow(10, len--) * (i % 10);
                i /= 10;
        }

        return res;
}
void _7(void) {
        int left, right;
        cin >> left >> right;
        bool flag = true;
        for (int i = left; i <= right; ++i) {
                if (isPrime(i)) {
                        int rev = numRev(i);
                        // cout << "rev : " << rev << endl;
                        if (isPrime(rev)) {
                                cout << i << endl;
                                flag = false;
                        }
                }
        }
        if (flag) cout << "NO";
}

void chPartRev(string &str, int left, int right) {
        int count = (right - left) / 2;
        while (count >= 0) {
                swap(str[left + count], str[right - count]);
                count--;
        }
}
void _8(void) {
        string str;
        getline(cin, str, '\n');
        int st = 0;
        while (!isalpha(str[st])) st++;
        int left = st;
        for (int i = st; i < str.size(); ++i) {
                if (!isalpha(str[i])) {
                        // cout << "left : " << left << ", right : " << i - 1 << endl;
                        chPartRev(str, left, i - 1);
                        left = i;
                        while (left < str.size() && !isalpha(str[left])) left++;
                }
                if (i == str.size() - 1 && isalpha(str[i])) {
                        chPartRev(str, left, i);
                }
        }
        cout << str;
}

void _9(void) { // 合法的子串
        int n;
        cin >> n;
        string str;
        cin >> str;

        int maxVal = 0, curCount;
        stack<int> s;
        s.push(0);
        int amount = 0;

        for (int i = 0; i < n; ++i) {
                if (str[i] == '(') s.push(s.top() -1);
                else s.push(s.top() + 1);
                if (s.top() == 0) amount++;
        }
        cout << amount;
}
struct Node {
        int data;
        int left, right;
};
int dfs(vector<Node> &T, int cur, int &amount) {
        int sum = T[cur].data;
        if (T[cur].left != 0 && T[[cur].left].data > 0) sum += T[[cur].left].data;
        if (T[cur].right != 0 && T[[cur].right].data > 0) sum += T[[cur].right].data;

        return sum;
}
void _10(void) {
        int n;
        cin >> n;
        vector<Node> T(n+1, {0, 0, 0});
        for (int i = 1; i <= n; ++i) {
                cin >> T[i].data;
                // if (T[i].data < minData)
        }
        int minData = T[1].data;
        int root, x, y;
        for (int i = 1; i <= n; ++i) {
                if (T[i].data < minData) minData = T[i].data;
                cin >> root >> x >> y;
                T[root].left = x;
                T[root].right = y;
        }
        int amount = minData;
        dfs(T, 1, amount);
        cout << amount;
}
int main(void)
{
        _10();


        return 0;
}


void _11(void) {

}

void _12(void) {

}
