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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s="";
       queue<TreeNode*>q;
       q.push(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp == NULL) {
            s += "#,";
            continue;
        }

        s += to_string(temp->val) + ",";
        q.push(temp->left);
        q.push(temp->right);
    }
}
return s;
    }

    // Decodes your encoded data to tree.
   TreeNode* deserialize(string data) {
    if (data.size() == 0) return NULL;

    // Step 1: split string
    vector<string> nodes;
    stringstream ss(data);
    string token;

    while (getline(ss, token, ',')) {
        nodes.push_back(token);
    }

    // Step 2: create root
    if (nodes[0] == "#") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    // Step 3: build tree
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // LEFT child
        if (nodes[i] != "#") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // RIGHT child
        if (i < nodes.size() && nodes[i] != "#") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));