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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        int carry = 0;
        while(curr1!=NULL && curr2 !=NULL){
            int data = curr1->val + curr2->val + carry;
            if(data>9){
                ListNode *newNode = new ListNode(data%10);
                temp->next = newNode;
                carry = 1;
            }
            else{
                ListNode *newNode = new ListNode(data);
                temp->next = newNode;
                carry = 0;
            }
            temp = temp->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1!=NULL){
           int data = curr1->val + carry;
           if(data>9){
             ListNode *newNode = new ListNode(data%10);
             temp->next = newNode;
             carry = 1;
           }
           else{
            ListNode *newNode = new ListNode(data);
                temp->next = newNode;
                carry = 0;
           }
             temp = temp->next;
             curr1 = curr1->next;
        }
        while(curr2!=NULL){
           int data = curr2->val + carry;
           if(data>9){
             ListNode *newNode = new ListNode(data%10);
             temp->next = newNode;
             carry = 1;
           }
           else{
            ListNode *newNode = new ListNode(data);
                temp->next = newNode;
                carry = 0;
           }
             temp = temp->next;
             curr2 = curr2->next;
        }
        if(carry == 1){
             ListNode *newNode = new ListNode(1);
             temp->next = newNode;
        }
        return dummyNode->next;
    }
};
