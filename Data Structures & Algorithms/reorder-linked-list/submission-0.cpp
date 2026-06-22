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
    void reorderList(ListNode* head) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode *curr = head;
        while(curr!=NULL){
            st1.push(curr);
            curr = curr->next;
        }
        stack<ListNode*> copy = st1;
        while(!copy.empty()){
            st2.push(copy.top());
            copy.pop();
        }
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        int n = st1.size();
        int count = 0;
        while(count<=n){
            if(count%2==0){
               temp->next = st2.top();
               st2.pop();
               temp = temp->next;
            }
            else{
                temp->next = st1.top();
                st1.pop();
                temp = temp->next;
            }
          count++;
        }
        temp->next = NULL;
    }
};
