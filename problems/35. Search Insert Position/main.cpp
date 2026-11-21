#include <iostream>
#include <vector>

// SOLVED

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] >= target) {
            return 0;
        }

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return nums.size();
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,3,5,6};
    cout << s.searchInsert(nums, 5) << endl;

    nums = {1,3,5,6};
    cout << s.searchInsert(nums, 2) << endl;

    nums = {1,3,5,6};
    cout << s.searchInsert(nums, 7) << endl;

    return 0;
}