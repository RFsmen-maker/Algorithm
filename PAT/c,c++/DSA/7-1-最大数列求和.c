/*
DSA-7-1 ��������������
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        // const int knotSize = 2;
        //_Bool test = 1;
        int K;
        scanf("%d", &K);
        int *arr = (int *)malloc(K * sizeof(int));
        int tempThis, tempSum;
        tempThis = tempSum = 0;
        for(int i = 0; i < K; i++)
        {
                scanf("%d", &arr[i]);
                tempThis += arr[i];
                if(tempThis > tempSum) {
                        tempSum = tempThis;
                }
                else if(tempThis < 0) {
                        tempThis = 0;
                }
//                if(arr[i] >= 0) {
//                        test = 0;
//                }
        }

        printf("%d", tempSum);
        return 0;

//        // ȫΪ������ӡ 0
//        if(test) {
//                printf("0");
//                return 0;
//        }
//
//        // �ֶ�
//        int knotCo = 0;
//        int (*knot)[knotSize] = (int (*)[knotSize])malloc(knotSize * K * sizeof(int));
//        for(int i = 0; i < K; i++)
//        {
//                if(arr[i] >= 0) {
//                        knot[knotCo][0] = i;
//                        while(arr[++i] >= 0 && i < K);
//                        i--;
//                        knot[knotCo][1] = i;
//                }
//                else {
//                        knot[knotCo][0] = i;
//                        while(arr[++i] < 0 && i < K);
//                        i--;
//                        knot[knotCo][1] = i;
//                }
//                knotCo++;
//        }
//
//        // ֻ��һ����ȫΪ����
//        if(knotCo == 1) {
//                knotCo = 0;
//                for(int i = 0; i < K; i++)
//                {
//                        knotCo += arr[i];
//                }
//                printf("%d", knotCo);
//                return 0;
//        }
//
//        // �ֶ���ͣ��γ�һ��һ������������
//        int *secSum = (int *)malloc(knotCo * sizeof(int));
//        for(int i = 0; i < knotCo; i++)
//        {
//                secSum[i] = 0;
//                for(int j = knot[i][0]; j <= knot[i][1]; j++)
//                {
//                        secSum[i] += arr[j];
//                }
//        }
//
//        // ����ֻ��һ�����������
//        int start = secSum[0] >= 0 ? 0 : 1;
//        int end = secSum[knotCo-1] >= 0 ? knotCo-1 : knotCo - 2;
//        if(start == end) {
//                printf("%d", secSum[start]);
//                return 0;
//        }
//
//        // ��ʼ��Խ�������к�
//        int maxRe = 0;
//        while(start < end)
//        {
//                if(secSum[start] + secSum[start+1] > 0) {
//                        start += 2;
//                        secSum[start] += (secSum[start-1] + secSum[start-2]);
//                }
//                else {
//                        if(secSum[start] > maxRe) {
//                                maxRe = secSum[start];
//                        }
//                        start += 2;
//                }
//        }
//
//        // ����ȫ����Խ�����
//        if(maxRe < secSum[start]) {
//                maxRe = secSum[start];
//        }
//
//        printf("%d", maxRe);
//
//        free(arr);
//        free(knot);
//
//        return 0;
}
