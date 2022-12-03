/*
 * 8585-2.3 十进制转八进制
 * times : 2
*/
#include <iostream>
#include <stack>

using namespace std;

// 先假设不是超长整数
int main(void)
{
        stack<int> s;
        long long n; // 先不管会不会超长
        cin >> n;
        while (n) {
                s.push(n % 8);
                n >>= 3;
        }
        while (!s.empty()) {
                cout << s.top();
                s.pop();
        }

        return 0;
}
