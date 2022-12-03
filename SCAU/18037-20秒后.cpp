/*
 * 18037. 20 秒后的时间
 */
#include <iostream>

using namespace std;

int main(void)
{
        int hour, minute, second;
        scanf("%d:%d:%d", &hour, &minute, &second);

        int carry1, carry2; // 注意顺序
        carry1 = (second + 20) / 60;
        second = (second + 20) % 60;
        carry2 = (minute + carry1) / 60;
        minute = (minute + carry1) % 60;
        hour = (hour + carry2) % 24;

        printf("%02d:%02d:%02d", hour, minute, second);

        return 0;
}
