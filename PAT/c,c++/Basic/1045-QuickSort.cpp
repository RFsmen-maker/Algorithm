/*
Basic-1045 Quick Sort
基本思想：左递减，右递增检查。
测试点 2，5 不过
排除：
1. 0 个数符合的情况
2. 元素相等时的情况
3. 题目只要求正整数，排除负数的情况

解决：
测试点 2：格式问题，加多一个空行解决（说好的“结尾无空行”？）
测试点 5：算法有问题，没有更新最大值和最小值
例子：1 2 3 3 2 1 1 2 3 10
*/
#include <iostream>

using namespace std;

int main(void)
{
        int N;
        cin >> N;
        long long arr[N];
        for(int i = 0; i < N; i++)
        {
                cin >> arr[i];
        }

        bool check[N] = {0};
        long long tempMaxMin = arr[0];
        for(int i = 0; i < N-1; i++)
        {
                if(!check[i]) {
                        tempMaxMin = arr[i];
                }
                if(tempMaxMin > arr[i+1]) {
                        check[i] = check[i+1] = 1;
                }
                else {
                        tempMaxMin = arr[i+1];
                }
        }
        tempMaxMin = arr[N-1];
        for(int i = N-1; i > 0; i--)
        {
                if(!check[i]) {
                        tempMaxMin = arr[i];
                }
                if(tempMaxMin < arr[i-1]) {
                        check[i] = check[i-1] = 1;
                }
                else {
                        tempMaxMin = arr[i-1];
                }
        }

        int tempCo = 0;
        int flag[N] = {0};
        for(int i = 0; i < N; i++)
        {
                if(!check[i]) {
                        flag[tempCo++] = i;
                }
        }

        if(tempCo) {
                cout << tempCo << endl;
                for(int i = 0; i < tempCo-1; i++)
                {
                        cout << arr[flag[i]] << ' ';
                }
                cout << arr[flag[tempCo-1]] << endl;
        }
        else {
                cout << tempCo << endl << endl;
        }

        return 0;
}
