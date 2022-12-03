#include <stdio.h>

void sort(int *input, int n)
{
        int i, j, temp;
        for(i = 0; i < n; i++)
        {
                for(j = i+1; j < n; j++)
                {
                        if(*(input+i) <= *(input+j))
                        {
                                temp = *(input+j);
                                *(input+j) = *(input+i);
                                *(input+i) = temp;
                        }
                }
        }
}

int main(void)
{
        int array[101] = {0};
        int input[101];
        int n, temp, count = 0;
        scanf("%d", &n);
        while(n--)
        {
                scanf("%d", &input[count]);
                temp = input[count];
                while(temp != 1)
                {
                        if(temp % 2)//ÆæÊý
                        {
                                temp = (temp * 3 + 1) / 2;
                                if(temp < 100)
                                        array[temp]++;
                        }
                        else//Å¼Êý
                        {
                                temp /= 2;
                                if(temp < 100)
                                        array[temp]++;
                        }
                }
                count++;
        }

        sort(input, count);
        n = 0;
        for(temp = 0; temp < count; temp++)
                if(array[input[temp]] == 0)
                        n++;
        int i = 0;
        for(temp = 0; temp < count; temp++)
        {
                if(array[input[temp]] == 0)
                {
                        printf("%d", input[temp]);
                        i++;
                        if(i < n)
                                putchar(' ');
                }
        }

        return 0;
}
