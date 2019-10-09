//
// Created by alex on 10/8/19.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256]={0}, ret=0, left=0;
        //use a hashmap to record the last position of i-th character, use ASCII code as key of the map
        for(int i=0;i<s.size();i++){
            if(map[s[i]]==0||map[s[i]]<left){
                //map[s[i]]==0 means the character has not been added to map
                //map[s[i]]==0 means the character is currently out of scope of "sliding window"
                ret = max(ret, i-left+1);
            }else{
                left = map[s[i]];
            }
            map[s[i]] = i+1;    //update the map with current character position
        }
        return ret;
    }
};