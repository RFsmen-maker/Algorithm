/*
Basic-1019 Digital Black Hole
*/
#include <iostream>
#include <algorithm>

using namespace std;

void showNum(int n)
{
        cout.width(4);
        cout.fill('0');
        cout << n;
}

void arrCopy(int dst[], int src[], int len)
{
        for(int i = 0; i < len; i++)
        {
                dst[i] = src[i];
        }
}

bool cmpDown(int a, int b)
{
        return a > b;
}

void split(int arr[])
{
        int tempIn = 1;
        for(int i = 10000; i > 1; i /= 10)
        {
                arr[tempIn++] = (arr[0] % i) / (i / 10);
        }
}

void combine(int arr[])
{
        arr[0] = 1000 * arr[1] + 100 * arr[2] + 10 * arr[3] + arr[4];
}

int main(void)
{
        int tempIn, arr[5];
        cin >> arr[0];
        split(arr);

        tempIn = 0;
        for(int i = 2; i < 5; i++)
        {
                tempIn += arr[i] - arr[i-1];
        }

        if(tempIn == 0) {
                showNum(arr[0]);
                cout << " - ";
                showNum(arr[0]);
                cout << " = 0000";
        }
        else {
                int up[5], down[5];
                do
                {
                        split(arr);
                        arrCopy(down, arr, 5);
                        arrCopy(up, arr, 5);

                        sort(up+1, up+5);
                        sort(down+1, down+5, cmpDown);
                        combine(up);
                        combine(down);
                        arr[0] = down[0] - up[0];

                        showNum(down[0]);
                        cout << " - ";
                        showNum(up[0]);
                        cout << " = ";
                        showNum(arr[0]);
                        if(arr[0] != 6174) {
                                cout << endl;
                        }
                }while(arr[0] != 6174);
        }

        return 0;
}
