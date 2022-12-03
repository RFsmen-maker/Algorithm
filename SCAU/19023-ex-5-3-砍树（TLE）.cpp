/*
 * 19023-ex5.3 砍树
 * 我自己的 TLE， 同样的时间复杂度，博客的能行
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m; // 1 <= n <= 1000000, 1 <= m <= 2000000000，可能超时 T = O(nlogn)

// 参考博客改造
bool check(vector<long long> &T, int mid) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
                if (T[i] >= mid) sum += (T[i] - mid);
                if (sum >= m) return true;
        }
        return sum >= m;
}

long long bsearch(vector<long long> &T, long long left, long long right) {
        long mid;
        while (left < right) {
                mid = left + ((right - left + 1) >> 1);
                if (check(T, mid)) left = mid;
                else right = mid - 1;
        }
        return left;
}

int main(void)
{
        scanf("%lld%lld", &n, &m);
        vector<long long> T(n);
        long long left = 0, right = 0;
        for (long long i = 0; i < n; ++i) {
                scanf("%lld", &T[i]);
                if (T[i] > right) right = T[i];
        }

        printf("%lld", bsearch(T, left, right));

        return 0;
}
