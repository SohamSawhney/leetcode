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


   ListNode*reverse(ListNode* newHead){
    ListNode*prev=NULL;
    ListNode*curr=newHead;


 

    while(curr!=NULL){
     ListNode* temp=curr->next;
     curr->next=prev;
     prev=curr;
     curr=temp;
    }

    return prev;
   }
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode*fast=head;

        while(fast!=NULL  and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*second=reverse(slow);
        ListNode*first=head;



        // now comparison is done 

        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }


            first=first->next;
            second=second->next;
        }


        return true;

    }
};