/*
 * 18711-ex 1.1 字符串去重
 * times : 2
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
        const int offset = static_cast<int>('a');
        vector<bool> flag(26, false);

        char ch;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
                cin >> ch;
                flag[static_cast<int>(ch) - offset] = true;
        }

        for (int i = 0; i < 26; ++i) if (flag[i]) cout << static_cast<char>(i + offset);

        return 0;
}

