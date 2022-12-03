/*
 * 50. Pow(x, n): x 的 n 次方
*/
#include <iostream>

using namespace std;

// 官方解法
double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow3(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

// 参考评论区的优化，避免了隐形类型转换的影响
double myPow2(double x, int n)
{
        double dest = 1.0;
        for (auto i = n; i != 0; i /= 2)
        {
                if (i % 2) dest *= x;
                x *= x;
        }
        return n < 0 ? 1 / dest : dest;
}

// 迭代版，C++ 编程竞赛经常用位移运算
// 面试时应是最佳的
double myPow1(double x, int n)
{
        if (x == 1 || (n == 0 && x != 0)) return 1.0;

        double pow = 1.0;
        long long N = n; // 避免了 int 负上溢的情况
        if (n < 0) { // 转换负数
                x = 1 / x;
                N = -N;
        }
        while (N)
        {
                if (N & 1) pow *= x; // 模 2 判断
                x *= x;
                N >>= 1;
        }
        return pow;
}

// 怎么保持小数点后五位？去总结复习 C++ 的格式化输出
// 分治实现幂函数，左右二分劈开，分奇数和偶数 n 的情况，显然 log2(n)
// 当然，还要考虑负数指数的情况
// 但是，这样还不够，0.00001, 2147483674 超时，需要进行快速幂运算
// 溢出原因，由于 int 最小值 -2^31 比最大值 (2^31 - 1) 还少 1，不能直接 n = -n
// 这个时候可以 t = n / 2, t = -n;
double myPow(double x, int n)
{
        // cout << "test : " << n << endl;
        // 过滤特殊情况
        if (x == 0 || x == 1) return x;
        if (n == 0 && x != 0) return 1;
        // 递归终止条件
        if (n == 1) return x;
        // 正指数情况
        auto t = n / 2;
        if (n < 0) {
                t = -t;
                x = 1 / x;
        }
        double res = myPow(x, t);
        if (n % 2 == 0) return res * res;
        return res * res * x;
//        if (n > 0) {
//                // 考虑错误，这样递归会产生大量重复
//                // if (n % 2) return myPow(x, (n - 1) / 2) * myPow(x, (n - 1) / 2) * x;
//                // else return myPow(x, n / 2) * myPow(x, n / 2);
//                auto y = myPow(x, n / 2);
//                return n % 2 ? y * y * x : y * y;
//        } else { // 负数的情况
//                return 1.0 / myPow(x, -n);
//        }
}

int main(void)
{
        cout << myPow(0.00001, 2147483647);

        return 0;
}
