/*
 * 18943. 小易爱回文
*/
#include <iostream>
#include <string>

using namespace std;

string str;
size_t len;

// 双指针法，左右两边向内夹逼，遇到不同的，右指针到末尾字符，遇到相同的，一起向内推进
// 最终找到中间对称点，再往左右两边扩，右指针到末尾就添加字符
void doublePointer(string str)
{
        size_t left = 0, right = len-1;
        while (left < right) // 左右夹逼
        {
                if (str[left] == str[right]) right--;
                else right = len-1;
                left++; // 优化，从左边开始遍历，遇到相同，右指针往前，不同，回去
        }

        // 完成后，left 停留在目标回文串的一半处，如果是奇数长，刚好在中间，如果偶数，在中点右边
        while (right != len - 1) left--, right++; // 让 right 回到末尾，让 left 走到部分回文串的头
        while (left > 0) str.push_back(str[--left]); // 补充回文串 1234<<>>(4321)

        cout << str;
}

int main(void)
{
        cin >> str;
        len = str.size();

        if (len == 1) {
                cout << str;
                return 0;
        }

        doublePointer(str);

        return 0;
}

