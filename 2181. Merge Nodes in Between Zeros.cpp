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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* ptr=head;
        ListNode* prev;
        ListNode* ans=head;
        while(head)
        {
            int sum=0;
            head=head->next;
            while(head && head->val!=0)
            {
                sum+=head->val;
                head=head->next;
            }

            if(sum!=0)
            {
                ptr->val=sum;
                prev=ptr;
                ptr=ptr->next;
            }
            
        }

        prev->next=NULL;
        return ans;
    }
};
