/*
* Basic-1035 Insert and Merge
* 排序目标为升序
* 考虑利用原数组判断是否为插入排序，不是插入就是归并
* 自测用例：
* 7 \n 3 1 2 8 7 5 9 \n 1 2 3 8 5 7 9
* 9 \n 3 1 2 8 7 5 9 4 0 \n 1 2 3 8 4 5 7 9 0
* 遇到问题：测试点 2、4 不过，均为插入排序检验
* 自测用例：3 \n 3 2 1 \n 3 2 1
*/
#include <iostream>
#include <cmath>

using namespace std;

void InsertSort(int arr[], int po);
void MergeCheck(int arr[], int len);

int main(void)
{
        int N, i;
        cin >> N;
        int orgArr[N], resArr[N];
        for(i = 0; i < N; i++) cin >> orgArr[i];
        for(i = 0; i < N; i++) cin >> resArr[i];

        // 先判断是否为插入排序
        // 若前面连续数个为升序且其后剩下元素一一对应原数组，则为插入排序
        int errPo = 0;
        for(i = 0; i < N-1; i++)
        {
                if(resArr[i] <= resArr[i+1]) ++errPo; // 找出错位置
                else {
                        ++errPo;
                        ++i;
                        while(orgArr[i] == resArr[i] && i < N) i++;
                        break;
                }
        }

        if(i == N && errPo) {
                cout << "Insertion Sort" << endl;
                if(i != errPo) InsertSort(resArr, errPo);
                for(i = 0; i < N-1; i++) cout << resArr[i] << ' ';
                cout << resArr[N-1];
        }
        else {
                cout << "Merge Sort" << endl;
                MergeCheck(resArr, N);
                for(i = 0; i < N-1; i++) cout << resArr[i] << ' ';
                cout << resArr[N-1];
        }

        return 0;
}

void InsertSort(int arr[], int po)
{
        int temp = arr[po];
        for(int i = po; i > 0; i--)
        {
                if(arr[i-1] > temp) {
                        arr[i] = arr[i-1];
                        if(i-1 == 0) arr[i-1] = temp; // 处理边界情况
                }
                else {
                        arr[i] = temp;
                        break;
                }
        }
}

void MergeCheck(int arr[], int len)
{
        int i, j, k;
        bool flag = 1;
        int step, time;
        step = 1;
        for(i = 2; i < len; i *= 2)
        {
                if(flag) {
                        time = len / i;
                        for(j = 0; j < time; j++)
                        {
                                if(flag)
                                for(k = j * i + 1; k < (j+1) * i; k++)
                                        if(arr[k] < arr[k-1]) {
                                                flag = 0;
                                                break;
                                        }
                        }
                }
                else break;
                if(flag) step = i;
        }

        int *temp = (int *)malloc(sizeof(int) * len);
        for(i = 0; i < len; i++) temp[i] = arr[i];
        time = len / (2*step) + 1;
        if(time * 2 * step > len) time++; // 过滤遍历次数不够的情况
        int l;
        for(i = 0; i < time; i++)
        {
                int head = 2 * i * step;
                int mid = head + step;
                if(mid > len) mid = len;
                int tail = mid + step;
                if(tail > len) tail = len;
                for(j = head, k = mid, l = j; j < mid && k < tail; l++)
                {
                        if(temp[j] <= temp[k]) arr[l] = temp[j++];
                        else arr[l] = temp[k++];
                }
                while(j < mid) arr[l++] = temp[j++];
                while(k < tail) arr[l++] = temp[k++];
        }

        free(temp);
}
