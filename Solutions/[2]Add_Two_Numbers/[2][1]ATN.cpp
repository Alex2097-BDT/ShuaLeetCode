//
// Created by alex on 10/8/19.
//

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i;
        int c;
        ListNode *h1 = new ListNode(-1);
        ListNode *h2 = new ListNode(-1);
        ListNode *pt, *pt2;
        h1->next = l1;      //extra header, actually unnecessary
        h2->next = l2;
        int num;
        pt = h1;
        pt2 = h2;
        c=0;
        bool flag=false;    //initialize flag to false is unnecessary
        // because the flag can first be assigned to true then false in some cases
        while(pt->next!=NULL||pt2->next!=NULL){
            if(pt->next==NULL){
                flag=false;
                pt2=pt2->next;
                pt2->val+=c;
                if(pt2->val>=10){   //calculation of carry bit can be precised by using a variant called sum
                    /**
                     *  sum/=10
                     *  if(a != null){sum+=m}
                     *  if(b != null){sum+=n}
                     *  addNewNode(sum%10)
                     *
                     *  in the above case, sum both represents the "sum" of two bits and the carry for next calculation
                     */
                    pt2->val-=10;
                    c=1;
                }else{
                    c=0;
                }
            }else if(pt2->next==NULL){
                flag=true;
                pt = pt->next;  //create a new node list, avoid redundant judgement
                pt->val+=c;
                if(pt->val>=10){
                    pt->val-=10;
                    c=1;
                }else{
                    c=0;
                }
                continue;
            }else{
                flag=true;
                pt = pt->next;
                pt2 = pt2->next;
                pt->val+=pt2->val+c;
                pt2->val = pt->val;
                if(pt->val>=10){
                    pt->val-=10;
                    pt2->val-=10;
                    c=1;
                }else{
                    c=0;
                }
            }
        }
        if(flag){
            if(c==1){
                pt->next = new ListNode(1);
            }
            return l1;
        }else{
            if(c==1){
                pt2->next = new ListNode(1);
            }
            return l2;
        }
    }
};