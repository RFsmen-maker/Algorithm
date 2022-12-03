/*
 * ex2.11 舞伴问题
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        // 直接填满到 k
        int l1, l2, k;
        cin >> l1 >> l2 >> k;

        vector<int> L1, L2;
        int count = 0;
        while (count < k) {
                L1.push_back(count % l1);
                L2.push_back(count % l2);
                count++;
        }
        cout << L1[k-1] + 1 << ' ' << L2[k-1] + 1;

        return 0;
}

