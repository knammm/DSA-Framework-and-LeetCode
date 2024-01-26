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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* ptr = head;
        ListNode* prevPtr = NULL;
        while(ptr && ptr->next){
            if(ptr == head){
                ListNode* tmp = ptr->next;
                ptr->next = tmp->next;
                tmp->next = ptr;
                head = tmp;
                prevPtr = ptr;
                ptr = tmp;
            }
            else{
                ListNode* tmp = ptr->next;
                ptr->next = tmp->next;
                tmp->next = ptr;
                prevPtr->next = tmp;
                prevPtr = ptr;
                ptr = tmp;
            }
            ptr = ptr->next->next;
        }
        return head;
    }
};