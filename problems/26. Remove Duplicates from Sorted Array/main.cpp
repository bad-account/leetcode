#include <iostream>
#include <vector>
#include <set>

// SOLVED

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> u;

        for (auto n : nums) {
            u.insert(n);
        }

        nums.clear();

        for (auto n : u) {
            nums.push_back(n);
        }
        
        return u.size();
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

    vector<int> nums = {1,1,2};
    cout << s.removeDuplicates(nums) << endl;
    print_v(nums);

    nums = {0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(nums) << endl;
    print_v(nums);

    return 0;
}