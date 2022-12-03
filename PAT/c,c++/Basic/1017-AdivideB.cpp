#include <iostream>
/*思路：
input：char A[1001], int B
handle：
        分类讨论情况：
        0）除数为 0
        1）被除数为 1
        2）除数小于被除数，被除数为一位数，因此除数第二位字符一定为 ‘\0'
        3）正常输入
                0.循环开始一位一位载入到 R
                1. R >= B: 取商到 Q，R = 余数
                2. 余数两种情况：
                        I: R != 0,不需特殊处理
                        II: R == 0：后面有 0 ，直接载入到 Q，直到非0或到 A 结束：
                                非 0 两种情况：0, !0
                                A结束：
                3. R *= 10, R += A下一位

output: char B[1001], int R

*/
using namespace std;

int main(void)
{
        char A[1001], Q[1001];
        int B, R, i, j, count;
        cin >> A >> B;

        if(A[0] == '0')
                cout << "0 0";
        else if(B == 1)
                cout << A << " " << 0;
        else if((A[0] - '0') < B && A[1] == '\0')
                cout << "0 " << A;
        else {
                i = j = R = 0;
                do {
                        R += A[i] - '0';
                        if(R >= B) {
                                Q[j] = '0';
                                Q[j++] += R / B;
                                R %= B;
                                if(R == 0) {
                                        i++;
                                        count = 0;
                                        while(A[i] != '\0' && A[i] == '0') {
                                                count++;
                                                i++;
                                        }
                                        if(A[i] == '\0') {
                                                i--;
                                        }
                                        else if(A[i] != '\0' && A[i] != '0') {
                                                R = A[i] - '0';
                                                if(R < B) {
                                                        Q[j++] = '0';
                                                        if(A[i+1] == '\0') { //是否最后一个
                                                                i--;
                                                                R = 0;
                                                        }
                                                }
                                                else {
                                                        i--;
                                                        R = 0;
                                                }
                                        }
                                        while(count--)
                                                Q[j++] = '0';
                                }
                        }

                        i++;
                        if(A[i] != '\0')
                                R *= 10;
                }while(A[i] != '\0');
                Q[j] = '\0';

                cout << Q << " " << R;
        }
        return 0;
}
