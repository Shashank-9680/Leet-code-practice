/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
     
        int part_size = length / k;  
        int extra = length % k;      
        
        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;
        int i = 0;
        
        // Step 3: Use a while loop to split the list into k parts
        while (i < k && curr) {
            result[i] = curr;
            int current_part_size = part_size + (extra > 0 ? 1 : 0); // If extra is available, add 1 more node to the current part
            extra--; // Decrease extra count if extra node is used
            
            // Move through 'current_part_size' nodes in the current part
            for (int j = 1; j < current_part_size; j++) {
                if (curr) curr = curr->next;
            }
            
            // Break the current part from the rest of the list
            if (curr) {
                ListNode* next = curr->next;
                curr->next = nullptr;
                curr = next; // Move to the next part of the list
            }
            i++; // Move to the next part
        }
       
        
        return result;
    }
};
