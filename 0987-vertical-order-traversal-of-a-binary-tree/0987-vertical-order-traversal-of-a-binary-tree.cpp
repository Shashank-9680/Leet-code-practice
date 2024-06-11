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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>result;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            TreeNode*temp=p.first;
            q.pop();
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(temp->val);
            if(temp->left!=NULL) q.push({temp->left,{x-1,y+1}});
            if(temp->right!=NULL) q.push({temp->right,{x+1,y+1}});
        }
    for (auto& horizontalDistanceEntry : nodes) {
    auto& depthMap = horizontalDistanceEntry.second;
    vector<int> columnValues;

    // Iterate over the sorted depths (y-coordinates) at this horizontal distance
    for (auto& depthEntry : depthMap) {
        auto& nodeValuesAtDepth = depthEntry.second;

        // Iterate over each element in nodeValuesAtDepth and add it to columnValues
        for (int value : nodeValuesAtDepth) {
            columnValues.push_back(value);
        }
    }

    // Append the column vector to the result vector
    result.push_back(columnValues);
}
        return result;
    }
};