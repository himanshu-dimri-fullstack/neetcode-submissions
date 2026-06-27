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
    ListNode* mergeArr(ListNode* head1, ListNode *head2){
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val < temp2->val){
              temp->next = temp1;
              temp = temp->next;
              temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return dummyNode->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode *curr = lists[0];
        for(int i=1;i<lists.size();i++){
            ListNode *curr1 = lists[i];
            curr = mergeArr(curr,curr1); 
        }
       return curr;
    }
};
