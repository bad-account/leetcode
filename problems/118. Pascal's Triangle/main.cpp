#include <iostream>
#include <vector>

// SOLVED

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        if (numRows == 1) {
            return {{1}};
        } 

        if (numRows == 2) {
            return {{1}, {1, 1}};
        }

        vector<vector<int>> output = {{1}, {1, 1}};

        for (int i = 2; i < numRows; ++i) {
            vector<int> previous_row = output[i - 1];
            vector<int> current_row = {};

            current_row.push_back(1); // 1st cell in row

            for (int j = 1; j <= i - 1; ++j) { 
                current_row.push_back(previous_row[j] + previous_row[j - 1]);
            }

            current_row.push_back(1); // last cell in row

            output.push_back(current_row);
        }

        return output;
    }
};


void print(vector<vector<int>> v) {
    cout << "[";
    
    for (int i = 0; i < v.size(); i++) {
        cout << "[";

        for (int j = 0; j < v[i].size(); j++) {
            if (j == v[i].size() - 1) {
                cout << v[i][j];
            } else {
                cout << v[i][j] << ", ";
            }
        }

        if (i == v.size() - 1) {
            cout << "]";

        } else {
            cout << "], ";
        }
    }

    cout << "]" << endl;
}

int main() {
    Solution s;

    print(s.generate(1));
    print(s.generate(5));

    return 0;
}

