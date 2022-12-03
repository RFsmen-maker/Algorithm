#include <stdio.h>
#include <math.h>

#define MAX 10000

int main(void)
{
        unsigned long n;
        scanf("%ul", &n);
        int i, j, flag = 1, count = 0;
        int primeCount = 3;
        unsigned long prime[MAX] = {1, 2, 3};
        for(i = 4; i <= n; i++)
        {
                for(j = 2; j <= sqrt(i); j++)
                {
                        if(i % j == 0)
                        {
                                flag = 0;
                                break;
                        }
                }
                if(flag)
                {
                        prime[primeCount++] = i;
                }
                flag = 1;
        }

        for(i = 1; i < primeCount; i++)
        {
                if(prime[i] - prime[i-1] == 2)
                        count++;
        }
        printf("%d", count);

        return 0;
}
