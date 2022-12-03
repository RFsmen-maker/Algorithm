/*
* A trial of leetcode: 1109
* 第一次尝试暴力算法，超时
* 第二次看题解，学会差分数组
*/
#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> solution(void)
{
        vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
        int n = 5;

        vector<int> answer(n+1, 0);
        for(auto it = bookings.begin(); it != bookings.end(); it++)
        {
                answer[(*it)[0]-1] += (*it)[2];
                answer[(*it)[1]] -= (*it)[2];
        }
        answer.pop_back();
        for(int i = 1; i < n; i++)
        {
                answer[i] += answer[i-1];
        }

        return answer;
}

int main(void)
{
        vector<int> temp = solution();
        for(auto it = temp.begin(); it != temp.end(); it++)
        {
                cout << *it << endl;
        }

        return 0;
}
