#include <stdio.h>

int main(void)
{
        long long a, b, c;
        int n, count = 0;
        int judge[10];
        char *judgement[2] = {"false", "true"};

        scanf("%d", &n);
        while(n--)
        {
                scanf("%lld%lld%lld: ", &a, &b, &c);
                if(a + b > c)
                        judge[count++] = 1;
                else
                        judge[count++] = 0;
        }

        for(n = 0; n < count; n++)
        {
                printf("Case #%d: %s", n+1, judgement[judge[n]]);
                if(n != count - 1)
                       putchar('\n');
        }

        return 0;
}
