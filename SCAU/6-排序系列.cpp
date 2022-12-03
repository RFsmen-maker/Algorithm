/*
 * SCAU 排序系列
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

// 1. 直接插入排序，遍历下标 [0, size())，比前面小，就往前推，不断交换
void directInsertSort(vector<int> &arr) {
        for (int i = 1; i < n; ++i) {
                for (int j = i; j > 0; --j) {
                        if (arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
                }
                for (int i : arr) cout << i << ' ';
                cout << endl;
        }
}

// 2. 折半插入排序，遍历下标 [0, size())，不断维护前面的增序
// 参考视频讲解，划分蓝红区域，理清指定寻找位置目标
int binarySearch(vector<int> &arr, int left, int right, int aim) {
        int mid;
        while (left + 1 != right) {
                mid = (left + right) / 2; // 整数相除自带 lower_bound()
                if (arr[mid] <= aim) left = mid; // 不大于 aim 就让 l 右扩
                else right = mid;
        }
        return right; // 要插入的位置是不大于 aim 的位置的下一个
}
void binaryInsertSort(vector<int> &arr) {
        for (int i = 1; i < n; ++i) {
                int pos = binarySearch(arr, -1, i, arr[i]); // 从 [0, 1) 中找到不大于 arr[i] 的最后一个位置

                int temp = arr[i];
                for (int j = i; j > pos; --j) arr[j] = arr[j-1]; // 后推
                arr[pos] = temp;

                for (int i : arr) cout << i << ' ';
                cout << endl;
        }
}

// 3. 希尔排序，在组内使用的是插入排序
void shellSort(vector<int> &arr) {
        int d = n / 2;
        while (d) {
                for (int i = d; i < n; ++i) { // 组内从前往后
                        int p = i, mem = arr[i]; // 记录
                        while (p - d >= 0 && arr[p-d] > mem) arr[p] = arr[p-d], p -= d; // 直接往后推
                        arr[p] = mem;
                }

                for (int i : arr) cout << i << ' ';
                cout << endl;

                d /= 2;
        }

}

// 4. 冒泡排序，从前往后，大的后推
// 还需要进行优化，判逆序以较少排序次数
void bubbleSort(vector<int> &arr) {
        bool flag;
        for (int i = 0; i < n - 1; ++i) {
                flag = true;
                for (int j = 0; j < n - i - 1; ++j) {
                        if (arr[j] > arr[j+1]) {
                                swap(arr[j], arr[j+1]);
                                flag = false;
                        }
                }

                for (int i : arr) cout << i << ' ';
                cout << endl;

                if (flag) break;
        }
}

// 5. 快速排序：参照以前写过的改造
static int Partition(vector<int> &arr, int left, int right) {
        int piv = arr[left]; // 默认先取第一个作为锚点
        while (left < right) {
                while (left < right && arr[right] >= piv) --right; // 找到右边小于锚点的元素
                arr[left] = arr[right];
                while(left < right && arr[left] <= piv) ++left;
                arr[right] = arr[left];
        }
        arr[left] = piv;
        return left;
}
void quickSort(vector<int> &arr, int left, int right) {
        if (left < right) {
                int pivPos = Partition(arr, left, right); // 锚点位置每一轮确定一个元素

                for (int i : arr) cout << i << ' ';
                cout << endl;

                quickSort(arr, left, pivPos - 1);
                quickSort(arr, pivPos + 1, right);
        }
}

// 6. 简单选择排序
void simpleSelectSort(vector<int> &arr) {
        int minIn;
        for (int i = 0; i < n-1; ++i) {
                minIn = i;
                for (int j = i + 1; j < n; ++j) if (arr[j] < arr[minIn]) minIn = j; // 找 (i, n) 中最小的
                swap(arr[i], arr[minIn]);

                for (int i : arr) cout << i << ' ';
                cout << endl;
        }
}

// WA 无法搞定，放！
// 7. 堆排：同样是以前写的改造，这次不用偏移，left = cur * 2 + 1, right = cur * 2 + 2
//static void heapAdjust_Recur(vector<int> &arr, int i, int len) { // 数组、待维护点下标、数组长，递归版
//        int root = i, left = i * 2 + 1, right = i * 2 + 2;
//        cout << "root : " << root << ", left : " << left << ", right : " << right << endl;
//        if (left < n && arr[left] > arr[root]) root = left;
//        if (right < n && arr[right] > arr[root]) root = right;
//        if (root != i) {
//                swap(arr[root], arr[i]);
//                heapAdjust_Recur(arr, root, len);
//        }
//}
//void heapSort_Recur(vector<int> &arr) {
//        for (int i = n / 2 - 1; i >= 0; --i) heapAdjust_Recur(arr, i, n); // 建堆，从最后一个出度不为 0 的结点开始
//
//        for (int i : arr) cout << i << ' ';
//        cout << endl;
//
//        for (int i = n-1; i > 0; --i) { // 每次交换了堆顶和末尾，再调整堆
//                swap(arr[i], arr[0]);
//                heapAdjust_Recur(arr, 0, i);
//
//                for (int i : arr) cout << i << ' ';
//                cout << endl;
//        }
//}
//static void heapAdjust_Iter(vector<int> &arr, int k) { // 迭代版
//        int temp = arr[k];
//        for(int i = 2 * k; i <= n; i *= 2)
//        {
//                if(i < n && arr[i] < arr[i+1]) ++i;
//                if(temp >= arr[i]) break;
//                else {
//                        arr[k] = arr[i];
//                        k = i;
//                }
//        }
//        arr[k] = temp;
//}
//void heapSort_Iter(vector<int> &arr) {
//        for (int i = n / 2 - 1; i >= 0; --i) heapAdjust_Iter(arr, i); // 建堆
//        for (int i = n-1; i > 0; --i) { // 每次交换了堆顶和末尾，再调整堆
//                swap(arr[i], arr[0]);
//                heapAdjust_Iter(arr, i);
//
//                for (int i : arr) cout << i << ' ';
//                cout << endl;
//        }
//}

int main(void)
{
        cin >> n;
        vector<int> arr(n);
        for (int &i : arr) cin >> i;

        HeapSort(arr, n+1);

        return 0;
}

