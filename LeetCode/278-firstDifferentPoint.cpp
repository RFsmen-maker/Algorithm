// 找第一个错误版本
/*
 使用 mid = lo + (hi - lo) /2 以防计算溢出
 要找的是终止点而不是对比值
*/

#include <iostream>

int main(void)
{

}

int firstBadVersion(int n) {
        int low = 1, high = n;
        while(low < high)
        {
                int mid = low + (high - low) / 2;
                if(isBadVersion(mid)) high = mid;
                else low = mid+1;
        }
        return low;
}

