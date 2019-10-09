//
// Created by alex on 10/8/19.
//

class Solution {
public:
    bool not_repeat(string s, char c){
        std::string::size_type n;
        n = s.find(c);
        if(n==std::string::npos){
            return true;
        }else return false;
    }
    bool self_not_repeat(string s){
        bool ret = true;
        int len = strlen(s.c_str());
        string tmp;
        for(;len>1;len--){
            tmp = s.substr(0, len-1);
            if(!not_repeat(tmp, s[len-1])){
                return false;
            }
        }
        return ret;
    }
    int lengthOfLongestSubstring(string s) {
        int max_len=1;
        if(strlen(s.c_str())==0){
            return 0;
        }
        int p_start=0, p_end=1;
        string ret;
        while(p_end<strlen(s.c_str())){
            ret = s.substr(p_start, max_len);
            if(not_repeat(ret, s[p_start+max_len])){
                max_len+=1;
                p_end+=1;
            }else{
                do{
                    p_start+=1;
                    p_end+=1;
                    ret = s.substr(p_start, max_len);
                    if(self_not_repeat(ret)&&not_repeat(ret, s[p_start+max_len])) break;
                }while(p_end<strlen(s.c_str()));
            }
        }
        return max_len;
    }
};