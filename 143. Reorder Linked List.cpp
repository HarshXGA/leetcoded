/**
 * Definition for singly-linked list
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
    ListNode* reversal(ListNode* curr)
    {
        ListNode* temp=curr, *prev=NULL;

        while(curr)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

        if(!head->next || !head->next->next)
            return;
        
        ListNode *rhead=head,*ptr=head; //ptr is fast pointer
        ListNode* rhead_prev;
        while(ptr && ptr->next)
        {   rhead_prev=rhead;
            rhead=rhead->next;
            ptr=ptr->next->next;
        }
        //second half of list
        rhead_prev->next=NULL; //first half of list
        rhead=reversal(rhead);


        ListNode* fhead=head; //fhead head for first half list, rhead for second half list
        ptr=head;

        while(fhead && rhead)
        {
            fhead=fhead->next;
            ptr->next=rhead;
            ptr=ptr->next;
            rhead=rhead->next;

            if(fhead)
            {    
                ptr->next=fhead;
                ptr=ptr->next;
            }
        }

        if(rhead) //odd list size
        {
            ptr->next=rhead;
            ptr=ptr->next;
        }

        ptr->next=NULL; 
    }
};
