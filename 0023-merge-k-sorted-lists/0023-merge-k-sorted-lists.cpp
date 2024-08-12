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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the nodes
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;

        // Initialize the heap with the head of each list
        for (ListNode* list : lists) {
            if (list != nullptr) {
                q.push(list);
            }
        }

        // Dummy node to help with the result list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Process the heap
        while (!q.empty()) {
            ListNode* temp = q.top();
            q.pop();

            // Add the smallest node to the merged list
            current->next = temp;
            current = current->next;

            // If there's a next node in the same list, push it into the heap
            if (temp->next != nullptr) {
                q.push(temp->next);
            }
        }

        // Return the merged list, skipping the dummy node
        return dummy->next;
    }
};