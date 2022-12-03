/*
 * 18937-2.9 阿克曼函数
*/
#include <iostream>

using namespace std;

int akm(int m, int n) {
        if (m == 0) return n + 1;
        else if (m > 0 && n == 0) return akm(m - 1, 1);
        else if (m > 0 && n > 0) return akm(m - 1, akm(m, n - 1));
        else return 0;
}

int main(void)
{
        int m, n;
        cin >> m >> n;
        cout << akm(m, n);

        return 0;
}

