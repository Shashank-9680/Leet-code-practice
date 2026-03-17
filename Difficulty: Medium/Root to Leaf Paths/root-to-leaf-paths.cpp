class Solution {
    bool isLeaf(Node* node){
        return node->left == NULL && node->right == NULL;
    }

public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        stack<Node*> st;
        Node* curr = root;
        Node* lastVisited = NULL;

        while(curr != NULL || !st.empty()){

            // go left
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            Node* node = st.top();

            // if right not visited, go right
            if(node->right && lastVisited != node->right){
                curr = node->right;
            }
            else{
                // process node
                if(isLeaf(node)){
                    vector<int> temp;

                    // copy stack → path
                    stack<Node*> tempStack = st;

                    while(!tempStack.empty()){
                        temp.push_back(tempStack.top()->data);
                        tempStack.pop();
                    }

                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }

                lastVisited = node;
                st.pop();
            }
        }

        return ans;
    }
};