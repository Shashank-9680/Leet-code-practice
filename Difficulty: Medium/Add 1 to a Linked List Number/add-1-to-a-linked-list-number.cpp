//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


class Solution {
    int carry=1;
    void adding(Node*head){
        if(head==NULL){
            return ;
        }
        adding(head->next);
        if(head->next==NULL&&head->data!=9){
            head->data=head->data+carry;
            carry=0;
           
        }
       
        if(carry==1&&head->data!=9){
             head->data=head->data+carry;
             carry=0;
        }
        if(carry==0){
            return;
        }
         if(head->data==9){
            head->data=0;
            carry=1;
            return;
        }
        
    }
  public:
 
    Node* addOne(Node* head) { 
        
       adding(head);
       if(carry==1){
           Node*temp=new Node(1);
           temp->next=head;
           return temp;
       }
       return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends