/*
 * p1014 普及 Cantor 表
 * 1/1, 1/2, 1/3...
 * 2/1, 2/2, 2/3...
 * 3/1, 3/2, 3/3...
 * 1. 1/1; 2. 1/2; 3. 2/1; 4. 3/1; 5. 2/2...
*/

#include <iostream>
#include <cmath>

using namespace std;

#include <iostream>
using namespace std;

// 群内大佬解法
int main3() {
	int n, k=1;
	cin >> n;
	while (n > k) {
		n = n - k;
		k++;
	}
	if (k % 2 == 0) {
		cout << n << "/" << n - k + 1;
	}
	else {
		cout << k - n + 1 << "/" << n;
	}
	return 0;
}

int main(void)
{
        int temp, total, lev;
        double N, seq;
        cin >> N;
        // 算层数
        temp = static_cast<int>(-0.5 + sqrt(1.0 + 8.0 * N) / 2.0);
        lev = temp;
        // 序数
        seq = N - static_cast<int>((1.0 + lev) * lev / 2.0);
        if (seq == 0) {
                lev -= 1.0;
                seq = N - static_cast<int>((1.0 + lev) * lev / 2.0);
        }
        total = lev + 2;

        int up, down;
        if (lev & 1) { // 奇数层，从右边开始
                down = total - seq;
                up = total - down;
        } else { // 偶数层，从左边开始
                up = total - seq;
                down = total - up;
        }
        cout << up << '/' << down << endl;

        return 0;
}
