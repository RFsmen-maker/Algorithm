/*
 * 9715. 相邻最大矩形面积
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力，遍历每条长方形，取得完全包含这条长方形的最大面积

int main(void)
{
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int &i : arr) cin >> i;

        int area = 0;
        for (int i = 0; i < N; ++i) {
                int height = arr[i];
                int width = 1;
                for (int j = i-1; j >= 0; --j) {
                        if (arr[j] >= height) width++;
                        else break;
                }
                for (int j = i+1; j < N; ++j) {
                        if (arr[j] >= height) width++;
                        else break;
                }
                area = max(area, height * width);
        }
        cout << area;

        return 0;
}
