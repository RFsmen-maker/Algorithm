#include <iostream>
/*˼·��
input��char A[1001], int B
handle��
        �������������
        0������Ϊ 0
        1��������Ϊ 1
        2������С�ڱ�������������Ϊһλ������˳����ڶ�λ�ַ�һ��Ϊ ��\0'
        3����������
                0.ѭ����ʼһλһλ���뵽 R
                1. R >= B: ȡ�̵� Q��R = ����
                2. �������������
                        I: R != 0,�������⴦��
                        II: R == 0�������� 0 ��ֱ�����뵽 Q��ֱ����0�� A ������
                                �� 0 ���������0, !0
                                A������
                3. R *= 10, R += A��һλ

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
                                                        if(A[i+1] == '\0') { //�Ƿ����һ��
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
