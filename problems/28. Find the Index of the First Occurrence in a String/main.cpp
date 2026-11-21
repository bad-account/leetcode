#include <iostream>
#include <string>

// SOLVED

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int output = -1;

        if (needle.size() > haystack.size()) {
            return output;
        }

        string substring = "";

        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            substring = haystack.substr(i, needle.size());

            if (substring == needle) {
                return i;
            }
        }

        return output;
    }
};

int main() {

    Solution s;

    cout << s.strStr("sadbutsad", "sad") << endl;
    cout << s.strStr("leetcode", "leeto") << endl;


    return 0;
}