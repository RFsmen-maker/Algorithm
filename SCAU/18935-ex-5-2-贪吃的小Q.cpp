/*
 * 18935-ex5.2 贪吃的小 Q
 */
#include <iostream>
#include <cmath>

using namespace std;

// 另一种办法：二分查找，不管数列和公式，也就是标签给的方法
int getSum(int a, int n) {
        int sum = a;
        for (int i = 1; i < n; ++i) {
                a = a / 2 + (a % 2);
                sum += a;
        }
        return sum;
}
int bSearchMethod(void)
{
        int n, m, sum;
        cin >> n >> m;
        int mid, left = 0, right = m;
        while (left +1 != right) { // 要找的是，令 sum 不大于 m 的最大一个 mid，即 left
                mid = (left + right) / 2;
                sum = getSum(mid, n);
                if (sum == m) return mid;
                else if (sum < m) left = mid; // 不够多，再加点
                else right = mid; // sum > m
        }
        return left;
}
int main(void)
{
        cout << bSearchMethod();

        return 0;
}


// 参考博客：从最后一天倒推，倒数第一天至少吃一块
// Sn = a1(2^n - 1)
int refer()
{
        int n, m, sum, val, i;
        scanf("%d%d", &n, &m);
        sum = m;
        for (i = n; i > 0; --i) {
                val = (sum - 1) / (pow(2, i) - 1) + 1;
                sum = sum - val;
        }
        printf("%d", val);
        return 0;
}

// n 天，m 块巧克力，已知 q = 1 / 2, Sn = a1 * (1 - q ^ n) / (1 - q)，求 a1
// 不能直接使用公式，因为会一步一步损失精度，先算出接近的数，再来遍历测试
int try1(void)
{
        double n, m;
        cin >> n >> m;

        if (n == 0) {
                cout << m;
                return 0;
        }

        int res = static_cast<int>(m * 0.5 / (1 - pow(0.5, n))); // 这个数不仅仅可能偏大，也可能偏小
        int sum = getSum(res, n);

        if (sum == m) {
                cout << res;
                return 0;
        }
        else if (sum > m) { // 需要向下尝试，直到 sum <= m
                while (sum > m) {
                        res--;
                        sum = getSum(res, n);
                }
        }
        else { // sum < m 需要向上尝试，直到 sum >= m
                while (sum < m) {
                        res++;
                        sum = getSum(res, n);
                }
        }

        cout << res;

        return 0;
}
