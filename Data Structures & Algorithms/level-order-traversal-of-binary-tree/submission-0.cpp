class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        int curr_level = 0;
        while (!q.empty()) {
            auto [curr, lvl] = q.front();
            q.pop();

            if (curr == nullptr) continue;

            if (lvl >= v.size()) v.push_back({});
            v[lvl].push_back(curr->val);

            q.push({curr->left, lvl + 1});
            q.push({curr->right, lvl + 1});
        }

        return v;
    }
};
