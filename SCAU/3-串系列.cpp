/*
 * 3. 串相关算法
 * Notice : 不管 OJ 给出的框架，直接使用 C++ STL 容器
 * 纯属背下来的代码，理解原理还需看 dfa 自动状态转移机方法
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 清华教材源代码，[0] 存的是字符串的长度
//void get_next(SString T, int next[]) {
//	int i = 1, next[1] = 0, j = 0;
//	while (i < T[0]) {
//		if (j == 0 || T[i] == T[j]) ++i, ++j, next[i] = j;
//		else j = next[j];
//	}
//}
//void get_nextval(string pat, vector<int> &nextval) {
//        size_t i = 1, j = 0;
//        nextval.push_back(0);
//        while (i < pat.size()) {
//                if (j == 0 || pat[i] == pat[j]) {
//                        ++i, ++j; // 前进
//                        if (pat[i] != pat[j]) nextval[i] = j; // 无重复字符情况
//                        else nextval[i] = nextval[j]; // 修正
//                }
//                else j = nextval[j-1]; // 回退
//        }
//}
//int Index_KMP(string str, string pat, int pos) {
//        // 利用模式串 T 的 next 函数求 T 在主串中下标 pos 之后的位置
//        // T 非空， 1 <= pos <= StrLength(S)
//        vector<int> next;
//        get_next(pat, next);
//
//        for (int i : next) cout << i << ' ';
//        cout << endl;
//
//        size_t i = pos, j = 0;
//        while (i < str.size() && j < pat.size()) {
//                if (str[i] == pat[j]) ++i, ++j; // 前进
//                else j = next[j]; // 模式串右移
//        }
//
//        if (j > pat.size()) return i - pat.size();
//        else return -1;
//}
// C++ 改造
void getNext(string pat, vector<int> &next)
{
        next = {0};
        int i = 1, j = 0, len = pat.size();
        while (i < len) {
                if (j == 0 || pat[i-1] == pat[j-1]) ++i, ++j, next.push_back(j);
                else j = next[j-1];
        }
}

// 1. 计算 next 数组
void calNext(void)
{
        int n;
        cin >> n;
        string pat;
        for (int i = 0; i < n; ++i) {
                vector<int> next;
                cin >> pat;
                getNext(pat, next);
                cout << "NEXT J is:";
                for (int j : next) cout << j;
                cout << endl;
        }
}

// 2. KMP 算法，使用 next 数组回退匹配
void kmp(void)
{
        int n;
        cin >> n;
        string str, pat;
        for (int i = 0; i < n; ++i) {
                vector<int> next;
                cin >> str >> pat;
                getNext(pat, next);
                int j = 0, k = 0, s = str.size(), p = pat.size();
                while (j < s && k < p) {
                        if (k == -1 || str[j] == pat[k]) ++j, ++k;
                        else k = next[k] - 1; // 注意要对背下来的 next 数组计算值偏移使用
                }
                if (k == p) cout << j - k + 1 << endl;
                else cout << 0 << endl;
        }
}

int main(void)
{
        ios::sync_with_stdio(false);
        kmp();

        // 测试
//        vector<int> next;
//        getNext("aaabaaab", next); // "abcaby" : 011123，但要用的话应该为 -1 0 0 0 1 2，下标对应没错
//        for (int i : next) cout << i << ' ';
//        cout << endl;

        return 0;
}

// 《算法4》解释，暂略，直接背 KMP 一维版
//void kmpDFA(string pat)
//{
//
//}
//int dfaSearch(string str, string pat)
//{
//        int M = pat.size();
//        int N = str.size();
//        int j = 0;
//        for (int i = 0; i < N; ++i) {
//                // 状态 j 遇到字符 str[i]
//                j = dp[j][pat[i]];
//                if (j == M) return i - M + 1; // 匹配完成，返回开头索引
//        }
//        return -1;
//}
