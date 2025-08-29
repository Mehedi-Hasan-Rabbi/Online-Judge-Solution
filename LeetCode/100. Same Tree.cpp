// Definition for a binary tree node.
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
    // DFS Solution (Recursive) 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr) return true;
        if (p == nullptr and q != nullptr) return false;
        if (p != nullptr and q == nullptr) return false;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // BFS Solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> root_p;
        queue<TreeNode*> root_q;

        root_p.push(p);
        root_q.push(q);

        while (!root_p.empty() and !root_q.empty()) {
            TreeNode* nodeP = root_p.front(); root_p.pop();
            TreeNode* nodeQ = root_q.front(); root_q.pop();

            if (nodeP == nullptr and nodeQ == nullptr) continue;    // Leaf nodes/Missing child etc.
            if (nodeP == nullptr and nodeQ != nullptr) return false;
            if (nodeP != nullptr and nodeQ == nullptr) return false;
            if (nodeP->val != nodeQ->val) return false;

            root_p.push(nodeP->left);
            root_p.push(nodeP->right);

            root_q.push(nodeQ->left);
            root_q.push(nodeQ->right);
        }

        return root_p.empty() and root_q.empty();
    }
};