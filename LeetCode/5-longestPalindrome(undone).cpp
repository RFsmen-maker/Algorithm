/*
 * 5. 最长回文子串
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 双指针法，统计前缀和与后缀和并进行对比
string longestPalindrome(string s)
{

}

// 首先尝试暴力法
bool isPalindrome(string s)
{
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
                if (s[left] != s[right]) return false;
                left++, right--;
        }
        return true;
}
string longestPalindrome_Brute(string s)
{
        int len = s.size();

}

int main(void)
{
        vector<string> str = {"babad", "cbbd"};
        for (string s : str) cout << longestPalindrome_Brute(s) << endl;

        return 0;
}

