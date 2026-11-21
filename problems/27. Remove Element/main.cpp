#include <iostream>
#include <vector>

// SOLVED

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t output = 0;

        size_t idx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[idx] = nums[i];
                idx += 1;
                output += 1;
            } 
        }

        nums.resize(idx);

        return output;
    }
};

void print_v(std::vector<int> v) {
    for(auto d : v) {
        std::cout << d;
    }

    std::cout << std::endl;
}

int main() {
    Solution s;

    vector<int> nums = {3,2,2,3};
    cout << s.removeElement(nums, 3) << endl;
    print_v(nums);


    return 0;
}