class Solution {
public:
    bool val = false;

    int dfs(Node* node){
        if(node == NULL) return 0;

        if(node->left == NULL && node->right == NULL){
            return node->data;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        int sum = 0;
        if(node->left) sum += node->left->data;
        if(node->right) sum += node->right->data;

        if(node->data != sum){
            val = true;
        }

        return node->data;
    }

    bool isSumProperty(Node *root) {
        if(root == NULL) return true;

        dfs(root);

        return !val;
    }
};