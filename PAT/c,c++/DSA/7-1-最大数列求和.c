/*
DSA-7-1 最大子列求和问题
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

//        // 全为负数打印 0
//        if(test) {
//                printf("0");
//                return 0;
//        }
//
//        // 分段
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
//        // 只有一段且全为正数
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
//        // 分段求和，形成一正一负的子列数组
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
//        // 过滤只有一段正数的情况
//        int start = secSum[0] >= 0 ? 0 : 1;
//        int end = secSum[knotCo-1] >= 0 ? knotCo-1 : knotCo - 2;
//        if(start == end) {
//                printf("%d", secSum[start]);
//                return 0;
//        }
//
//        // 开始跨越负数子列和
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
//        // 过滤全部跨越的情况
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
