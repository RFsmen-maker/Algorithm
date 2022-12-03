/*
* Basic-1059 C Lan Contest
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool checkPrime(int n);

int main(void)
{
        int N, tempIn;
        int arr[10000] = {0};
        vector<int> re, check;
        vector<int>::iterator it;

        // 读入结果，将排名存储在 arr 数组里面
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
                cin >> tempIn;
                re.push_back(tempIn);
                arr[tempIn] = i;
        }

        // 读入待查序列
        cin >> N;
        for(int i = 0; i < N; i++)
        {
                cin >> tempIn;
                check.push_back(tempIn);
        }

        // 遍历待查序列并输出结果
        for(auto i = check.begin(); i != check.end(); i++)
        {
                cout.fill('0');
                cout.width(4);
                if(arr[*i] == 0) cout << *i << ": Are you kidding?";
                else if(arr[*i] == -1) cout << *i << ": Checked";
                else {
                        if(arr[*i] == 1) cout << *i << ": Mystery Award";
                        else {
                                if(checkPrime(arr[*i])) cout << *i << ": Minion";
                                else cout << *i << ": Chocolate";
                        }
                        arr[*i] = -1;
                }
                if(i+1 != check.end()) cout << endl;
        }

        return 0;
}

bool checkPrime(int n)
{
        for(int i = sqrt(n); i > 1; i--)
        {
                if(n % i == 0) return false;
        }
        return true;
}
