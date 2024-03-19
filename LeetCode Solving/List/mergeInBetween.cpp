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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        ListNode* ptr = list1;
        ListNode* tail1 = NULL;
        ListNode* tail2 = NULL;
        while(ptr != NULL){
            if(i + 1 == a) tail1 = ptr;
            if(i == b + 1){
                tail2 = ptr;
                break;
            }
            ptr = ptr->next;
            i++;
        }
        std::cout << list1->val << " " << list2->val << endl;
        tail1->next = list2;
        while(list2->next != NULL){
            list2 = list2->next;
        }
        list2->next = tail2;
        return list1;
    }
};