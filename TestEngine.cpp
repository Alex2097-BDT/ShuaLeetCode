//
// Created by alex on 10/7/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include "TestEngine.h"
using namespace std;

TestEngine *TestEngine::_test_engine = nullptr;
TestEngine::TestEngine() = default;
TestEngine::~TestEngine() {
    delete _test_engine;
}
TestEngine::TestEngine(const TestEngine &) = default;
TestEngine& TestEngine::operator=(const TestEngine &) = default;
TestEngine& TestEngine::instance() {
    static TestEngine _test_engine = TestEngine();
    return _test_engine;
}

/////////////////////////////////////////////////////////////////////
/**
 * add functions and structs def here
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/////////////////////////////////////////////////////////////////////


/**
 * paste Solution here
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i;
        int c;
        ListNode *h1 = new ListNode(-1);
        ListNode *h2 = new ListNode(-1);
        ListNode *pt, *pt2;
        h1->next = l1;
        h2->next = l2;
        int num;
        pt = h1;
        pt2 = h2;
        c=0;
        bool flag=false;
        while(pt->next!=NULL||pt2->next!=NULL){
            if(pt->next==NULL){
                flag=false;
                pt2=pt2->next;
                pt2->val+=c;
                if(pt2->val>=10){
                    pt2->val-=10;
                    c=1;
                }else{
                    c=0;
                }
            }else if(pt2->next==NULL){
                flag=true;
                pt = pt->next;
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

/**
 * write test function here
 * @return
 */
RC TestEngine::test(){
    Solution solution;
    ListNode *l1 = new ListNode(1);
    ListNode l11 = ListNode(8);
    l1->next=&l11;
    ListNode *l2 = new ListNode(0);
    cout<<endl;
    ListNode *output = solution.addTwoNumbers(l2, l1);
    ListNode *pt;
    pt = output;
    do{
        cout<<pt->val<<" ";
        pt = pt->next;
    }while(pt!=NULL);

//    cout<<(output->next->val==NULL)<<endl;
    return SUCCESS;
}

int main(int argc, char *argv[]){
    TestEngine &testEngine = TestEngine::instance();
    testEngine.test();
    return SUCCESS;
}
