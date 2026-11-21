#include <iostream>
#include <vector>
#include <string>

// SOLVED

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool overflow = false;
        bool carry = false;
        digits[digits.size() - 1] += 1;

        if (digits[digits.size() - 1] % 10 == 0) { // update last digit if it does not change other digits
            digits[digits.size() - 1] %= 10;
            carry = true;            
        } else {
            return digits;
        }

        for (int i = digits.size() - 2; i >= 0; --i) {
            if (carry) {
                digits[i] += 1;
            }
            
            if (digits[i] % 10 == 0) {
                digits[i] %= 10;
                carry = true;
            } else {
                return digits; 
            }
        }

        if (digits[0] == 0) {
            digits.resize(digits.size() + 1);
            digits[0] = 1;
        }

        return digits;
    }
};

void print_v(std::vector<int> v) {
    for(auto d : v) {
        std::cout << d;
    }

    std::cout << std::endl;
}

int main() {
    Solution *s = new Solution();

    std::vector<int> digits1 = {1,2,3};
    std::vector<int> digits2 = {4,3,2,1};
    std::vector<int> digits3 = {9,9};
    std::vector<int> digits4 = {9,8,7,6,5,4,3,2,1,0};
    std::vector<int> digits5 = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};

    std::vector<int> solution1 = s->plusOne(digits1);
    std::vector<int> solution2 = s->plusOne(digits2);
    std::vector<int> solution3 = s->plusOne(digits3);
    std::vector<int> solution4 = s->plusOne(digits4);
    std::vector<int> solution5 = s->plusOne(digits5);

    print_v(solution1);
    print_v(solution2);
    print_v(solution3);
    print_v(solution4);
    print_v(solution5);

    return 0;
}
