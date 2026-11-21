#include <iostream>
#include <vector>
#include <map>

// SOLVED

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        double min = nums.size() / 2;

        map<int, int> occurrences;

        for (int n : nums) {
            occurrences[n] = 1;
        }

        for (int n : nums) {
            occurrences[n] += 1;
        }

        auto max = occurrences.begin();

        for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
            if ((*it).second > (*max).second) {
                max = it;
            }
        }

        return (*max).first;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3,2,3};
    cout << s.majorityElement(nums) << endl;
    nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement(nums) << endl;

    return 0;
}