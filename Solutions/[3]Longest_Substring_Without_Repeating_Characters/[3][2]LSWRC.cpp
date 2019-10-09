//
// Created by alex on 10/8/19.
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charset;
        int len = strlen(s.c_str());
        int i=0, j=0;
        int max_len=0;
        while(i<len&&j<len){
            if(charset.find(s[j])!=charset.end()){
                charset.erase(s[i++]);
            } else{
                charset.insert(s[j++]);
                max_len = max(max_len, j-i);
            }
        }
        return max_len;
    }
};
