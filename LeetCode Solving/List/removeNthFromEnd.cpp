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
    int getLength(ListNode* head){
        if(!head) return 0;
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int length = getLength(head);
        int index = length - n;
        if(index == 0){
            ListNode* delPtr = head;
            head = head->next;
            delete(delPtr);
        }
        else{
            ListNode* ptr = head;
            for(int i = 0; i < index - 1; i++){
                ptr = ptr->next;
            }
            ListNode* delPtr = ptr->next;
            if(delPtr->next == NULL) ptr->next = NULL;
            else ptr->next = delPtr->next;
            delete(delPtr);
        }
        return head;
    }
};