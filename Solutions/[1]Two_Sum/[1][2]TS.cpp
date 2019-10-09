//
// Created by alex on 10/7/19.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int *a = new int[j+1];
        for(int k=0;k<=j;k++){
            a[k] = nums[k];
        }
        sort(nums.begin(),nums.end());
        vector<int> ret;
        bool found=false;
        do{
            if(i>=j) break;
            if(nums[i]+nums[j]>target){
                j--;
            }else if(nums[i]+nums[j]<target){
                i++;
            }else{
                found = true;
                int m,n;
                for(int k=0;k<nums.size();k++){
                    if(a[k]==nums[i]){
                        m=k;
                        break;
                    }
                }
                for(int k=nums.size()-1;k>=0;k--){
                    if(a[k]==nums[j]){
                        n=k;
                        break;
                    }
                }
                ret.push_back(min(m,n));
                ret.push_back(max(m,n));
            }
        }while(!found);
        return ret;
    }
};