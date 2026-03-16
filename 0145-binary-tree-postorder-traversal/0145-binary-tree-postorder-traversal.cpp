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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode*curr=root;
        stack<TreeNode*>st;
        vector<int>ans;
        while(curr!=NULL||!st.empty()){
            if(curr!=NULL){
               st.push(curr);
               curr=curr->left;
            }

            else{
               TreeNode*temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty()&&st.top()->right==temp){
                        temp=st.top();
                        ans.push_back(temp->val);
                        st.pop();
                    }
                }
                else{
                    curr=temp;
                }
            }
            

        }
        return ans;
    }
};