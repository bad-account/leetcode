#include <iostream>
#include <vector>

// SOLVED

using namespace std;

class Solution {
public:
    /*
        {4,5,6,1,2,3}
    */

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tmp = 0;

        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }

        for (int i = m + n - 1; i >= 0; --i) {
            for (int j = m + n - 1; j >= 0; --j) {
                if (nums1[j] < nums1[i]) {
                    tmp = nums1[i];
                    nums1[i] = nums1[j];
                    nums1[j] = tmp;
                }
            }
        }
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

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);

    print_v(nums1);
    
    vector<int> nums3 = {1};
    vector<int> nums4 = {};
    s.merge(nums3, 1, nums4, 0);

    print_v(nums3);

    vector<int> nums5 = {0};
    vector<int> nums6 = {1};
    s.merge(nums5, 0, nums6, 1);

    print_v(nums5);

    vector<int> nums7 = {4,5,6,0,0,0};
    vector<int> nums8 = {1,2,3};
    s.merge(nums7, 3, nums8, 3);

    print_v(nums7);

    return 0;
}