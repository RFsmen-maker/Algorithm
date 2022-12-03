#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
        int n, i, j, temp, count, l, k;
        bool flag;
        //输入n与n个整数并排列
        cin >> n;
        int num[n];
        cin >> num[0];
        for(i = 1; i < n; i++)
        {
                cin >> num[i];
                for(j = i; j > 0; j--)
                {
                        if(num[j] > num[j-1]) {
                                temp = num[j];
                                num[j] = num[j-1];
                                num[j-1] = temp;
                        }
                }
        }
        //计算m行n列
        flag = 0;
        for(i = sqrt(n); i <= n; i++) //m
        {
                for(j = sqrt(n); j > 0; j--) //n
                {
                        if(i * j < n)
                                break;
                        if(i * j == n)
                        {
                                flag = 1;
                                break;
                        }
                }
                if(flag)
                        break;
        }
        //填充螺旋矩阵
        int result[i][j];
        count = l = k = temp = 0;
        flag = 1;
        while(1)
        {
                if(count == n)
                        break;
                if(flag) {
                        if(k != j - temp - 1) {
                                result[l][k++] = num[count++];
                                continue;
                        }
                        else {
                               if(l != i - temp - 1) {
                                        result[l++][k] = num[count++];
                                        continue;
                               }
                        }
                        flag = 0;
                        temp++;
                }
                else {
                        if(k != temp - 1) {
                                result[l][k--] = num[count++];
                                continue;
                        }
                        else {
                                if(l != temp) {
                                        result[l--][k] = num[count++];
                                        continue;
                                }
                        }
                        flag = 1;
                }
        }
        //输出矩阵
        for(l = 0; l < i; l++)
        {
                for(k = 0; k < j; k++)
                {
                        cout << result[l][k];
                        if(k != j-1)
                                cout << ' ';
                }
                if(l != i-1)
                        cout << endl;
        }

        return 0;
}
