#include <stdio.h>

int main(void)
{
        int n;
        scanf("%d", &n);

        int b, s, g, i;

        g = n % 10;
        n /= 10;
        s = n % 10;
        n /= 10;
        b = n % 10;

        while(b--)
                putchar('B');
        while(s--)
                putchar('S');
        i = 1;
        while(g--)
                printf("%d", i++);

        return 0;
}
