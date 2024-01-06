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
    ListNode* getTail(ListNode* head){
        while(head->next){
            head = head->next;
        }
        return head;
    }
    int getLength(ListNode* head){
        if(!head) return 0;
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int length = getLength(head);
        int timeLoop = k % length;
        for(int i = 0; i < timeLoop; i++){
            ListNode* tail = getTail(head);
            ListNode* ptr = head;
            tail->next = head;
            head = tail;
            while(ptr->next != tail){
                ptr = ptr->next;
            }
            ptr->next = NULL;
        }
        return head;
    }
};