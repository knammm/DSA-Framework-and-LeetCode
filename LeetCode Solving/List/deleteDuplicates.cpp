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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* ptr = head;
        while(head != NULL && head->next != NULL){
            if((head->val) ==(head->next->val)){
                ListNode* delPtr = head->next;
                head->next = head->next->next;
                delete(delPtr);
            }
            else head = head->next;
        }
        return ptr;
    }
};