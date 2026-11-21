#include <iostream>

using namespace std;

// SOLVED

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /*
        1    1
       2 3  2 3
    
        1    1
       2      2
    
        1    1
       2 1  1 2
    */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) 
            return true;
        
        if (!p || !q) 
            return false;
        
        if (p->val != q->val) 
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }   
};

int main () {
    TreeNode root1(1, new TreeNode(2), new TreeNode(3));
    TreeNode root2(1, new TreeNode(2), new TreeNode(3));

    TreeNode root3(1, new TreeNode(2), nullptr);
    TreeNode root4(1, nullptr, new TreeNode(2));

    TreeNode root5(1, new TreeNode(2), new TreeNode(1));
    TreeNode root6(1, new TreeNode(1), new TreeNode(2));


    Solution s;
    cout << s.isSameTree(&root1, &root2) << endl;
    cout << s.isSameTree(&root3, &root4) << endl;
    cout << s.isSameTree(&root5, &root6) << endl;

    return 0;
}