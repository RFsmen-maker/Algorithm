#include <stdio.h>

#define MAX 1001

int main(void)
{
        int array[MAX];
        int count = 0;

        while(1)
        {
                scanf("%d", &array[count++]);
                if(!(count % 2))
                {
                        if(array[count-1] == 0)
                        {
                                count -= 2;
                                break;
                        }
                        array[count-2] *= array[count-1];
                        array[count-1]--;
                }
                if(getchar() == '\n')
                        break;
        }
        for(int i = 0; i < count; i++)
        {
                printf("%d", array[i]);
                if(i != count - 1)
                     putchar(' ');
        }
        if(array[1] == 0)
                printf("0 0");

        return 0;
}
