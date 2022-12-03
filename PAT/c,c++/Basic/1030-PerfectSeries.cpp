/*
* Basic-1030 Perfect Series
* 测试点 5 不过，根据博客，与数据类型有关？
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
        long long N, p;
        cin >> N >> p;

        long long arr[N];
        for(long i = 0; i < N; i++)
        {
                cin >> arr[i];
        }

        sort(arr, arr+N);

        long head, rear;
        head = 0;
        rear = N-1;
        while(arr[rear] > p*arr[head] && rear >= head)
        {
                if(arr[rear-1] <= p*arr[head]) {
                        rear--;
                        break;
                }
                if(arr[rear] <= p*arr[head+1]) {
                        head++;
                        break;
                }
                rear--;
                head++;
        }
        cout << rear-head+1;

        return 0;
}
