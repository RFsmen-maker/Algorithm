/*
* 双指针移动窗口法
* 1. 要注意边界
* 2. 想到搜索到的重复字符不在窗口中的情况
* 3. 一定要考虑字符串为空的情况
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 官方解法
#include <unordered_map>
int lengthOfLongestSubstring1(string s)
{
        if(s.length() == 0) return 0;
        unordered_map<char, int> hashTable;

        int len = s.length(), maxLength = 0, currentLength = 0, startIndex = 0;
        for(int i = 0; i < len; i++)
        {
                if(hashTable.find(s[i]) == hashTable.end()) {
                        currentLength++;
                        hashTable[s[i]] = i;
                }
                else {
                        if(currentLength > maxLength) maxLength = currentLength;
                        startIndex = max(hashTable[s[i]], startIndex);
                        currentLength = i - startIndex;
                        hashTable[s[i]] = i;
                }
        }

        if(currentLength > maxLength) maxLength = currentLength;
        return maxLength;
}

int lengthOfLongestSubstring(string s)
{
        if(s.empty()) return 0;
        else if(s.size() == 1) return 1;

        int temp, max, left, count;
        int len = s.size();

        int record[128];
        memset(record, 0, 128 * sizeof(int));
        record[static_cast<int>(s[0])] = 1; // 存最后一次发现的次序

        max = count = left = 1;
        for(int right = 1; right < len; ++right)
        {
                temp = static_cast<int>(s[right]);
                if(record[temp] >= left) {
                        if(count > max) max = count;
                        left = record[temp];
                        count = right + 1 - record[temp];
                }
                else count++;
                record[temp] = right + 1;
        }

        return count > max ? count : max;
}

int main(void)
{
        cout << lengthOfLongestSubstring1("abba");

        return 0;
}
