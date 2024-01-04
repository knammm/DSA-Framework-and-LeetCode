/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        if(!head) return 0;
        int returnResult = 0;
        while(head){
            returnResult++;
            head = head->next;
        }
        return returnResult;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        
        if(lengthA > lengthB){
            while(lengthA != lengthB){
                lengthA--;
                headA = headA->next;
            }
        }
        else if(lengthA < lengthB){
            while(lengthA != lengthB){
                lengthB--;
                headB = headB->next;
            }
        }

        while(headA && headB){
            if(headA == headB) return headA; // Must be the same memory shell !
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};