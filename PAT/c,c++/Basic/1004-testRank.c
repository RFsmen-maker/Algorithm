#include <stdio.h>

#define MAX 100

int main(void)
{
        char name[MAX][11];
        char sequence[MAX][11];
        int score[MAX];
        int max, min;
        int n, i = 0;
        max = min = 0;
        scanf("%d", &n);
        while(n--)
        {
                scanf("%s %s %d", name[i], sequence[i], &score[i]);
                if(score[min] >= score[i])
                        min = i;
                if(score[max] <= score[i])
                        max = i;
                i++;
        }

        printf("%s %s\n", name[max], sequence[max]);
        printf("%s %s", name[min], sequence[min]);

        return 0;
}
