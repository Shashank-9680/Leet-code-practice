// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        unordered_map<int,int>m;
        Node*temp=head;
        vector<pair<int,int>>ans;
        while(temp){
            int a=target-temp->data;
            if(m.find(a)!=m.end()){
                ans.push_back({a,temp->data});
            }
            m[temp->data]++;
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};