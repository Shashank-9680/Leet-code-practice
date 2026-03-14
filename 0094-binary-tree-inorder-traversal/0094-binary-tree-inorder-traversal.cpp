class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(node != nullptr || !st.empty()){

            while(node != nullptr){
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();

            ans.push_back(node->val);

            node = node->right;
        }

        return ans;
    }
};