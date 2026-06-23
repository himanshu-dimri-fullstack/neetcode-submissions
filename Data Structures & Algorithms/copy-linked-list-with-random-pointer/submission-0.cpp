/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummyNode = new Node(-1);
        Node *temp = dummyNode;
        Node *curr = head;
        while(curr!=NULL){
            Node *newNode = new Node(curr->val);
            temp->next = newNode;
            temp = temp->next;
            curr = curr->next;
        }
        curr = head;
        temp = dummyNode->next;
        unordered_map<Node*, Node*> mapp;
        while(curr!=NULL){
            mapp.insert({curr,temp});
            curr = curr->next;
            temp = temp->next;
        }
        curr = head;
        temp = dummyNode->next;
        while(curr!=NULL){
            if(curr->random==NULL){
                temp->random = NULL;
            }
            else{
                Node* randomP = curr->random;
                if(mapp.find(randomP)!=mapp.end()){
                    temp->random = mapp.find(randomP)->second;
                }
            }
             temp = temp->next;
             curr = curr->next;
        }
        return dummyNode->next;
    }
};
