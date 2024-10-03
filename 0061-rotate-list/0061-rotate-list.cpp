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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        int size=1;
        while(curr->next!=NULL){
             size++;
            curr=curr->next;
        }
        curr->next=head;
        k=k%size;
        ListNode* temp=head;
        for(int i=1;i<size-k;i++){
            temp=temp->next;

        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        return newhead;
    }
};
