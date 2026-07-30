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

    ListNode* midpoint(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;


        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }


        return slow;
    }


    ListNode* merge(ListNode* left,ListNode* right){
        ListNode dummy(0);
        ListNode* tail=&dummy;



        while(left and right){
            if(left->val<right->val){
                tail->next=left;
                left=left->next;
            }

            else{
                tail->next=right;
                right=right->next;

            }
            tail=tail->next;


        }

        if(left){
            tail->next=left;
        }
        else{
            tail->next=right;


        }

        return  dummy.next;
    }
    ListNode* sortList(ListNode* head) {

        if(head==NULL or  head->next==NULL){
            return head;
        }

        ListNode*mid=midpoint(head);


        ListNode*right=mid->next;
        mid->next=NULL;
        ListNode*left=head;

        left=sortList(left);
        right=sortList(right);




        return merge(left,right);

        
    }
};