/*
 * 18052. 插入数据
 */
#include <stdio.h>
int a[16]={2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 34, 71, 79, 97, 103};
void display()
{
    int i;
    for(i=0; i<16; i++) printf("%d ", a[i]);
}
int main()
{
        // 首先尝试简单插入，即找到最后一个不大于 x 的位置
        int x;
        scanf("%d", &x);
        int i;
        for (i = 14; i >= 0; --i) {
                if (a[i] > x) a[i+1] = a[i];
                else break;
        }
        a[i+1] = x;

    display();
    return 0;
}
