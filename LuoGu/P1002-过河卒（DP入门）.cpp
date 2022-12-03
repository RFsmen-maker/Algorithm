/*
 * NOIP 2002 �ռ��������䣬�� A �㵽 B ���·������
 * DP ������
 * Note:
 * ���̴�С�����̶��������޶��� A��B ��ĶԽǷ�Χ��
 * intput: Bx, By, Hx, Hy
 * RE������Խ�磬��������ڴ��ͷ�
 * WA���ͷ��ڴ�˳�����
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int Bx, By, Hx, Hy;

long long countStep(bool **table);

int main(void)
{
        cin >> Bx >> By >> Hx >> Hy;
        if (Bx == Hx && By == Hy) {
                cout << 0;
                return 0;
        }

        // ������̲���ʼ��
        bool **table;
        table = (bool **)malloc(sizeof(bool *) * (Bx + 1));
        for (int i = 0; i <= Bx; ++i)
        {
                table[i] = (bool *)malloc(sizeof(bool) * (By + 1));
                for (int j = 0; j <= By; ++j)
                {
                        table[i][j] = false;
                }
        }

        // ��������Ƶ�
        if (Hx <= Bx && Hy <= By) table[Hx][Hy] = true;
        int conX, conY;
        int offset[2][2] = {{-1, +1}, {-2, +2}};
        for (int i = -2; i <= 2; ++i)
        {
                if (i == 0) continue;
                conX = Hx + i;
                if (conX < 0 || conX > Bx) continue;
                for (int j = 0; j < 2; ++j)
                {
                        conY= Hy + offset[2 - abs(i)][j];
                        if (conX == 0 && conY == 0) {
                                cout << 0;
                                return 0;
                        }
                        if (conY < 0 || conY > By) continue;
                        table[conX][conY] = true;
                }
        }

        // ���㲽��
        cout << countStep(table);

        // ���̲��ԣ��ͷ��ڴ�
        for (int i = Bx; i >= 0; --i)
        {
//                for (int j = 0; j <= By; ++j)
//                {
//                        if (i == 0 && j == 0) cout << "A\t";
//                        else if (i == Hx && j == Hy) cout << "Horse\t";
//                        else if (i == Bx && j == By) cout << "B\t";
//                        else cout << (table[i][j] ? "true\t" : "false\t");
//                }
//                cout << endl;
                free(table[i]);
        }

        return 0;
}

long long countStep(bool **table)
{
        long long step[Bx+1][By+1];
        step[0][0] = 1;
        // ��ʼ��
        for (int i = 1; i <= By; ++i) step[0][i] = table[0][i] ? 0 : step[0][i-1];
        for (int i = 1; i <= Bx; ++i) step[i][0] = table[i][0] ? 0 : step[i-1][0];
        for (int i = 1; i <= Bx; ++i)
        {
                for (int j = 1; j <= By; ++j)
                {
                        step[i][j] = table[i][j] ? 0 : (step[i-1][j] + step[i][j-1]);
                }
        }

        return step[Bx][By];
}
