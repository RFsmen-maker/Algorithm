/*
Basic-1045 Quick Sort
����˼�룺��ݼ����ҵ�����顣
���Ե� 2��5 ����
�ų���
1. 0 �������ϵ����
2. Ԫ�����ʱ�����
3. ��ĿֻҪ�����������ų����������

�����
���Ե� 2����ʽ���⣬�Ӷ�һ�����н����˵�õġ���β�޿��С�����
���Ե� 5���㷨�����⣬û�и������ֵ����Сֵ
���ӣ�1 2 3 3 2 1 1 2 3 10
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
