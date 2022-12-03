#include <stdio.h>

int main(void)
{
        int array[101];
        int *head, *tail;
        int m, n, i, count = 0;

        scanf("%d%d", &n, &m);
        while(n--)
                scanf("%d", &array[count++]);

        while(m >= count)
                m -= count;

        tail = &array[0];
        head = &array[count - m];

        for(i = 0; i < m; i++)
                printf("%d ", *(head+i));
        for(i = 0; i < count - m; i++)
        {
                printf("%d", *(tail+i));
                if(i != count - m - 1)
                        putchar(' ');
        }

        return 0;
}
