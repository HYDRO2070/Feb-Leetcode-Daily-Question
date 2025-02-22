/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(string &s, int d, int &index, const int &n) {
        if (index >= n) return NULL;

        int _count = 0;
        while (index + _count < n && s[index + _count] == '-') {
            _count++;
        }

        if (_count != d) {
            return NULL;
        }

        index += _count;

        int num = 0;
        while (index < n && s[index] != '-') {
            num = num * 10 + (s[index] - '0');
            index++;
        }

        TreeNode* root = new TreeNode(num);

        root->left = solve(s, d + 1, index, n);
        root->right = solve(s, d + 1, index, n);

        return root;
    }

public:
    TreeNode* recoverFromPreorder(string &s) {
        int index = 0;
        const int n = s.size();
        return solve(s, 0, index, n);
    }
};
