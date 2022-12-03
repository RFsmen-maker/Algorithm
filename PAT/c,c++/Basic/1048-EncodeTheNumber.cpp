/*
* Basic-1048 Encode the Number
* 题目隐含意思未明
* B 长于 A 时，到 B 的长度为止，或者补上 0？
* A 长于 B 时，到 A 的长度为止，或者不上 0？
* 遇到问题：测试点 2、5 错误
* 没考虑到前面的几位为 0 的情况：但改进无效
* input: 1212 1212; output: 0404
* 根据网查，尝试补 0 计算，可以通过
*/
#include <iostream>
#include <stack>

using namespace std;

void handle(char &ch);

int main(void)
{
        char tempCh;
        stack<char> A, B, re;

        while((tempCh = getchar()) != ' ')
                A.push(tempCh - '0');
        while((tempCh = getchar()) != '\n')
                B.push(tempCh - '0');

        // 计算登长部分的结果
        int i, sizeA = A.size(), sizeB = B.size();
        for(i = 1; i <= sizeA && i <= sizeB; i++)
        {
                if(i % 2) tempCh = (A.top() + B.top()) % 13;
                else tempCh = B.top() - A.top();
                A.pop(), B.pop();
                handle(tempCh);
                re.push(tempCh);
        }

        // A 更长的情况
        while(i <= sizeA)
        {
                if(i % 2) tempCh = (A.top() + 0) % 13;
                else tempCh = 0 - A.top();
                handle(tempCh);
                re.push(tempCh);
                A.pop(), i++;
        }

        // B 更长的情况
        while(i <= sizeB)
        {
                if(i % 2) tempCh = (0 + B.top()) % 13;
                else tempCh = B.top() - 0;
                handle(tempCh);
                re.push(tempCh);
                B.pop(), i++;
        }

        // 去掉结果前面的 0
        if(re.size() == 1 && re.top() == '0') cout << 0;
        else {
                while(re.size() != 1)
                {
                        if(re.top() == '0') re.pop();
                        else break;
                }
                while(!re.empty()) {
                        cout << re.top();
                        re.pop();
                }
        }

        return 0;
}

void handle(char &ch)
{
        if(ch < 0) ch += 10;
        switch(ch)
        {
        case 10: ch = 'J'; return;
        case 11: ch = 'Q'; return;
        case 12: ch = 'K'; return;
        default: ch += '0'; return;
        };
}
