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
    int countNodes(ListNode* head){
        int count=0;
        ListNode*temp=head;


        while(temp!=NULL){
            count++;
            temp=temp->next;
        }


        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

    


        int N=countNodes(head);

        if(N==n){
            ListNode*newHead=head->next;
            delete head;
            return newHead;
        }
        ListNode*temp=head;

        for(int i=0;i<N-n-1;i++){
             temp=temp->next;
        }
        ListNode*delNode=temp->next;

        temp->next=delNode->next;
        delete delNode;

     
        return head;
        
    }
};