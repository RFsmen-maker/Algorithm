/*
* 面试题 17.14 最小 k 个数
* 1. 暴力选择排序：喜闻乐见超出时间限制
* 2. 快排思想，辅助向量，仍然无法通过，执行出错

class Solution {
public:
    vector<int> smallestK(vector<int>& nums, int k)
    {
        qsort(nums,k,0,nums.size()-1);
        return res;
    }

private:
    vector<int> res;
    void qsort(vector<int>& vec, int k,int left,int right)
    {
        if(left > right) return;
        int i = left;
        int j = right;
        //vec[left] is base
        while(i<j)
        {
            while(i<j && vec[j] >= vec[left]) --j;
            while(i<j && vec[i] <= vec[left]) ++i;
            swap(vec[i],vec[j]);
        }
        swap(vec[i],vec[left]);
        if(i == k) res.assign(vec.begin(),vec.begin()+k);
        else if(i > k) qsort(vec,k,left,i-1);
        else qsort(vec,k,i+1,right);
    }
};

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution1(vector<int> arr, int k)
{
        vector<int> result;

        for(auto i = 0; i < k; i++)
        {
                for(auto j = i+1; j < arr.size(); j++)
                {
                        if(arr[j] < arr[i]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
                result.push_back(arr[i]);
        }

        return result;
}

vector<int> solution2(vector<int> arr, int k)
{
        vector<int> result, tempAu1, tempAu2, tempCo(arr);
        if(k == 0) return result;

        int enough = k;
        while(enough >= 0)
        {
                int pivot = tempCo[0];
                for(auto it = tempCo.begin(); it != tempCo.end(); it++)
                {
                        if(*it <= pivot) tempAu1.push_back(*it);
                        else tempAu2.push_back(*it);
                }
                if(enough == k && tempAu1.size() == k) return tempAu1;
                if(tempAu1.size() >= enough) {
                        for(auto it = tempAu1.end()-1; it != tempAu1.end()-1-enough; it--)
                        {
                                result.push_back(*it);
                        }
                        break;
                }
                else {
                        enough -= tempAu1.size();
                        for(auto it = tempAu1.end()-1; it != tempAu1.begin()-1; it--)
                        {
                                result.push_back(*it);
                        }
                }
                tempCo = tempAu2;
                tempAu1.clear(), tempAu2.clear();
        }

        return result;
}

int main(void)
{
        vector<int> arr = {10, 22, 30, 5, 1, 4, 59};
        vector<int> result;
        result = solution2(arr, 1);

        for(auto it = result.begin(); it != result.end(); it++)
                cout << (*it) << endl;

        return 0;
}
