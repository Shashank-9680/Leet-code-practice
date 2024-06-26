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
class BSTIterator {
    stack<TreeNode*>st;
     void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
   
public:
    BSTIterator(TreeNode* root) {
       pushAllLeft(root);
    }
    
    int next() {
         TreeNode* node = st.top();
        st.pop();
        int result = node->val;

        // If the node has a right child, push all its left children to the stack
        if (node->right != nullptr) {
            pushAllLeft(node->right);
        }

        return result;
    
    }
    
    bool hasNext() {
      return !st.empty();  
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */