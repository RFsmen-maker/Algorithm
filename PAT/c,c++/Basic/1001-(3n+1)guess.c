#include <stdio.h>

int main(void)
{
        unsigned int n, count = 0;

        scanf("%u", &n);
        while(n != 1)
        {
                if (n % 2)//ÆæÊý
                        n = (3 * n + 1) / 2;
                else
                        n /= 2;
                count++;
        }
        printf("%d", count);

        return 0;
}
