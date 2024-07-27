/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
//       bool pathNodes(TreeNode* root, TreeNode* p, vector<TreeNode*>& v) {
//         if (!root) return false;
//         v.push_back(root);
//         if (root->val == p->val) return true;

//         if (pathNodes(root->left, p, v) || pathNodes(root->right, p, v)) {
//             return true;
//         }
//         v.pop_back();
//         return false;
//     }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//          vector<TreeNode*> arr1;
//         vector<TreeNode*> arr2;

//         pathNodes(root, p, arr1);
//         pathNodes(root, q, arr2);

//         TreeNode* lca = nullptr;
//         for (int i = 0; i < min(arr1.size(), arr2.size()); i++) {
//             if (arr1[i]->val == arr2[i]->val) {
//                 lca = arr1[i];
//             } else {
//                 break;
//             }
//         }
//         return lca;  
//          if(root==NULL){
//             return NULL;
            
//         }
        int curr=root->val;
        if(curr<p->val&&curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val&&curr>q->val){
              return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};