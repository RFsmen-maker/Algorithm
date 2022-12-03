/*
DSA-7-2 一元多项式乘法与加法运算
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        struct {
                _Bool zero;
                int term;
                int (*coef)[2];
        }poly1, poly2;

        poly1.zero = 0;
        scanf("%d", &poly1.term);
        if(poly1.term == 0) {
                poly1.zero = 1;
        }
        else {
                poly1.zero = 1;
                poly1.coef = (int (*)[2])malloc(poly1.term * 2 * sizeof(int));
                for(int i = 0, j = 0; i < poly1.term; i++, j++)
                {
                        scanf("%d%d", &poly1.coef[j][0], &poly1.coef[j][1]);
                        if(poly1.coef[j][0] == 0) {
                                j--;
                        }
                        else {
                                poly1.zero = 0;
                        }
                }
        }

        poly2.zero = 0;
        scanf("%d", &poly2.term);
        if(poly2.term == 0) {
                poly2.zero = 1;
        }
        else {
                poly2.zero = 1;
                poly2.coef = (int (*)[2])malloc(poly2.term * 2 * sizeof(int));
                for(int i = 0, j = 0; i < poly2.term; i++, j++)
                {
                        scanf("%d%d", &poly2.coef[j][0], &poly2.coef[j][1]);
                        if(poly2.coef[j][0] == 0) {
                                j--;
                        }
                        else {
                                poly2.zero = 0;
                        }
                }
        }

        if(poly1.zero || poly2.zero) {
                printf("0 0\n");
        }
        else {
                int realMul[4001] = {0};
                int *temp = &realMul[2000];
                for(int i = 0; i < poly1.term; i++)
                {
                        for(int j = 0; j < poly2.term; j++)
                        {
                                temp[poly1.coef[i][1]+poly2.coef[j][1]] += poly1.coef[i][0] * poly2.coef[j][0];
                        }
                }

                int mulCo = 0;
                int (*mul)[2] = (int (*)[2])malloc((poly1.term * poly2.term) * 2 * sizeof(int));
                for(int i = 4000; i >= 0; i--)
                {
                        if(realMul[i] != 0) {
                                mul[mulCo][0] = realMul[i];
                                mul[mulCo][1] = i - 2000;
                                mulCo++;
                        }
                }

                for(int i = 0; i < mulCo-1; i++)
                {
                        printf("%d %d ", mul[i][0], mul[i][1]);
                }
                printf("%d %d\n", mul[mulCo-1][0], mul[mulCo-1][1]);
                free(mul);
        }

        if(poly1.zero && poly2.zero) {
                printf("0 0");
                return 0;
        }
        if(poly1.zero) {
                poly1.term = 0;
        }
        if(poly2.zero) {
                poly2.term = 0;
        }

        int (*sum)[2] = (int (*)[2])malloc((poly1.term + poly2.term) * 2 * sizeof(int));
        int i, j, sumCo;
        i = j = sumCo = 0;
        for(i = 0, j = 0; i < poly1.term && j < poly2.term; )
        {
                if(poly1.coef[i][1] == poly2.coef[j][1] && poly1.coef[i][0] + poly2.coef[j][0] != 0) {
                        sum[sumCo][0] = poly1.coef[i][0] + poly2.coef[j][0];
                        sum[sumCo][1] = poly1.coef[i][1];
                        i++;
                        j++;
                        sumCo++;
                }
                else if(poly1.coef[i][0] + poly2.coef[j][0] == 0) {
                        i++;
                        j++;
                }
                else if(poly1.coef[i][1] > poly2.coef[j][1]) {
                        sum[sumCo][0] = poly1.coef[i][0];
                        sum[sumCo][1] = poly1.coef[i][1];
                        i++;
                        sumCo++;
                }
                else {
                        sum[sumCo][0] = poly2.coef[j][0];
                        sum[sumCo][1] = poly2.coef[j][1];
                        j++;
                        sumCo++;
                }
        }
        while(i < poly1.term)
        {
                sum[sumCo][0] = poly1.coef[i][0];
                sum[sumCo][1] = poly1.coef[i][1];
                sumCo++;
                i++;
        }
        while(j < poly2.term)
        {
                sum[sumCo][0] = poly2.coef[j][0];
                sum[sumCo][1] = poly2.coef[j][1];
                sumCo++;
                j++;
        }

        free(poly1.coef);
        free(poly2.coef);

        if(sumCo == 0) {
                printf("0 0");
                return 0;
        }

        for(int i = 0; i < sumCo-1; i++)
        {
                if(sum[i][0]) {
                        printf("%d %d ", sum[i][0], sum[i][1]);
                }
        }
        printf("%d %d", sum[sumCo-1][0], sum[sumCo-1][1]);
        free(sum);

        return 0;
}
