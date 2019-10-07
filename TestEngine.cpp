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


/**
 * paste Solution here
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> ret;
        bool found=false;
        for(i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ret.push_back(i);
                    ret.push_back(j);
                    found = true;
                }
            }
        }
        return ret;
    }
};

/**
 * write test function here
 * @return
 */
RC TestEngine::test(){
    Solution solution;
    vector<int> input_1 = {1,2,3};
    int input_2 = 3;
    vector<int> output(solution.twoSum(input_1, input_2));
    print_vector(output);
    return SUCCESS;
}

int main(int argc, char *argv[]){
    TestEngine &testEngine = TestEngine::instance();
    testEngine.test();
    return SUCCESS;
}
