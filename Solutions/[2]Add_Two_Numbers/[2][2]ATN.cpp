//
// Created by alex on 10/8/19.
//

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h = new ListNode(-1), *p=h;
        int sum=0;
        while(l1||l2||sum){
            int a=l1?l1->val:0, b=l2?l2->val:0;
            sum+=a+b;
            p->next=new ListNode(sum%10);
            p=p->next;
            sum/=10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return h->next;
    }
};