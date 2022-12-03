/*
Basic-1050 Spiral Matrix (redo)
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
        int N;
        cin >> N;
        int *arr = new int[N];
        for(int i = 0; i < N; i++)
        {
                cin >> arr[i];
        }

        sort(arr, arr+N);

        int m, n;
        m = n = sqrt(N);
        while(m * n != N)
        {
                if(m * n < N) {
                        ++m;
                }
                else {
                        --n;
                }
        }

        bool flag = 1;
        int output[m][n];
        int row, column, temp;
        row = column = temp = 0;
        while(N)
        {
                if(N == 1) {
                        output[row][column] = arr[--N];
                        break;
                }
                if(flag) {
                        if(column < n - temp - 1) {
                                output[row][column++] = arr[--N];
                                continue;
                        }
                        if(row < m - temp - 1) {
                                output[row++][column] = arr[--N];
                                continue;
                        }
                        flag = 0;
                }
                else {
                        if(column > temp) {
                                output[row][column--] = arr[--N];
                                continue;
                        }
                        if(row > temp + 1) {
                                output[row--][column] = arr[--N];
                                continue;
                        }
                        temp++;
                        flag = 1;
                }
        }

        for(int i = 0; i < m; i++)
        {
                for(int j = 0; j < n; j++)
                {
                        cout << output[i][j];
                        if(j != n-1) {
                                cout << ' ';
                        }
                }
                if(i != m-1) {
                        cout << endl;
                }
        }

        return 0;
}
