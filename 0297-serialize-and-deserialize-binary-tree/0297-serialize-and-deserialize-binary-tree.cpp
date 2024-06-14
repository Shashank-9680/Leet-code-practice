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
    string s;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if (!root) return "null";
        
        string s;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp) {
                s.append(to_string(temp->val) + ",");
                q.push(temp->left);
                q.push(temp->right);
            } else {
                s.append("null,");
            }
        }
        
        // Remove trailing comma
        if (!s.empty()) s.pop_back();
        
        return s;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if (data == "null") return nullptr;
        
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(item));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));