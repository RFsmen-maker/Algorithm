#include <stdio.h>

int main(void)
{
        unsigned int n;
        while(~scanf("%ld", &n))
        {
                int front, rear;
                front = 1;
                rear = 2;
                if(n > 1)
                        while(--n)
                        {
                                rear += front;
                                front = rear - front;
                                front %= 3;
                                rear %= 3;
                        }
                if(rear)
                        printf("no\n");
                else
                        printf("yes\n");
        }

        return 0;
}
