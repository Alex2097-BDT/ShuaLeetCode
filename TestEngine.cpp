//
// Created by alex on 10/7/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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

/////////////////////////////////////////////////////////////////////


/**
 * paste Solution here
 */
class Solution {
public:
    //abpwbkew
    bool not_repeat(string s, char c){
        std::string::size_type n;
        n = s.find(c);
        if(n==std::string::npos){
            return true;
        }else return false;
    }

    int lengthOfLongestSubstring(string s) {
        int max_len=1;
        int len=strlen(s.c_str());
        if(len==0){
            return 0;
        }
        int p_start=0, p_end=1;
        while(p_end<len){
            if(not_repeat(s.substr(p_start, max_len), s[p_start+max_len])){
                max_len+=1;
                p_end+=1;
            }else{
                do{
                    p_start+=1;
                    p_end+=1;
                    if(not_repeat(s.substr(p_start, max_len), s[p_start+max_len])) break;
                }while(p_end<len);
            }
        }
        return max_len;
    }
};

/**
 * write test function here
 * @return
 */
RC TestEngine::test(){
    Solution solution;
    string input = "pwwkew";
    cout << solution.lengthOfLongestSubstring(input)<<endl;
    return SUCCESS;
}

int main(int argc, char *argv[]){
    TestEngine &testEngine = TestEngine::instance();
    testEngine.test();
    return SUCCESS;
}
