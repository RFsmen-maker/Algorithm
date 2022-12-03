#include <iostream>
#include <vector>

using namespace std;

// 双指针左右逼近法
vector<int> twoSum(vector<int>& numbers, int target)
{
        int left = 0;
        int right = numbers.size() - 1;
        int sum;
        while(left < right)
        {
                sum = numbers[left] + numbers[right];
                if(sum == target) return {left+1, right+1};
                else if(sum < target) left++;
                else right--;
        }

        return {-1, -1};
}

vector<int> getNums(void)
{
        vector<int> nums;
        cout << "input the numbers, -1 to end" << endl;
        int tempIn;
        while(cin >> tempIn && tempIn != -1) nums.push_back(tempIn);

        return nums;
}

int main(void)
{
        vector<int> nums = getNums();
        for(auto num : nums) cout << num << endl;
        cout << "input the target: ";
        int target;
        cin >> target;
        auto temp = twoSum(nums, target);
        for(auto it = temp.begin(); it != temp.end(); it++)
                cout << *it << endl;

        return 0;
}
