/*
* 66. 加一
* 一个整数组成的非空数组表示负整数，加一
* 每个元素单个数字，高位放前面
* 显然，问题的关键在于考虑进位
*/
#include <iostream>
#include <vector>

using namespace std;

// 优化代码逻辑：从一开始就处理 999 + 1 的情况
vector<int> plusOne1(vector<int>& digits)
{
        int len = digits.size();
        for(int i = len - 1; i >= 0; --i)
        {
                if(digits[i] != 9) { // 个位没有进位，就直接结束了
                        digits[i]++;
                        return digits;
                } else { // 有进位，这一位为 0
                        digits[i] = 0;
                }
        }
        // 如果数组元素都是 9，那么在头位置插入 1
        vector<int> dest(len+1, 0);
        dest[0] = 1;
        return dest;
}

// 逻辑混乱因为我思路是加上任意个位数，代码风格也乱，总是纠结
// 要注意针对题目条件，没必要自行扩展
#include <algorithm>
vector<int> plusOne(vector<int>& digits)
{
        if(digits.size() == 1 && digits.back() < 9) {
                return {digits.back()+1};
        }
        bool carryBit = false;
        vector<int> dest;
        int temp = digits.back() + 1;
        if(temp >= 10) {
                carryBit = true;
                temp -= 10;
        }
        dest.push_back(temp);
        digits.pop_back();
        do
        {
                if (carryBit) {
                        carryBit = false;
                        if (digits.empty()) {
                                dest.push_back(1);
                                break;
                        } else {
                                digits.back() += 1;
                        }
                }
                temp = digits.back();
                if (temp >= 10) {
                        carryBit = true;
                        temp -= 10;
                }
                dest.push_back(temp);
                digits.pop_back();
        } while (!digits.empty() || carryBit);
        reverse(dest.begin(), dest.end());

        return dest;
}

int main(void)
{
        vector<int> arr = {9};
        vector<int> result = plusOne1(arr);
        for(int num : result) cout << num << endl;

        return 0;
}
