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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;

        }
        int x=k;
        ListNode* temp=head;
        while(x>0 && temp!=NULL){
            temp=temp->next;
            x--;
            }
         if(x==0){
             ListNode* prev=NULL;
             ListNode* curr=head;
             ListNode* forward=NULL;
             int count=0;
             while(curr!=NULL && count<k){
                 forward=curr->next;
                 curr->next=prev;
                 prev=curr;
                 curr=forward;
                 count++;

             }
             if(forward!=NULL){
                 head->next=reverseKGroup(forward, k);
             }
             return prev;

         }   
         else 
         return head;
        
    }
};