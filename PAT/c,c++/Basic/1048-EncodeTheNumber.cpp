/*
* Basic-1048 Encode the Number
* ��Ŀ������˼δ��
* B ���� A ʱ���� B �ĳ���Ϊֹ�����߲��� 0��
* A ���� B ʱ���� A �ĳ���Ϊֹ�����߲��� 0��
* �������⣺���Ե� 2��5 ����
* û���ǵ�ǰ��ļ�λΪ 0 ����������Ľ���Ч
* input: 1212 1212; output: 0404
* �������飬���Բ� 0 ���㣬����ͨ��
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

        // ����ǳ����ֵĽ��
        int i, sizeA = A.size(), sizeB = B.size();
        for(i = 1; i <= sizeA && i <= sizeB; i++)
        {
                if(i % 2) tempCh = (A.top() + B.top()) % 13;
                else tempCh = B.top() - A.top();
                A.pop(), B.pop();
                handle(tempCh);
                re.push(tempCh);
        }

        // A ���������
        while(i <= sizeA)
        {
                if(i % 2) tempCh = (A.top() + 0) % 13;
                else tempCh = 0 - A.top();
                handle(tempCh);
                re.push(tempCh);
                A.pop(), i++;
        }

        // B ���������
        while(i <= sizeB)
        {
                if(i % 2) tempCh = (0 + B.top()) % 13;
                else tempCh = B.top() - 0;
                handle(tempCh);
                re.push(tempCh);
                B.pop(), i++;
        }

        // ȥ�����ǰ��� 0
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
