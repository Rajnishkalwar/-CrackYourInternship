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
    ListNode* middleNode(ListNode* head) {
        ListNode* current =head;
        int nodes= 0;
        while(current!=NULL){
            nodes++;
            current=current->next;
        }
        current=head;
        int middleNode=(nodes/2)+1;
        while(middleNode>1){
             current=current->next;
             middleNode--;

        }
        return current;
    }
};