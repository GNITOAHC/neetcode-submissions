/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        set<int> s; // visited node idx
        map<int, Node*> m; // idx, created node
        queue<pair<Node*, Node*>> q; // original, cloned

        Node *cloned = new Node(node->val); // cloned root node
        q.push({node, cloned});
        m.insert({cloned->val, cloned});

        while(!q.empty()) {
            auto [original, cloned] = q.front();
            q.pop();

            if (s.count(original->val))
                continue;
            else s.insert(original->val);

            for (const auto& n : original->neighbors) {
                // Check if target is cloned before
                Node *new_node;
                if (m.count(n->val))
                    new_node = m[n->val];
                else new_node = new Node(n->val);

                cloned->neighbors.push_back(new_node);
                q.push({n, new_node});
                m.insert({new_node->val, new_node});
            }
        }

        return cloned;
    }
};
