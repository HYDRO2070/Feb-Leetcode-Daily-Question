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
class FindElements {
    private:
   unordered_set<int> m;
public:
    FindElements(TreeNode* root) {
         auto solve = [&](TreeNode* node, int parent, int val, auto& solveRef) -> void {
            if (node == NULL) return;

            int temp = 2 * parent + val;
            m.insert(temp);

            if (node->left)
                solveRef(node->left, temp, 1, solveRef);
            if (node->right)
                solveRef(node->right, temp, 2, solveRef);
        };

        solve(root, 0, 0, solve);
    }
    
    bool find(int target) {
        return m.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
