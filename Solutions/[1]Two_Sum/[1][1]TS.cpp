//
// Created by alex on 10/7/19.
//

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