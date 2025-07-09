/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:    
    string serialize(TreeNode* root) {
        string serial = "";
        queue<TreeNode*> bfs;

        if (root == NULL) {
            bfs.push(nullptr);
        } else bfs.push(root);
        while (!bfs.empty()) {
            TreeNode* top = bfs.front();
            bfs.pop();

            if (top == nullptr) {
                serial += "N,";
                continue;
            } else serial += to_string(top->val) + ",";

            bfs.push(top->left);
            bfs.push(top->right);

        }
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        if (nodes.empty() || nodes[0] == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> bfs;
        bfs.push(root);

        for (int i=1; i < nodes.size(); i+=2) {
            TreeNode* curr = bfs.front();
            bfs.pop();

            TreeNode* left = nodes[i] == "N" ? nullptr : new TreeNode(stoi(nodes[i]));
            TreeNode* right = nodes[i + 1] == "N" ? nullptr : new TreeNode(stoi(nodes[i + 1]));
            curr->left = left;
            curr->right = right;

            if (left) bfs.push(left);
            if (right) bfs.push(right);
        }


        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));