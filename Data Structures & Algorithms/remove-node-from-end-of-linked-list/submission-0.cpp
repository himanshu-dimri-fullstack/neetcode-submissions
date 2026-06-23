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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            size++;
            curr = curr->next;
        }
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *temp = dummyNode;
        int count = 0;
        while(count<size-n){
            temp = temp->next;
            count++;
        }
        ListNode *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        return dummyNode->next;
    }
};
