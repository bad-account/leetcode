#include <iostream>
#include <string>

// SOLVED

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        
        while (s[s.length() - 1] == ' ') {
            s.pop_back();
        }

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                result += 1;
            } else {
                return result;
            }
        }

        return result;
    }
};

int main () {
    Solution solution;

    string s = "Hello World";
    cout << solution.lengthOfLastWord(s) << endl;
    s = "   fly me   to   the moon  ";
    cout << solution.lengthOfLastWord(s) << endl;
    s= "luffy is still joyboy";
    cout << solution.lengthOfLastWord(s) << endl;

    return 0;
}