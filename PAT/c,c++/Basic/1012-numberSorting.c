#include <stdio.h>

int main(void)
{
        int n;
        int count[5] = {0};
        int result[5] = {0};
        int input;
        scanf("%d", &n);
        while(n--)
        {
                scanf("%d", &input);
                switch(input%5)
                {
                case 0:
                        if(!(input % 2))
                        {
                                count[0]++;
                                result[0] += input;
                        }
                        break;
                case 1:
                        count[1]++;
                        if(count[1] % 2)
                                result[1] += input;
                        else
                                result[1] -= input;
                        break;
                case 2:
                        count[2]++;
                        result[2]++;
                        break;
                case 3:
                        count[3]++;
                        result[3] += input;
                        break;
                case 4:
                        count[4]++;
                        result[4] = input > result[4] ? input : result[4];
                        break;
                }
        }

        double a4;
        a4 = (double) result[3] / count[3];

        for(int i = 0; i < 5; i++)
        {
                if(count[i])
                {
                        switch(i)
                        {
                        case 0:
                        case 1:
                        case 2:
                        case 4:
                                printf("%d", result[i]);
                                break;
                        case 3:
                                printf("%.1f", a4);
                        }
                }
                else
                {
                        putchar('N');
                }
                if(i != 4)
                        putchar(' ');
        }


        return 0;
}
