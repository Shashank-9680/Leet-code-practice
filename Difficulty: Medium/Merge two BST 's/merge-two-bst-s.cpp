//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    void fxn1(Node*root,vector<int>&a){
        if(root==NULL){
            return;
        }
        fxn1(root->left,a);
        a.push_back(root->data);
        fxn1(root->right,a);
    }
    //   void fxn2(Node*root,vector<int>&b){
    //       if(root==NULL){
    //         return;
    //     }
    //     fxn2(root->left,b);
    //     b.push_back(root->data);
    //     fxn2(root->right,b);
    // }
  public:
   
    vector<int> merge(Node *root1, Node *root2) {
      vector<int>a;
      vector<int>b;
      fxn1(root1,a);
      fxn1(root2,b);
      vector<int>ans;
      int i=0;
      int j=0;
      while(i<a.size()&&j<b.size()){
          if(a[i]>b[j]){
              ans.push_back(b[j]);
              j++;
          }
          else if(a[i]<b[j]){
              ans.push_back(a[i]);
              i++;
          }
          else{
              ans.push_back(a[i]);
               ans.push_back(a[i]);
               i++;
               j++;
          }
      }
      while(i<a.size()){
          ans.push_back(a[i]);
          i++;
      }
      while(j<b.size()){
          ans.push_back(b[j]);
          j++;
      }
      return ans;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends