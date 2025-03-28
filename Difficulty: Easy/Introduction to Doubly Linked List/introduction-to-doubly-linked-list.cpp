//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    Node* prev;
    int data;
    Node* next;

    Node() {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value) {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

void printList(Node* node) {
    Node* tmp = node;
    int c1 = 0, c2 = 0;
    if (tmp) {
        while (tmp->next != NULL) {
            c1++;
            tmp = tmp->next;
        }
        while (tmp->prev != NULL) {
            c2++;
            tmp = tmp->prev;
        }
        if (c1 != c2) {
            cout << "-1\n";
            return;
        }
    }
    while (tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
    // void dbLL(vector<int>&arr,Node*head){
    //     Node*back=NULL;
    //     int i=1;
    //     Node*temp=head;
    //     while(i<arr.size()){
    //         Node*newNode=new Node(arr[i]);
    //         temp->next=newNode;
    //         temp->prev=back;
    //         back=temp;
    //         temp=temp->next;
    //         i++;
    //     }
    // }
  public:
    Node* constructDLL(vector<int>& arr) {
       Node*head=new Node(arr[0]);
    //   head->prev=NULL;
    //   Node*back=NULL;
        int i=1;
        Node*temp=head;
        while(i<arr.size()){
            Node*newNode=new Node(arr[i]);
            temp->next=newNode;
            newNode->prev=temp;
            temp=temp->next;
            i++;
        }
       return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructDLL(arr);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends